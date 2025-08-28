#pragma once

#include "BTCompositeNode.h"

namespace BT
{
	class DLL BTSequenceNode final : public BTCompositeNode
	{
	public:
		ENodeResult Execute(void* userData) override;

	};
}
