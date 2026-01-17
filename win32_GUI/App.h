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
	App(AppMode mode = AppMode::Game);
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	MyTimer timer;
	AppMode mode;
};