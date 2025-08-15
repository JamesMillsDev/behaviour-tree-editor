#include "BTSequenceNode.h"

namespace BT
{
	BTSequenceNode::BTSequenceNode()
		: m_pendingChild{ nullptr }
	{
	}

	BTSequenceNode::~BTSequenceNode()
	{
		for (const BTNode* child : m_children)
		{
			delete child;
		}

		m_children.clear();
	}

	ENodeResult BTSequenceNode::Execute(void* userData)
	{
		if (m_pendingChild != nullptr)
		{
			switch (m_pendingChild->Execute(userData))
			{
			case ENodeResult::Failed:
			{
				m_pendingChild = nullptr;
				break;
			}
			case ENodeResult::Succeeded:
			{
				m_pendingChild = nullptr;
				return ENodeResult::Succeeded;
			}
			case ENodeResult::Pending:
			{
				return ENodeResult::Pending;
			}
			}
		}

		for (BTNode* child : m_children)
		{
			switch (child->Execute(userData))
			{
			case ENodeResult::Failed:
			{
				return ENodeResult::Failed;
			}
			case ENodeResult::Succeeded:
			{
				continue;
			}
			case ENodeResult::Pending:
			{
				m_pendingChild = child;
				return ENodeResult::Pending;
			}
			}
		}

		return ENodeResult::Succeeded;
	}

	void BTSequenceNode::AddChild(BTNode* node)
	{
		if (const auto iter = std::ranges::find(m_children, node);
			iter == m_children.end())
		{
			m_children.emplace_back(node);
		}
	}

	void BTSequenceNode::RemoveChild(BTNode* node)
	{
		if (const auto iter = std::ranges::find(m_children, node);
			iter != m_children.end())
		{
			m_children.erase(iter);
		}
	}

	void BTSequenceNode::SetNodeIndex(BTNode* node, const int newIndex)
	{
		const auto iter = std::ranges::find(m_children, node);
		if (iter == m_children.end())
		{
			AddChild(node);
		}

		m_children.erase(iter);

		if (std::cmp_greater_equal(newIndex, m_children.size()))
		{
			AddChild(node);
			return;
		}

		m_children.emplace(m_children.begin() + newIndex, node);
	}
}