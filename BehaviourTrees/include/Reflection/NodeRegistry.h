#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "BehaviourTrees.h"

using std::function;
using std::string;
using std::unordered_map;
using std::variant;
using std::vector;

using std::get;
using std::is_same_v;

namespace BT
{
	class BTNode;

	namespace Reflection
	{
		// Variant type for parameter values from JSON
		using ParamValue = variant<string, float, int, bool, ENodeResult>;

		// Parameter info structure
		struct ParamInfo
		{
		public:
			string name;
			string type;
			ParamValue defaultValue;

		};

		// Node factory function signature
		using NodeFactory = function<BTNode* (const vector<ParamValue>&)>;

		// Global registry
		class DLL NodeRegistry
		{
		public:
			static NodeRegistry& Instance();

		public:
			void RegisterNode(const string& typeName, NodeFactory factory, const vector<ParamInfo>& params);
			BTNode* CreateNode(const string& typeName, const vector<ParamValue>& params) const;
			const vector<ParamInfo>& GetParamInfo(const string& typeName) const;
			bool IsRegistered(const string& typeName) const;

		private:
			unordered_map<string, NodeFactory> m_factories;
			unordered_map<string, vector<ParamInfo>> m_paramInfos;

		};

		// Helper to convert ParamValue to specific type
		template<typename T>
		T GetParam(const ParamValue& value)
		{
			if constexpr (is_same_v<T, string>)
			{
				return get<string>(value);
			}
			else if constexpr (is_same_v<T, float>)
			{
				return get<float>(value);
			}
			else if constexpr (is_same_v<T, int>)
			{
				return get<int>(value);
			}
			else if constexpr (is_same_v<T, bool>)
			{
				return get<bool>(value);
			}
			else if constexpr (is_same_v<T, ENodeResult>)
			{
				const string& str = get<string>(value);
				if (str == "Success")
				{
					return ENodeResult::Succeeded;
				}

				if (str == "Failed")
				{
					return ENodeResult::Failed;
				}

				return ENodeResult::Pending;
			}

			return T();
		}
	}
}