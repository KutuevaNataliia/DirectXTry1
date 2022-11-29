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
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	//while(true)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		wnd.Gfx().ClearBuffer(0.5, 0.5, 0.5);
		//wnd.Gfx().DrawTestTriangle(timer.Peek());
		wnd.Gfx().DrawTestTriangle(
			timer.Peek(),
			wnd.mouse.GetPosX() / 150.0f - 1.0f,
			-wnd.mouse.GetPosY() / 150.0f + 1.0f
		);
		wnd.Gfx().EndFrame();
	}
	if (gResult == -1)
	{
		return -1;
	}
	return msg.wParam;
	
	return 0;
}