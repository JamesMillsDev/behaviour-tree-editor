#pragma once

class Application
{
public:
	static int Launch();
	static Application const* Instance();

public:
	float Width() const;
	float Height() const;

private:
	static Application* m_instance;

private:
	float m_width;
	float m_height;
	const char* m_title;

private:
	Application();
	~Application();

private:
	int Run();

	void Initialise();

	void Tick(float dt);
	void Render();

	void Shutdown();

};