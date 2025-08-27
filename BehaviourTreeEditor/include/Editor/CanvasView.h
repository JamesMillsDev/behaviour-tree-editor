#pragma once

#include "EditorView.h"

#include <vector>

using std::vector;

namespace BehaviourTree::Editor
{
	namespace Graph
	{
		class Node;
		class Grid;
	}

	using namespace Graph;

	class CanvasView final : public EditorView
	{
	public:
		CanvasView();
		~CanvasView() override;

	protected:
		// Inherited via EditorView
		void Initialise() override;

		void OnRender() override;
		void OnTick(float dt) override;

	private:
		vector<Node*> m_nodes;
		Grid* m_grid;

	};
}