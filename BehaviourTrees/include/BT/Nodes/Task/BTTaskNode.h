#pragma once

#include "BT/Nodes/BTNode.h"

namespace BT
{
	class DLL BTTaskNode : public BTNode
	{
	public:
		void AddChild(BTNode* node) override;
		void RemoveChild(BTNode* node) override;

	};
}