#include "Editor/Graph/Grid.h"

#include <raymath.h>
#include <rlgl.h>

#include "Editor/Utilities.h"

namespace BehaviourTree::Editor::Graph
{
	Grid::Grid(const float dpi, const float cellSize, const float zoomSpeed, const Vector2 zoomConstraints)
		: m_dpi{ dpi }, m_cellSize{ cellSize }, m_zoomSpeed{ zoomSpeed }, m_zoomConstraints{ zoomConstraints },
		m_zoom{ zoomConstraints.x }, m_offset{ 0, 0 }, m_centerScreen{ 0, 0 }
	{
	}

	void Grid::SetScreenCenter(Vector2 center)
	{
		m_centerScreen = center;
	}

	void Grid::Render(Rectangle vp)
	{
		static Color minorColor = FromHex(0x2d2d2dff);
		static Color majorColor = FromHex(0x3a3a3aff);

		rlPushMatrix();
		rlLoadIdentity();

		rlScalef(m_dpi, m_dpi, 1.f);

		int i = 0;
		for (float x = m_offset.x; x < vp.width; x += m_cellSize * m_zoom)  // NOLINT(cert-flp30-c)
		{
			const Color col = i++ % 5 == 0 ? majorColor : minorColor;

			DrawLineV({ x, 0 }, { x, vp.height }, col);
		}

		i = 0;
		for (float x = m_offset.x; x > 0; x -= m_cellSize * m_zoom)  // NOLINT(cert-flp30-c)
		{
			const Color col = i++ % 5 == 0 ? majorColor : minorColor;

			DrawLineV({ x, 0 }, { x, vp.height }, col);
		}

		i = 0;
		for (float y = m_offset.y; y < vp.height; y += m_cellSize * m_zoom)  // NOLINT(cert-flp30-c)
		{
			const Color col = i++ % 5 == 0 ? majorColor : minorColor;

			DrawLineV({ 0, y }, { vp.width, y }, col);
		}

		i = 0;
		for (float y = m_offset.y; y > 0; y -= m_cellSize * m_zoom)  // NOLINT(cert-flp30-c)
		{
			const Color col = i++ % 5 == 0 ? majorColor : minorColor;

			DrawLineV({ 0, y }, { vp.width, y }, col);
		}

		rlPopMatrix();
	}

	void Grid::Tick()
	{
		m_zoom += GetMouseWheelMove() * m_zoomSpeed;
		m_zoom = Clamp(m_zoom, m_zoomConstraints.x, m_zoomConstraints.y);

		if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
		{
			m_offset += GetMouseDelta() * m_zoomSpeed;
		}
	}
}
