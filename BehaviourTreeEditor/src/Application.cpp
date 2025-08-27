#include "Application.h"

#define DEFAULT_WINDOW_WIDTH 1600
#define DEFAULT_WINDOW_HEIGHT 900
#define DEFAULT_WINDOW_TITLE "Behaviour Tree Editor"

#include <cstdlib>
#include <raylib.h>

#include "Editor/CanvasView.h"
#include "Editor/EditorView.h"
#include "Editor/Utilities.h"

namespace BehaviourTree::Editor
{
	Application* Application::m_instance = nullptr;

	int Application::Launch()
	{
		// If the instance has already been created, we can't launch
		if (m_instance != nullptr)
		{
			return EXIT_FAILURE;
		}

		// Create a new application instance and run it
		m_instance = new Application;
		const int ret = m_instance->Run();

		// Clean up the application memory
		delete m_instance;
		m_instance = nullptr;

		// Return the result of the application run.
		return ret;
	}

	Application* Application::Instance()
	{
		return m_instance;
	}

	float Application::Width() const
	{
		return m_width;
	}

	float Application::Height() const
	{
		return m_height;
	}

	void Application::ListenScreenResize(const ScreenResizeFunction& fnc)
	{
		m_screenResizeCallbacks.emplace_back(fnc);
	}

	Application::Application()
		: m_width{ DEFAULT_WINDOW_WIDTH }, m_height{ DEFAULT_WINDOW_HEIGHT },
		m_title{ DEFAULT_WINDOW_TITLE }
	{
		m_views.emplace_back(new CanvasView);
	}

	Application::~Application()
	{
		for (const auto& view : m_views)
		{
			delete view;
		}

		m_views.clear();
	}

	int Application::Run()
	{
		// Attempt to open the window in resizable mode
		SetConfigFlags(FLAG_WINDOW_RESIZABLE);
		InitWindow(static_cast<int>(m_width), static_cast<int>(m_height), m_title);

		// If somehow the window failed to open, return failure
		if (!IsWindowReady())
		{
			return EXIT_FAILURE;
		}

		// Initialise the editor views
		Initialise();

		// Maximise the window automatically and prevent any key closing the window
		MaximizeWindow();
		SetExitKey(KEY_NULL);

		Color background = FromHex(0x1a1a1aff);

		while (!WindowShouldClose())
		{
			float oldWidth = m_width;
			float oldHeight = m_height;

			// Updated the width and height variables to the current values
			m_width = static_cast<float>(GetScreenWidth());
			m_height = static_cast<float>(GetScreenHeight());

			if (!CompareFloat(oldHeight, m_height) || !CompareFloat(oldWidth, m_width))
			{
				for (auto& cb : m_screenResizeCallbacks)
				{
					cb(m_width, m_height);
				}
			}

			Tick(GetFrameTime());

			BeginDrawing();
			ClearBackground(background);

			Render();

			EndDrawing();
		}

		// Close down the window
		CloseWindow();

		// Program ran completely so return success.
		return EXIT_SUCCESS;
	}

	void Application::Initialise() const
	{
		for (const auto& view : m_views)
		{
			view->Initialise();
		}
	}

	void Application::Tick(const float dt) const
	{
		for (const auto& view : m_views)
		{
			view->Tick(dt);
		}
	}

	void Application::Render() const
	{
		for (const auto& view : m_views)
		{
			view->Render();
		}
	}
}
