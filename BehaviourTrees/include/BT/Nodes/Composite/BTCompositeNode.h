#pragma once

#include "BehaviourTrees.h"
#include "BT/Nodes/BTNode.h"

#include <vector>

using std::vector;

namespace BT
{
	class DLL BTCompositeNode : public BTNode
	{
	public:
		BTCompositeNode();
		~BTCompositeNode() override;

	public:
		void AddChild(BTNode* node) override;
		void RemoveChild(BTNode* node) override;
		void SetNodeIndex(BTNode* node, int newIndex);

	protected:
		vector<BTNode*> m_children;

	};
}
