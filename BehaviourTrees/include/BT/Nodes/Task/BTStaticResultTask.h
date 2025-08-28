#pragma once

#include "BTTaskNode.h"

namespace BT
{
	class DLL BTStaticResultTask : public BTTaskNode
	{
	public:
		BTStaticResultTask(ENodeResult staticResult);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		ENodeResult m_staticResult;

	};
}