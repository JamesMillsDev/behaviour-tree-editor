#pragma once
#include "BTTaskNode.h"

namespace BT
{
	class BTWaitNode : public BTTaskNode
	{
	public:
		BTWaitNode(float time);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		float m_time;

	};
}