// dllmain.cpp : 定义 DLL 应用程序的入口点。
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Baby_Hook.h"
HHOOK hooker;
HWND notepadhandle;
BOOL handled;
extern "C" __declspec(dllexport) LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam);
//char* ConvertInttoChar(int i);

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		handled = FALSE;
		notepadhandle = FindWindow(L"Notepad", NULL);
		if (notepadhandle == NULL) {
			printf("Notepad Not Found.\n");
			return TRUE;
		}
		hooker = SetWindowsHookEx(WH_GETMESSAGE, HookProc, (HINSTANCE)hModule, GetWindowThreadProcessId(notepadhandle, NULL));
		if (hooker) {
			printf("Hook Succeed.\nHookID:%d\n", (int)hooker);
		}
		else {
			printf("Hook Failed.\nError:%x\n", GetLastError());
			return TRUE;
		}
		PostMessage(notepadhandle, WM_CLOSE, 0, 0);
	}
	return TRUE;
}

extern "C" __declspec(dllexport) LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode<0)
		return CallNextHookEx(hooker, nCode, wParam, lParam);
	tagMSG* msg;
	msg = (tagMSG*)lParam;
	if (nCode == HC_ACTION && (msg->message == WM_CLOSE)) {
		if (handled == FALSE) {
			handled = TRUE;
			MessageBox(NULL, L"This is a messagebox from notepad.exe", L"hook", MB_OK);
		}
		UnhookWindowsHookEx(hooker);
		msg->message = WM_NULL;
		return CallNextHookEx(hooker, nCode, wParam, (LPARAM)msg);
	}
	return CallNextHookEx(hooker, nCode, wParam, lParam);
}
