#include "BTNotDecorator.h"

namespace BT
{
	ENodeResult BTNotDecorator::Execute(void* userData)
	{
		const ENodeResult result = BTDecoratorNode::Execute(userData);

		if (result == ENodeResult::Pending)
		{
			m_pendingChild = m_child;
			return ENodeResult::Pending;
		}

		return result == ENodeResult::Succeeded ? ENodeResult::Failed : ENodeResult::Succeeded;
	}
}
