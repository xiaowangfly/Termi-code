#include<windows.h>
#include<time.h>
#include<tchar.h>
int main()
{
	FreeConsole();
	int a, b
		; int x, y
		; x = GetSystemMetrics(SM_CYSCREEN)
		; y = GetSystemMetrics(SM_CYSCREEN)
		; HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd)
		; POINT point;
	while (0 == 0)
	{
		GetCursorPos(&point)
			; int randx, randy
			; randx = rand() % x + 0;
		randy = rand() % y + 0;

			; a = GetSystemMetrics(SM_CXSCREEN);
		b = GetSystemMetrics(SM_CXSCREEN);
		StretchBlt(GetDC(NULL), 50, 50, a - 100, b - 100, GetDC(NULL), 0, 0, a, b, SRCCOPY);
                                Sleep(400);
	



			;
	}




}
