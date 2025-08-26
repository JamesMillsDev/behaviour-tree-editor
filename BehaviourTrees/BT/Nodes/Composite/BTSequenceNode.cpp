#include "BTSequenceNode.h"

namespace BT
{
	ENodeResult BTSequenceNode::Execute(void* userData)
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
				return ENodeResult::Failed;

			case ENodeResult::Succeeded:
				continue;

			case ENodeResult::Pending:
				m_pendingChild = child;
				return ENodeResult::Pending;
			}
		}

		return ENodeResult::Succeeded;
	}
}