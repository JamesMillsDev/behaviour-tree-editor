#pragma once
#include "BTCompositeNode.h"

namespace BT
{
	class DLL BTRandomSelector : public BTCompositeNode
	{
	public:
		ENodeResult Execute(void* userData) override;

	};
}
