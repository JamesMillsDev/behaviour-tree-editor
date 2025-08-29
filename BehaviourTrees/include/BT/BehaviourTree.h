#pragma once

#include <nlohmann/json.hpp>

#include "Nodes/BTNode.h"

using json = nlohmann::json;

namespace BT
{
	class DLL BehaviourTree
	{
	public:
		template<typename T>
		static T* CastUserData(void* userData);

		static BehaviourTree* LoadTree(const string& jsonFile);

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

		class BTParser
		{
			friend BehaviourTree;

		private:
			static BehaviourTree* Parse(const string& jsonFile);
			static bool LoadJson(const string& jsonFile, json& json);

			static BTNode* BuildTree(const json& json);
			static BTNode* BuildNode(const json& nodeJson);

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