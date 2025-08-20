#include<Windows.h>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int  nCmdShow)
{
	const wchar_t* pClassName = L"hw3Test";

	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
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
		200,200,640,480,
		nullptr,
		nullptr,
		hInstance,
		nullptr
		);

	ShowWindow(hwnd, SW_SHOW);

	while (true);

	return 0;
}