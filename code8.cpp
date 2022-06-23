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
	HWND upWnd = GetForegroundWindow();
	HDC upHdc = GetDC(upWnd);
	HDC desk = GetDC(NULL);
	int sw = GetSystemMetrics(SM_CXSCREEN);
	int sh = GetSystemMetrics(SM_CYSCREEN);
	int i = 1;
	while (i <= 300) {
		upWnd = GetForegroundWindow();
		upHdc = GetDC(upWnd);
		desk = GetDC(NULL);
		POINT c;
		GetCursorPos(&c);
		BitBlt(desk, -1, 1, sw, sh, desk, 2, 2, NOTSRCCOPY);
		SelectObject(desk, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		BitBlt(desk, -rand() % 15, rand() % 15, sw, sh, desk, -rand() % 11, rand() % 11, 0x2837E28);
		i++;
	}
}
	
