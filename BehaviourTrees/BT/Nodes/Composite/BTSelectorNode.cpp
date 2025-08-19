#include "BTSelectorNode.h"

namespace BT
{
	ENodeResult BTSelectorNode::Execute(void* userData)
	{
		if (m_pendingChild != nullptr)
		{
			switch (m_pendingChild->Execute(userData))
			{
			case ENodeResult::Failed:
				m_pendingChild = nullptr;
				break;

			case ENodeResult::Succeeded:
				m_pendingChild = nullptr;
				return ENodeResult::Succeeded;

			case ENodeResult::Pending:
				return ENodeResult::Pending;
			}
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
