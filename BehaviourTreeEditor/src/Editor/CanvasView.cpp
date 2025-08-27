#include "Editor/CanvasView.h"

#include "Application.h"

#include "Editor/Utilities.h"
#include "Editor/Graph/Node.h"

#include "Editor/Graph/Grid.h"

namespace BehaviourTree::Editor
{
	CanvasView::CanvasView()
		: EditorView{ "Canvas" }, m_grid{ new Grid{ 4.f, 10.f } }
	{
	}

	CanvasView::~CanvasView()
	{
		for (const auto& node : m_nodes)
		{
			delete node;
		}

		m_nodes.clear();

		delete m_grid;
	}

	void CanvasView::Initialise()
	{
		Application::Instance()->ListenScreenResize([this](float w, float h)
			{
				m_grid->SetScreenCenter({ w * .5f, h * .5f });
			});
	}

	void CanvasView::OnRender()
	{
		m_grid->Render(m_rectangle);

		/*for (const auto& node : m_nodes)
		{
			node->Render();
		}*/
	}

	void CanvasView::OnTick(float dt)
	{
		m_grid->Tick(m_rectangle);

		/*for (const auto& node : m_nodes)
		{
			node->Tick(dt);
		}*/
	}
}
