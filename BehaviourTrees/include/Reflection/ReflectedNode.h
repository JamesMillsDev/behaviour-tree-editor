// ReSharper disable CppClangTidyBugproneMacroParentheses
#pragma once

#include <any>
#include <functional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "BehaviourTrees.h"

using std::any;
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

#define REFLECT_NODE_NoParams(TYPE) \
	static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>&) { \
        return new TYPE(); \
    } \
    inline static bool registered; \
    static bool RegisterType() { \
        BT::Reflection::NodeRegistry::Instance().RegisterNode( \
            #TYPE, \
            [](const vector<BT::Reflection::ParamValue>& params) -> BT::BTNode* { \
                return new TYPE(); \
            }, \
            {} \
        ); \
        return true; \
    }

// Macro for nodes with 1 parameter
#define REFLECT_NODE_OneParam(TYPE, T1, NAME1) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0])); \
    } \
    inline static bool registered; \
    static bool RegisterType() { \
        BT::Reflection::NodeRegistry::Instance().RegisterNode( \
            #TYPE, \
            [](const vector<BT::Reflection::ParamValue>& params) -> BT::BTNode* { \
                return new TYPE(BT::Reflection::GetParam<T1>(params[0])); \
            }, \
            {{NAME1, #T1, T1{}}} \
        ); \
        return true; \
    }

// Macro for nodes with 2 parameters
#define REFLECT_NODE_TwoParams(TYPE, T1, NAME1, T2, NAME2) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1])); \
    } \
    inline static bool registered; \
    static bool RegisterType() { \
        BT::Reflection::NodeRegistry::Instance().RegisterNode( \
            #TYPE, \
            [](const vector<BT::Reflection::ParamValue>& params) -> BT::BTNode* { \
                return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                               BT::Reflection::GetParam<T2>(params[1])); \
            }, \
            {{NAME1, #T1, T1{}}, {NAME2, #T2, T2{}}} \
        ); \
        return true; \
    }

// Macro for nodes with 3 parameters
#define REFLECT_NODE_ThreeParams(TYPE, T1, NAME1, T2, NAME2, T3, NAME3) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1]),\
                       BT::Reflection::GetParam<T3>(params[2])); \
    } \
    inline static bool registered; \
    static bool RegisterType() { \
        BT::Reflection::NodeRegistry::Instance().RegisterNode( \
            #TYPE, \
            [](const vector<BT::Reflection::ParamValue>& params) -> BT::BTNode* { \
                return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1]),\
                       BT::Reflection::GetParam<T3>(params[2])); \
            }, \
            {{NAME1, #T1, T1{}}, {NAME2, #T2, T2{}}, {NAME3, #T3, T3{}}} \
        ); \
        return true; \
    }

// Macro for nodes with 4 parameters
#define REFLECT_NODE_FourParams(TYPE, T1, NAME1, T2, NAME2, T3, NAME3, T4, NAME4) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1]),\
                       BT::Reflection::GetParam<T3>(params[2]),\
                       BT::Reflection::GetParam<T4>(params[3])); \
    } \
    inline static bool registered; \
    static bool RegisterType() { \
        BT::Reflection::NodeRegistry::Instance().RegisterNode( \
            #TYPE, \
            [](const vector<BT::Reflection::ParamValue>& params) -> BT::BTNode* { \
                return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1]),\
                       BT::Reflection::GetParam<T3>(params[2]),\
                       BT::Reflection::GetParam<T4>(params[3])); \
            }, \
            {{NAME1, #T1, T1{}}, {NAME2, #T2, T2{}}, {NAME3, #T3, T3{}}, {NAME4, #T4, T4{}}} \
        ); \
        return true; \
    }