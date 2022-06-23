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
		while (0 == 0)
		{
			BitBlt(hdc, rand() % 10 - 25, rand() % 25 - 10, x, y, hdc, 0, 0, SRCCOPY);//<--- Effect

		}
	}
