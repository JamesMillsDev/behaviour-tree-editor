#pragma once

#include "BT/Nodes/BTNode.h"

#include <vector>

using std::vector;

namespace BT
{
	class BTSelectorNode final : public BTNode
	{
	public:
		BTSelectorNode();
		~BTSelectorNode() override;

	public:
		ENodeResult Execute(void* userData) override;
		void AddChild(BTNode* node) override;
		void RemoveChild(BTNode* node) override;
		void SetNodeIndex(BTNode* node, int newIndex);

	private:
		vector<BTNode*> m_children;
		BTNode* m_pendingChild;

	};
}

