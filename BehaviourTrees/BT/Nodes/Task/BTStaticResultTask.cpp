#include "BTStaticResultTask.h"

namespace BT
{
	BTStaticResultTask::BTStaticResultTask(ENodeResult staticResult)
		: m_staticResult{ staticResult }
	{
	}

	ENodeResult BTStaticResultTask::Execute(void* userData)
	{
		return m_staticResult;
	}
}
