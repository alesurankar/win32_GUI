#pragma once
#include "Window.h"
#include "MyTimer.h"

enum class AppMode
{
	Game,
	GUI
};

class App
{
public:
	App(AppMode mode = AppMode::GUI);
	int Go();
private:
	void UpdateFrame();
	void DrawFrame();
private:
	Window wnd;
	MyTimer timer;
	AppMode mode;
};