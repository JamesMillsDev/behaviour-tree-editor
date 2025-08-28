#pragma once

#include "BTDecoratorNode.h"

namespace BT
{
	class DLL BTNotDecorator : public BTDecoratorNode
	{
	public:
		ENodeResult Execute(void* userData) override;

	};
}