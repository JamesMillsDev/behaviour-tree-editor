#pragma once

#include "BTDecoratorNode.h"

namespace BT
{
	class DLL BTRetryDecorator : public BTDecoratorNode
	{
	public:
		REFLECT_NODE_OneParam(BTRetryDecorator, int, "retryCount")

	public:
		BTRetryDecorator(int retryCount);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		int m_retryCount;
		int m_currentIteration;

	};
}
