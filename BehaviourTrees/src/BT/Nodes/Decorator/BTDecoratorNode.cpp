#include "BT/Nodes/Decorator/BTDecoratorNode.h"

namespace BT
{
	BTDecoratorNode::BTDecoratorNode()
		: m_child{ nullptr }
	{
	}

	BTDecoratorNode::~BTDecoratorNode()
	{
		delete m_child;
		m_child = nullptr;
	}

	ENodeResult BTDecoratorNode::Execute(void* userData)
	{
		if (ENodeResult pendingResult;
			ExecutePending(userData, pendingResult))
		{
			return pendingResult;
		}

		const ENodeResult result = m_child->Execute(userData);

		if (result == ENodeResult::Pending)
		{
			m_pendingChild = m_child;
		}

		return result;
	}

	void BTDecoratorNode::AddChild(BTNode* node)
	{
		m_child = node;
	}

	void BTDecoratorNode::RemoveChild(BTNode* node)
	{
		if (m_child == node)
		{
			return;
		}

		m_child = nullptr;
	}
}
