#include "BT/Nodes/Composite/BTSelectorNode.h"

namespace BT
{
	ENodeResult BTSelectorNode::Execute(void* userData)
	{
		if (ENodeResult pendingResult;
			ExecutePending(userData, pendingResult))
		{
			return pendingResult;
		}

		for (BTNode* child : m_children)
		{
			switch (child->Execute(userData))
			{
			case ENodeResult::Failed:
				continue;

			case ENodeResult::Succeeded:
				return ENodeResult::Succeeded;

			case ENodeResult::Pending:
				m_pendingChild = child;
				return ENodeResult::Pending;
			}
		}

		return ENodeResult::Failed;
	}
}
