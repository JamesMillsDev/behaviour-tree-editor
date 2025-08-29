#include "BT/BehaviourTree.h"

#include <fstream>

#include "BT/Nodes/Composite/BTCompositeNode.h"
#include "BT/Nodes/Decorator/BTDecoratorNode.h"

using std::fstream;

using BT::Reflection::NodeRegistry;

namespace BT
{
	BehaviourTree* BehaviourTree::LoadTree(const string& jsonFile)
	{
		return BTParser::Parse(jsonFile);
	}

	BehaviourTree::BehaviourTree()
		: m_root{ new BTRoot }
	{

	}

	BehaviourTree::~BehaviourTree()
	{
		delete m_root;
		m_root = nullptr;
	}

	ENodeResult BehaviourTree::Run(void* userData) const
	{
		return m_root->Execute(userData);
	}

	BTNode* BehaviourTree::GetRootNode() const
	{
		return m_root;
	}

	BehaviourTree::BTRoot::BTRoot()
		: m_child{ nullptr }
	{
		
	}

	BehaviourTree::BTRoot::~BTRoot()
	{
		delete m_child;
		m_child = nullptr;
	}

	ENodeResult BehaviourTree::BTRoot::Execute(void* userData)
	{
		return m_child->Execute(userData);
	}

	void BehaviourTree::BTRoot::AddChild(BTNode* node)
	{
		m_child = node;
	}

	void BehaviourTree::BTRoot::RemoveChild(BTNode* node)
	{
		if (m_child == node)
		{
			return;
		}

		m_child = nullptr;
	}

	BehaviourTree* BehaviourTree::BTParser::Parse(const string& jsonFile)
	{
		json json;
		if (LoadJson(jsonFile, json))
		{
			BehaviourTree* bt = new BehaviourTree;

			bt->GetRootNode()->AddChild(BuildTree(json));

			return bt;
		}

		return nullptr;
	}

	bool BehaviourTree::BTParser::LoadJson(const string& jsonFile, json& json)
	{
		bool didOpen = false;

		fstream file;
		file.open(jsonFile, std::ios::in);

		if (file.is_open())
		{
			didOpen = true;
			file >> json;
		}

		file.close();

		return didOpen;
	}

	BTNode* BehaviourTree::BTParser::BuildTree(const json& json)
	{
		BTNode* node = BuildNode(json);
		if (json.contains("children"))
		{
			if (BTCompositeNode* composite = dynamic_cast<BTCompositeNode*>(node))
			{
				for (const auto& child : json["children"])
				{
					composite->AddChild(BuildTree(child));
				}
			}

			if (BTDecoratorNode* decorator = dynamic_cast<BTDecoratorNode*>(node))
			{
				if (!json["children"].empty())
				{
					decorator->AddChild(BuildTree(json["children"][0]));
				}
			}
		}

		return node;
	}

	BTNode* BehaviourTree::BTParser::BuildNode(const json& nodeJson)
	{
		return NodeRegistry::Instance().CreateNode(nodeJson["id"], {});
	}
}
