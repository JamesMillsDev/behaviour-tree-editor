#pragma once

#include "BTTaskNode.h"

#include <string>

using std::string;

namespace BT
{
	class BTLogTask : public BTTaskNode
	{
	public:
		BTLogTask(string message);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		string m_message;

	};
}
