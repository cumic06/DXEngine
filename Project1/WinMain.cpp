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