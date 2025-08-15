#include "BTSelectorNode.h"

#include <utility>

namespace BT
{
	BTSelectorNode::BTSelectorNode()
		: m_pendingChild{ nullptr }
	{
	}

	BTSelectorNode::~BTSelectorNode()
	{
		for (const BTNode* child : m_children)
		{
			delete child;
		}

		m_children.clear();
	}

	ENodeResult BTSelectorNode::Execute(void* userData)
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
				continue;
			}
			case ENodeResult::Succeeded:
			{
				return ENodeResult::Succeeded;
			}
			case ENodeResult::Pending:
			{
				m_pendingChild = child;
				return ENodeResult::Pending;
			}
			}
		}

		return ENodeResult::Failed;
	}

	void BTSelectorNode::AddChild(BTNode* node)
	{
		if (const auto iter = std::ranges::find(m_children, node);
			iter == m_children.end())
		{
			m_children.emplace_back(node);
		}
	}

	void BTSelectorNode::RemoveChild(BTNode* node)
	{
		if (const auto iter = std::ranges::find(m_children, node); 
			iter != m_children.end())
		{
			m_children.erase(iter);
		}
	}

	void BTSelectorNode::SetNodeIndex(BTNode* node, const int newIndex)
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
