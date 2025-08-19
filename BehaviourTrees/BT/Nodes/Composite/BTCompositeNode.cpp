#include "BTCompositeNode.h"

namespace BT
{
	BTCompositeNode::BTCompositeNode() = default;

	BTCompositeNode::~BTCompositeNode()
	{
		for (const BTNode* child : m_children)
		{
			delete child;
		}

		m_children.clear();
	}

	void BTCompositeNode::AddChild(BTNode* node)
	{
		if (const auto iter = std::ranges::find(m_children, node);
			iter == m_children.end())
		{
			m_children.emplace_back(node);
		}
	}

	void BTCompositeNode::RemoveChild(BTNode* node)
	{
		if (const auto iter = std::ranges::find(m_children, node);
			iter != m_children.end())
		{
			m_children.erase(iter);
		}
	}

	void BTCompositeNode::SetNodeIndex(BTNode* node, int newIndex)
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
