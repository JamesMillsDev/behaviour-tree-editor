#pragma once

#include "BTTaskNode.h"

#include <string>

using std::string;

namespace BT
{
	class DLL BTLogTask : public BTTaskNode
	{
	public:
		//REFLECT_NODE()

	public:
		BTLogTask(string message);

	public:
		ENodeResult Execute(void* userData) override;

	private:
		string m_message;

	};
}
