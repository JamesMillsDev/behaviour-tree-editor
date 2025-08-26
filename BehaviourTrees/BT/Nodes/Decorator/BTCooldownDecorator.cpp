#include "BTCooldownDecorator.h"

using std::chrono::high_resolution_clock;

namespace BT
{
	BTCooldownDecorator::BTCooldownDecorator(float time)
		: m_time{ time }, m_isCoolingDown{ false }
	{
	}

	ENodeResult BTCooldownDecorator::Execute(void* userData)
	{
		if (ENodeResult pendingResult;
			ExecutePending(userData, pendingResult))
		{
			return pendingResult;
		}

		// If we aren't cooling down...
		if (!m_isCoolingDown)
		{
			// ... start cooling down, but run the child.
			m_isCoolingDown = true;
			m_nodeStart = high_resolution_clock::now();

			ENodeResult result = m_child->Execute(userData);
			if (result == ENodeResult::Pending)
			{
				m_pendingChild = m_child;
			}

			return result;
		}

		// Store the current time and calculate the duration between
		// when we started counting and now
		const time_point now = high_resolution_clock::now();
		const duration time = now - m_nodeStart;

		// If we have cooled down, switch the flag for next execution
		if (time.count() >= m_time)
		{
			m_isCoolingDown = false;
		}

		return ENodeResult::Failed;
	}
}
