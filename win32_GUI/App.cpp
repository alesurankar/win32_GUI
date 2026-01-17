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
            UpdateFrame();
            DrawFrame();
        }
        if (ecode) {
            return *ecode;
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
    gfx.DrawTestTriangle(
        timer.Peek(),
        wnd.mouse.GetPosX() / 400.0f - 1.0f,
        -wnd.mouse.GetPosY() / 300.0f + 1.0f
    );
	gfx.EndFrame();
}