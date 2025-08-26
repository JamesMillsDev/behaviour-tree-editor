#pragma once

#include "BTCompositeNode.h"

using std::vector;

namespace BT
{
	class BTSelectorNode final : public BTCompositeNode
	{
	public:
		ENodeResult Execute(void* userData) override;

	};
}

