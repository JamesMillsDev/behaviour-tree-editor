#pragma once

#include "BTDecoratorNode.h"

namespace BT
{
	class BTRetryDecorator : public BTDecoratorNode
	{
	public:
		BTRetryDecorator(int retryCount);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		int m_retryCount;
		int m_currentIteration;

	};
}
