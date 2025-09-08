#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	LPCTSTR lpszClass = TEXT("Sample Window Class");

	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = lpszClass;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		lpszClass,
		TEXT("Hello WinAPI"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		800,
		600,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (hwnd == nullptr)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {};

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (uMsg)
	{
	case WM_PAINT:
	{
		ps;
		hdc = BeginPaint(hwnd, &ps);

		TextOut(hdc, 50, 50, TEXT("Hello, Windows!"), 15);
		Rectangle(hdc, 100, 100, 300, 200);
		Ellipse(hdc, 350, 100, 550, 300);

		EndPaint(hwnd, &ps);
		break;
	}
	/*case WM_LBUTTONDOWN:
		ps;
		hdc = BeginPaint(hwnd, &ps);

		TextOut(hdc, 200, 200, TEXT("나 없지롱"), 5);

		EndPaint(hwnd, &ps);
		break;*/
	case WM_RBUTTONDOWN:
		hdc = GetDC(hwnd);
		TextOut(hdc, 100, 100, TEXT("어케 찾았지"), 6);
		ReleaseDC(hwnd, hdc);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

		return 0;
	}


	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}