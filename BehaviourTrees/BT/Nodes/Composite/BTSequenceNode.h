#pragma once

#include "BT/Nodes/BTNode.h"

#include <vector>

using std::vector;

namespace BT
{
	class BTSequenceNode final : public BTNode
	{
	public:
		BTSequenceNode();
		~BTSequenceNode() override;

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
