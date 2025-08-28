#pragma once

#include "BT/Nodes/BTNode.h"

namespace BT
{
	class DLL BTDecoratorNode : public BTNode
	{
	public:
		BTDecoratorNode();
		~BTDecoratorNode() override;

	public:
		ENodeResult Execute(void* userData) override;
		void AddChild(BTNode* node) override;
		void RemoveChild(BTNode* node) override;

	protected:
		BTNode* m_child;

	};
}