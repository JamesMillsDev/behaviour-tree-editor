#pragma once
#include "BTCompositeNode.h"

namespace BT
{
	class BTRandomSelector : public BTCompositeNode
	{
	public:
		ENodeResult Execute(void* userData) override;

	};
}
