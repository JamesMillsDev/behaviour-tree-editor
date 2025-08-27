#pragma once

#include <functional>
#include <vector>

using std::function;
using std::vector;

namespace BehaviourTree::Editor
{
	typedef function<void(float, float)> ScreenResizeFunction;

	class EditorView;

	class Application
	{
	public:
		static int Launch();
		static Application* Instance();

	public:
		float Width() const;
		float Height() const;

		void ListenScreenResize(const ScreenResizeFunction& fnc);

	private:
		static Application* m_instance;

	private:
		float m_width;
		float m_height;
		const char* m_title;

		vector<EditorView*> m_views;
		vector<ScreenResizeFunction> m_screenResizeCallbacks;

	private:
		Application();
		~Application();

	private:
		int Run();

		void Initialise() const;
		void Tick(float dt) const;
		void Render() const;

	};
}