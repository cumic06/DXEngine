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
			SetWindowText(hwnd, L"�� Ű ����");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hwnd, L"�� Ű �ø�");
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
	wc.cbClsExtra = 0; //API�� ����Ǵ� Ŭ���� ����ü 0���� �߰� ����Ʈ
	wc.cbWndExtra = 0; //�����Ǵ� â������ 0�� �߰�����Ʈ
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;//���ø����̼� ������ 
	wc.hCursor = nullptr;//���ø����̼� Ŀ��
	wc.hbrBackground = nullptr; //���
	wc.lpszMenuName = nullptr; //�޴� �̸�
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	const wchar_t* windowName = L"Happy Hard Window";

	//������ â ����
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

	//������ â Ȱ��ȭ
	ShowWindow(hwnd, SW_SHOW);

	//�޽��� Ȱ��ȭ

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