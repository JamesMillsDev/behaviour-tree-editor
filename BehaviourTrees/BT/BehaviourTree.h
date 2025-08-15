#pragma once

#include "Nodes/BTNode.h"

namespace BT
{
	class BehaviourTree
	{
	public:
		template<typename T>
		static T* CastUserData(void* userData);

	public:
		BehaviourTree();
		~BehaviourTree();

	public:
		ENodeResult Run(void* userData) const;

		BTNode* GetRootNode() const;

	private:
		class BTRoot : public BTNode
		{
		public:
			BTRoot();
			~BTRoot() override;

		public:
			ENodeResult Execute(void* userData) override;
			void AddChild(BTNode* node) override;
			void RemoveChild(BTNode* node) override;

		private:
			BTNode* m_child;

		};

	private:
		BTRoot* m_root;

	};

	template <typename T>
	T* BehaviourTree::CastUserData(void* userData)
	{
		return dynamic_cast<T*>(userData);
	}
}