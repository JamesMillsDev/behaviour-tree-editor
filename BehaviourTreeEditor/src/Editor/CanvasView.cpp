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
	}

	void CanvasView::Initialise()
	{
		Application::Instance()->ListenScreenResize([this](float w, float h)
			{
				m_grid->SetScreenCenter({ w * .5f, h * .5f });
			});
	}

	void CanvasView::OnRender(Rectangle rect)
	{
		m_grid->Render(rect);
		/*static Color minorColor = FromHex(0x2d2d2dff);
		static Color majorColor = FromHex(0x3a3a3aff);

		const float gridSpacing = m_baseGridSpacing * (1.f / m_zoomLevel);

		const int xCount = static_cast<int>(rect.width / gridSpacing);
		const int yCount = static_cast<int>(rect.height / gridSpacing);

		for (int i = 0; i < xCount * yCount; ++i)
		{
			const Color col = i % 5 == 0 ? majorColor : minorColor;

			DrawLineV(
				Vector2{ static_cast<float>(i) * gridSpacing, 0 } + m_offset,
				Vector2{ static_cast<float>(i) * gridSpacing, rect.height } + m_offset,
				col
			);

			DrawLineV(
				Vector2{ 0, static_cast<float>(i) * gridSpacing } + m_offset,
				Vector2{ rect.width, static_cast<float>(i) * gridSpacing } + m_offset,
				col
			);
		}*/

		/*for (const auto& node : m_nodes)
		{
			node->Render();
		}*/
	}

	void CanvasView::OnTick(float dt)
	{
		m_grid->Tick();

		/*for (const auto& node : m_nodes)
		{
			node->Tick(dt);
		}*/
	}
}
