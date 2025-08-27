#include "BT/Nodes/BTNode.h"

namespace BT
{
	bool BTNode::ExecutePending(void* userData, ENodeResult& result)
	{
		if (m_pendingChild != nullptr) 
		{
			switch (m_pendingChild->Execute(userData))
			{
			case ENodeResult::Failed:
				m_pendingChild = nullptr;
				result = ENodeResult::Failed;
				return false;

			case ENodeResult::Succeeded:
				m_pendingChild = nullptr;
				result = ENodeResult::Succeeded;
				break;

			case ENodeResult::Pending:
				result = ENodeResult::Succeeded;
				break;
			}

			return true;
		}

		return false;
	}
}
