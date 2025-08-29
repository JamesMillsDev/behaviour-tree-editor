#pragma once

#include "BTDecoratorNode.h"

namespace BT
{
	class DLL BTNotDecorator : public BTDecoratorNode
	{
	public:
		REFLECT_NODE_NoParams(BTNotDecorator)

	public:
		ENodeResult Execute(void* userData) override;

	};
}