#pragma once

#include <raylib.h>

namespace BehaviourTree::Editor::Graph
{
	class Grid
	{
	public:
		Grid(float dpi, float cellSize, float zoomSpeed = .1f, Vector2 zoomConstraints = { 1, 2 });

	public:
		void SetScreenCenter(Vector2 center);
		void Render(Rectangle vp) const;
		void Tick(Rectangle vp);

	private:
		float m_dpi;
		float m_cellSize;
		float m_zoomSpeed;

		Vector2 m_zoomConstraints;

		float m_zoom;
		Vector2 m_offset;
		Vector2 m_centerScreen;

	};
}