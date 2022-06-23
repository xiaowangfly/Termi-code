#include<windows.h>
#include<time.h>
#include<tchar.h>
#include<stdio.h>
#include<iostream>
//Do not run long time
int main()
{
	FreeConsole();
 HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);


	while (0 == 0)
	{
		DrawIcon(hdc, rand() % 1920, rand() % 1080 , LoadIcon(nullptr, IDI_ERROR));//画错误图标
		DrawIcon(hdc, rand() % 1920, rand() % 1080 , LoadIcon(nullptr, IDI_WINLOGO));
		DrawIcon(hdc, rand() % 1920, rand() % 1080, LoadIcon(nullptr, IDI_QUESTION));
		DrawIcon(hdc, rand() % 1920, rand() % 1080, LoadIcon(nullptr, IDI_WARNING));
		DrawIcon(hdc, rand() % 1920, rand() % 1080, LoadIcon(nullptr, IDI_SHIELD));
		DrawIcon(hdc, rand() % 1920, rand() % 1080, LoadIcon(nullptr, IDI_INFORMATION));




	}




}
