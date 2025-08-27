#include "BT/BehaviourTree.h"

namespace BT
{
	BehaviourTree::BehaviourTree()
		: m_root{ new BTRoot }
	{

	}

	BehaviourTree::~BehaviourTree()
	{
		delete m_root;
		m_root = nullptr;
	}

	ENodeResult BehaviourTree::Run(void* userData) const
	{
		return m_root->Execute(userData);
	}

	BTNode* BehaviourTree::GetRootNode() const
	{
		return m_root;
	}

	BehaviourTree::BTRoot::BTRoot() = default;

	BehaviourTree::BTRoot::~BTRoot()
	{
		delete m_child;
		m_child = nullptr;
	}

	ENodeResult BehaviourTree::BTRoot::Execute(void* userData)
	{
		return m_child->Execute(userData);
	}

	void BehaviourTree::BTRoot::AddChild(BTNode* node)
	{
		m_child = node;
	}

	void BehaviourTree::BTRoot::RemoveChild(BTNode* node)
	{
		if (m_child == node)
		{
			return;
		}

		m_child = nullptr;
	}
}
