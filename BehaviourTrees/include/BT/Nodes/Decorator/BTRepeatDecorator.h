#pragma once

#include "BTDecoratorNode.h"

namespace BT
{
	class DLL BTRepeatDecorator : public BTDecoratorNode
	{
	public:
		REFLECT_NODE_OneParam(BTRepeatDecorator, int, "repeatCount")

	public:
		BTRepeatDecorator(int repeatCount);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		int m_repeatCount;
		int m_currentIteration;

	};
}
