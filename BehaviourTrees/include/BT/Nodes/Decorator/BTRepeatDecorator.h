#pragma once

#include "BTDecoratorNode.h"

namespace BT
{
	class BTRepeatDecorator : public BTDecoratorNode
	{
	public:
		BTRepeatDecorator(int repeatCount);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		int m_repeatCount;
		int m_currentIteration;

	};
}
