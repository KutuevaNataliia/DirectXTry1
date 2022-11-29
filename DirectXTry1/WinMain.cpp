#include "Window.h"
#include "MyTimer.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	Window wnd(300, 300, "Test window");
	MSG msg;
	BOOL gResult;
	MyTimer timer;
	while(true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}

		wnd.Gfx().ClearBuffer(0.1, 0.4, 0.7);
		/*wnd.Gfx().DrawTestTriangle(
			timer.Peek(),
			wnd.mouse.GetPosX() / 150.0f - 1.0f,
			-wnd.mouse.GetPosY() / 150.0f + 1.0f
		);*/
		wnd.Gfx().DrawTestCube(
			timer.Peek(),
			wnd.mouse.GetPosX() / 150.0f - 1.0f,
			-wnd.mouse.GetPosY() / 150.0f + 1.0f
		);
		wnd.Gfx().EndFrame();
	}
	
	return 0;
}