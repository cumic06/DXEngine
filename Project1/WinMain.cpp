#include<Windows.h>
#include "WindowsMessageMap.h"
#include "sstream"

#include "Window.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Window window(600, 800, L"fdadgewag");
	Window wfdw(700, 365, L"grwntnt");

	static WindowsMessageMap mm;
	OutputDebugString((LPCWSTR)mm(msg, lParam, wParam).c_str());

	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hwnd, L"왜 키 누름");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hwnd, L"왜 키 올림");
		}
		break;
	case WM_CHAR:
	{
		static std::wstring title;
		title.push_back((wchar_t)wParam);
		SetWindowText(hwnd, title.c_str());
	}
	break;
	case WM_LBUTTONDOWN:
		POINTS pt = MAKEPOINTS(lParam);
		std::wostringstream oss;
		oss << "(" << pt.x << "," << pt.y << ")";
		SetWindowText(hwnd, oss.str().c_str());
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int  nCmdShow)
{
	const wchar_t* pClassName = L"hw3Test";

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0; //API에 저장되는 클래스 구조체 0개의 추가 바이트
	wc.cbWndExtra = 0; //생성되는 창에대해 0개 추가바이트
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;//어플리케이션 아이콘 
	wc.hCursor = nullptr;//어플리케이션 커서
	wc.hbrBackground = nullptr; //배경
	wc.lpszMenuName = nullptr; //메뉴 이름
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	const wchar_t* windowName = L"Happy Hard Window";

	//윈도우 창 생성
	HWND hwnd = CreateWindowEx
	(
		0,
		pClassName,
		windowName,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	//윈도우 창 활성화
	ShowWindow(hwnd, SW_SHOW);

	//메시지 활성화

	MSG msg;
	BOOL gResult;
	while (gResult = GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}

	return 0;
}