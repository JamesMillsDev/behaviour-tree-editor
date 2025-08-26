#include "BTLogTask.h"

#include <iostream>

namespace BT
{
	BTLogTask::BTLogTask(string message)
		: m_message{ std::move(message) }
	{
	}

	ENodeResult BTLogTask::Execute(void* userData)
	{
		std::cout << m_message << "\n";

		return ENodeResult::Succeeded;
	}
}
