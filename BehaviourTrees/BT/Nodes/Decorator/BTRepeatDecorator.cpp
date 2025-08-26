#include "BTRepeatDecorator.h"

namespace BT
{
	BTRepeatDecorator::BTRepeatDecorator(int repeatCount)
		: m_repeatCount{ repeatCount }, m_currentIteration{ 0 }
	{
	}

	ENodeResult BTRepeatDecorator::Execute(void* userData)
	{
		if (ENodeResult pendingResult;
			ExecutePending(userData, pendingResult))
		{
			return pendingResult;
		}

		ENodeResult result = ENodeResult::Failed;

		for (; m_currentIteration < m_repeatCount; ++m_currentIteration)
		{
			result = m_child->Execute(userData);

			if (result == ENodeResult::Pending)
			{
				m_pendingChild = m_child;
				return ENodeResult::Pending;
			}
		}

		m_currentIteration = 0;
		return result;
	}
}
