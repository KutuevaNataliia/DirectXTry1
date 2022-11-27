#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	Window wnd(300, 300, "Test window");
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		wnd.Gfx().ClearBuffer(0.5, 0.5, 0.5);
		wnd.Gfx().DrawTestTriangle();
		wnd.Gfx().EndFrame();
	}
	if (gResult == -1)
	{
		return -1;
	}
	return msg.wParam;
	
	return 0;
}