#pragma once

#include "BTTaskNode.h"

#include <chrono>

typedef std::chrono::duration<float> duration;
typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_point;

namespace BT
{
	class DLL BTWaitTask : public BTTaskNode
	{
	public:
		BTWaitTask(float time);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		float m_time;
		bool m_isRunning;

		time_point m_nodeStart;

	};
}