#pragma once

#include "BTDecoratorNode.h"

#include <chrono>

typedef std::chrono::duration<float> duration;
typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_point;

namespace BT
{
	class DLL BTCooldownDecorator : public BTDecoratorNode
	{
	public:
		REFLECT_NODE_OneParam(BTCooldownDecorator, float, "time")

	public:
		BTCooldownDecorator(float time);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		float m_time;
		bool m_isCoolingDown;

		time_point m_nodeStart;

	};
}
