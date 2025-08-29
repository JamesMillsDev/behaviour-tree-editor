#include "Reflection/ReflectedNode.h"

#include <utility>

namespace BT::Reflection
{
	NodeRegistry& NodeRegistry::Instance()
	{
		static NodeRegistry instance;
		return instance;
	}

	void NodeRegistry::RegisterNode(const string& typeName, NodeFactory factory, const vector<ParamInfo>& params)
	{
		m_factories[typeName] = std::move(factory);
		m_paramInfos[typeName] = params;
	}

	BTNode* NodeRegistry::CreateNode(const string& typeName, const vector<ParamValue>& params) const
	{
		if (const auto it = m_factories.find(typeName); 
			it != m_factories.end()) 
		{
			return it->second(params);
		}

		return nullptr;
	}

	const vector<ParamInfo>& NodeRegistry::GetParamInfo(const string& typeName) const
	{
		static vector<ParamInfo> empty;
		const auto it = m_paramInfos.find(typeName);

		return it != m_paramInfos.end() ? it->second : empty;
	}

	bool NodeRegistry::IsRegistered(const string& typeName) const
	{
		return m_factories.contains(typeName);
	}
}
