#pragma once

#include "BTCompositeNode.h"

using std::vector;

namespace BT
{
	class DLL BTSelectorNode final : public BTCompositeNode
	{
	public:
		REFLECT_NODE_NoParams(BTSelectorNode)

	public:
		ENodeResult Execute(void* userData) override;

	};
}

