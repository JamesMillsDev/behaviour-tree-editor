#include "Editor/EditorView.h"

#include "Application.h"

namespace BehaviourTree::Editor
{
	EditorView::EditorView(const char* name)
		: m_name{ name }, m_rectangle{ 0, 0, 0, 0 }
	{

	}

	EditorView::~EditorView()
	{

	}

	const char* EditorView::Name() const
	{
		return m_name.c_str();
	}

	void EditorView::Initialise()
	{
	}

	void EditorView::Render()
	{
		m_rectangle =
		{
			.x = 0,
			.y = 0,
			.width = Application::Instance()->Width(),
			.height = Application::Instance()->Height()
		};

		OnRender();
	}

	void EditorView::Tick(float dt)
	{
		OnTick(dt);
	}
}
