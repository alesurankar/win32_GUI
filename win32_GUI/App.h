#pragma once
#include "Window.h"

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
	void DoFrame();
private:
	Window wnd;
	AppMode mode;
};