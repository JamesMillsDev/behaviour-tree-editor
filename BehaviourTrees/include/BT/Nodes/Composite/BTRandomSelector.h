#pragma once
#include "BTCompositeNode.h"

namespace BT
{
	class DLL BTRandomSelector : public BTCompositeNode
	{
	public:
		REFLECT_NODE_NoParams(BTRandomSelector)

	public:
		ENodeResult Execute(void* userData) override;

	};
}
