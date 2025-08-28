#pragma once

#include "BehaviourTrees.h"

namespace BT
{
	enum class ENodeResult : unsigned char
	{
		Failed,
		Succeeded,
		Pending
	};

	class DLL BTNode
	{
		friend class BehaviourTree;

	public:
		BTNode() = default;
		virtual ~BTNode() = default;

	public:
		bool ExecutePending(void* userData, ENodeResult& result);

		virtual ENodeResult Execute(void* userData) = 0;
		virtual void AddChild(BTNode* node) = 0;
		virtual void RemoveChild(BTNode* node) = 0;

	protected:
		BTNode* m_pendingChild;

	};
}

