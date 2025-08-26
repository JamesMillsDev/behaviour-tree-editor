#include "BTWaitTask.h"

using std::chrono::high_resolution_clock;

namespace BT
{
	BTWaitTask::BTWaitTask(float time)
		: m_time{ time }, m_isRunning{ false }
	{
	}

	ENodeResult BTWaitTask::Execute(void* userData)
	{
		// If we haven't run the clock before, store the current time
		if (!m_isRunning)
		{
			m_isRunning = true;
			m_nodeStart = high_resolution_clock::now();
		}

		// Store the current time and calculate the duration between
		// when we started counting and now
		const time_point now = high_resolution_clock::now();
		const duration time = now - m_nodeStart;

		// If we haven't reached the maximum; return pending.
		if (time.count() < m_time)
		{
			return ENodeResult::Pending;
		}

		// We have expired the timer, so reset and return success
		m_isRunning = false;
		return ENodeResult::Succeeded;
	}
}
