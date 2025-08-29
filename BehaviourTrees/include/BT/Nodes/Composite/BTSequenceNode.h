#pragma once

#include "BTCompositeNode.h"

namespace BT
{
	class DLL BTSequenceNode final : public BTCompositeNode
	{
	public:
		REFLECT_NODE_NoParams(BTSequenceNode)

	public:
		ENodeResult Execute(void* userData) override;

	};
}
