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
//Do ont run long time
DWORD WINAPI Glitch(LPVOID lpParam) {
	FreeConsole();
	DWORD WINAPI screenrotate(LPVOID lpParam); {
		HDC desk = GetDC(0);
		int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
		RECT rekt; POINT wPt[3];
		while (1) {
			GetWindowRect(GetDesktopWindow(), &rekt);
			wPt[0].x = rand() % sw; wPt[0].y = rand() % sh;
			wPt[1].x = rand() % sw; wPt[1].y = rand() % sh;
			wPt[2].x = rand() % sw; wPt[2].y = rand() % sh;
			PlgBlt(desk, wPt, desk, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		}
	}
}




int main()
{

	while (0 == 0) {
		HANDLE thread5 = CreateThread(0, 0, Glitch, 0, 0, 0);
		Sleep(3000);
	}
}
