#include "Application.h"

#define DEFAULT_WINDOW_WIDTH 1600
#define DEFAULT_WINDOW_HEIGHT 900
#define DEFAULT_WINDOW_TITLE "Behaviour Tree Editor"

#include <cstdlib>
#include <raylib.h>

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

Application const* Application::Instance()
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

Application::Application()
	: m_width{ DEFAULT_WINDOW_WIDTH }, m_height{ DEFAULT_WINDOW_HEIGHT },
	m_title{ DEFAULT_WINDOW_TITLE }
{
}

Application::~Application()
{
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

	// Maximise the window automatically and prevent any key closing the window
	MaximizeWindow();
	SetExitKey(KEY_NULL);

	// Run the initialisation code
	Initialise();

	while (!WindowShouldClose())
	{
		// Updated the width and height variables to the current values
		m_width = static_cast<float>(GetScreenWidth());
		m_height = static_cast<float>(GetScreenHeight());

		Tick(GetFrameTime());

		BeginDrawing();
		ClearBackground(RAYWHITE);

		Render();

		EndDrawing();
	}

	// Run cleanup code and close down the window
	Shutdown();
	CloseWindow();

	// Program ran completely so return success.
	return EXIT_SUCCESS;
}

void Application::Initialise()
{
}

void Application::Tick(float dt)
{
}

void Application::Render()
{
}

void Application::Shutdown()
{
}
