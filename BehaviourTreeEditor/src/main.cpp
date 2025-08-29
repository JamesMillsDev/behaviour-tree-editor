#include "Application.h"

#include "BT/BehaviourTree.h"

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

int main()
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	BT::BehaviourTree* bt = BT::BehaviourTree::LoadTree(R"(C:\Users\james.mills\Documents\git\BehaviourTreeEditor\sample_tree.json)");

	delete bt;

	return EXIT_SUCCESS;
	//return BehaviourTree::Editor::Application::Launch();
}