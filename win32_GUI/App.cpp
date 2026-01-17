#include "App.h"


App::App(AppMode mode)
    : 
    wnd(800, 600, L"My App"),
    mode(mode)
{
    if (mode == AppMode::GUI)
        wnd.SetMode(Window::Mode::GUI);
    else
        wnd.SetMode(Window::Mode::Game);
}

int App::Go()
{
    if (mode == AppMode::Game)
    {
        while (true)
        {
            if (const auto ecode = Window::ProcessMessages())
                return *ecode;

            DoFrame(); // update & render every iteration
        }
    }
    else // GUI mode
    {
        MSG msg = {};
        while (GetMessage(&msg, nullptr, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return static_cast<int>(msg.wParam);
    }
}


void App::DoFrame()
{
    const float c = sin(timer.Peek()) / 2.0f + 0.5f;
    auto& gfx = wnd.Gfx();
    gfx.ClearBuffer(0.1f, 0.1f, 0.2f);
    wnd.Gfx().DrawTestTriangle();
	gfx.EndFrame();
}