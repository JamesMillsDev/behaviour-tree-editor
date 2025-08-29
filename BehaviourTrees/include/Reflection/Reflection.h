// ReSharper disable CppClangTidyBugproneMacroParentheses
#pragma once

#include "NodeRegistry.h"

#define REFLECT_NODE_NoParams(TYPE) \
	static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>&) { \
        return new TYPE(); \
    } \
    static bool RegisterType() { \
        BT::Reflection::NodeRegistry::Instance().RegisterNode( \
            #TYPE, \
            [](const vector<BT::Reflection::ParamValue>& params) -> BT::BTNode* { \
                return new TYPE(); \
            }, \
            {} \
        ); \
        return true; \
    } \
    inline static bool registered = TYPE::RegisterType();

// Macro for nodes with 1 parameter
#define REFLECT_NODE_OneParam(TYPE, T1, NAME1) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0])); \
    } \
    static bool RegisterType() { \
        BT::Reflection::NodeRegistry::Instance().RegisterNode( \
            #TYPE, \
            [](const vector<BT::Reflection::ParamValue>& params) -> BT::BTNode* { \
                return new TYPE(BT::Reflection::GetParam<T1>(params[0])); \
            }, \
            {{NAME1, #T1, T1{}}} \
        ); \
        return true; \
    } \
    inline static bool registered = TYPE::RegisterType();

// Macro for nodes with 2 parameters
#define REFLECT_NODE_TwoParams(TYPE, T1, NAME1, T2, NAME2) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1])); \
    } \
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
    } \
    inline static bool registered = TYPE::RegisterType();

// Macro for nodes with 3 parameters
#define REFLECT_NODE_ThreeParams(TYPE, T1, NAME1, T2, NAME2, T3, NAME3) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1]),\
                       BT::Reflection::GetParam<T3>(params[2])); \
    } \
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
    } \
    inline static bool registered = TYPE::RegisterType();

// Macro for nodes with 4 parameters
#define REFLECT_NODE_FourParams(TYPE, T1, NAME1, T2, NAME2, T3, NAME3, T4, NAME4) \
    static BTNode* CreateInstance(const vector<BT::Reflection::ParamValue>& params) { \
        return new TYPE(BT::Reflection::GetParam<T1>(params[0]), \
                       BT::Reflection::GetParam<T2>(params[1]),\
                       BT::Reflection::GetParam<T3>(params[2]),\
                       BT::Reflection::GetParam<T4>(params[3])); \
    } \
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
    } \
    inline static bool registered = TYPE::RegisterType();