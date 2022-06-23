#include <iostream>
#include <Windows.h>
#include<cmath>
#include<tchar.h>
#include<stdio.h>
#pragma comment(lib, "winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
#define winapi WINAPI
#define lpvoid LPVOID
#define dword DWORD
#define ulonglong ULONGLONG
#define uint UINT
#define rdtsc __rdtsc

int x = 1920, y = 1080;
auto hdc = GetWindowDC(GetDesktopWindow());
struct tagRECT Rect;
HBRUSH hBrush;
int main() {
	while (0==0) {
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(SM_CXSCREEN),
			h = GetSystemMetrics(SM_CYSCREEN),//melt Effect
			rx = rand() % w;
		DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WARNING));
		DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
		DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WINLOGO));
		BitBlt(hdc, rx, 10, 100, h, hdc, rx, 0, SRCCOPY);
		ReleaseDC(NULL, hdc);
	}
}
	
