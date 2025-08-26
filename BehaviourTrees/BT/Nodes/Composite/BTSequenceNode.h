#pragma once

#include "BTCompositeNode.h"

namespace BT
{
	class BTSequenceNode final : public BTCompositeNode
	{
	public:
		ENodeResult Execute(void* userData) override;

	};
}
