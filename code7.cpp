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

DWORD WINAPI Black(LPVOID lpParam) {
	SetProcessDPIAware();
	int wDest;
	int iVar1;
	HDC hdcDest;
	int hDest;

	wDest = GetSystemMetrics(0);
	iVar1 = GetSystemMetrics(1);
	hdcDest = GetDC((HWND)0x0);
	do {
		do {
			hDest = 0;
		} while (iVar1 < 1);
		do {
			StretchBlt(hdcDest, 0, 0, wDest, hDest, hdcDest, 0, 0, 1, 1, 0x8800c6);
			Sleep(1);
			hDest = hDest + 6;
		} while (hDest < iVar1);
	} while (true);
}
DWORD WINAPI Mlt(LPVOID lpParam) {
	time_t t;
	HDC screenDC = GetDC(NULL);
	int scrWidth = GetDeviceCaps(screenDC, HORZRES);
	int scrHeight = GetDeviceCaps(screenDC, VERTRES);
	int i = 1;
	int x;
	while (1) {
		HDC screenDC = GetDC(NULL);
		x = rand() % scrWidth;
		BitBlt(screenDC, x, 1, 9000, scrHeight, screenDC, x, 0, SRCCOPY);
		Sleep(2);
	}
}
DWORD WINAPI  PlgBlt(LPVOID lpParam) {
	while (1)
	{
		HDC desk;
		RECT wRect;
		POINT wPt[3];
		desk = GetDC(0);
		HDC deskMem = CreateCompatibleDC(desk);
		int xs = GetSystemMetrics(0), ys = GetSystemMetrics(1);
		HBITMAP screenshot = CreateCompatibleBitmap(desk, xs, ys);
		SelectObject(deskMem, screenshot);
		GetWindowRect(GetDesktopWindow(), &wRect);
		wPt[0].x = wRect.left + 19;
		wPt[0].y = wRect.top - 90;
		wPt[1].x = wRect.right + 10;
		wPt[1].y = wRect.top + 18;
		wPt[2].x = wRect.left - 70;
		wPt[2].y = wRect.bottom - 90;
		PlgBlt(deskMem, wPt, desk, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
		SelectObject(desk, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));

		BitBlt(desk, 0, 0, xs, ys, deskMem, 0, 0, 0x2837E28);
		DeleteDC(desk);
		DeleteObject(screenshot);
		if (rand() % 10 == 4) InvalidateRect(0, 0, 0);
	}
}
DWORD WINAPI Dmwhile(LPVOID lpParam) {
	HDC dc;
	int i = 1;
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1), x;
	while (i <= 89)//loop 89
	{
		dc = GetDC(0);
		x = rand() % w;
		BitBlt(dc, x, 1, 10, h, dc, x, 0, NOTSRCCOPY);
		Sleep(2);
		i++;
	}
	return 0;
}
int main() {
	while (0 == 0) {
		HANDLE thread11 = CreateThread(0, 0, Black, 0, 0, 0);
		HANDLE thread12 = CreateThread(0, 0, PlgBlt, 0, 0, 0);
		HANDLE thread13 = CreateThread(0, 0, Dmwhile, 0, 0, 0);
		Sleep(1000);

	}
	

}
