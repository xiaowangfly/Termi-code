#include <iostream>
#include <Windows.h>
#include <cmath>
#include<tchar.h>
#include<stdio.h>
#pragma comment(lib, "winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 

int x = 1920, y = 1080;
auto hdc = GetWindowDC(GetDesktopWindow());
struct tagRECT Rect;
HBRUSH hBrush;
//Do not run long time
DWORD WINAPI  Textout(LPVOID lpParam) {
	HDC hdc;
	int sx = 0, sy = 0;
	LPCWSTR lpText = L"Synth_Cir NB!";
	int i = 1;
	while (i <= 320)
	{
		hdc = GetWindowDC(GetDesktopWindow());
		sx = GetSystemMetrics(0);
		sy = GetSystemMetrics(1);
		TextOutW(hdc, rand() % 1920, rand() % 1080, lpText, wcslen(lpText));
		Sleep(10);
		i++;
	}
	return 0;
}
DWORD WINAPI Textout2(LPVOID lpParam) {
	HDC hdc;
	int sx = 0, sy = 0;
	LPCWSTR lpText = L"Termi by Synth_Cir";
	int i = 1;
	while (i <= 900)
	{
		hdc = GetWindowDC(GetDesktopWindow());
		sx = GetSystemMetrics(0);
		sy = GetSystemMetrics(1);
		SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		SetBkColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		TextOutW(hdc, rand() % 1920, rand() % 1080, lpText, wcslen(lpText));
		i++;
		Sleep(10);
	}
	return 0;
}


int main()
{
	while (0 == 0)
	{
		HANDLE thread7 = CreateThread(0, 0, Textout, 0, 0, 0);
		HANDLE thread10 = CreateThread(0, 0, Textout2, 0, 0, 0);
		Sleep(3000);
	}

}
