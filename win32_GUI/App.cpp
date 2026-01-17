#include "App.h"


App::App(AppMode mode)
    : 
    wnd(800, 600, L"My App"),
    mode(mode)
{
    if (mode == AppMode::GUI) {
        wnd.SetMode(Window::Mode::GUI);
    }
    else {
        wnd.SetMode(Window::Mode::Game);
        DrawFrame();
    }
}

int App::Go()
{
    while (true)
    {
        std::optional<int> ecode;

        if (mode == AppMode::Game) {
            ecode = Window::ProcessMessages(); // non-blocking
            UpdateFrame();
            DrawFrame();
        }
        else if (mode == AppMode::GUI) {
            ecode = Window::WaitMessages();    // blocking
            if (ecode) {
                return *ecode;
            }
            UpdateFrame();
            DrawFrame();
        }
    }
}

void App::UpdateFrame()
{

}

void App::DrawFrame()
{
    const float c = sin(timer.Peek()) / 2.0f + 0.5f;
    auto& gfx = wnd.Gfx();
    gfx.ClearBuffer(c, c, 1.0f);
    gfx.DrawTestTriangle();
	gfx.EndFrame();
}