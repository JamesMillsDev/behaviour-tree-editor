#pragma once

#include <string>

#include <raylib.h>

using std::string;

namespace BehaviourTree::Editor
{
	class EditorView
	{
		friend class Application;

	public:
		explicit EditorView(const char* name);
		virtual ~EditorView();

	public:
		const char* Name() const;

	protected:
		virtual void Initialise();
		void Render();
		void Tick(float dt);
		
		virtual void OnRender(Rectangle rect) = 0;
		virtual void OnTick(float dt) = 0;

	private:
		string m_name;
		Rectangle m_rectangle;

	};
}
