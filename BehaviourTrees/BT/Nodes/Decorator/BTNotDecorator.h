#pragma once

#include "BTDecoratorNode.h"

namespace BT
{
	class BTNotDecorator : public BTDecoratorNode
	{
	public:
		ENodeResult Execute(void* userData) override;

	};
}