// dllmain.cpp : 定义 DLL 应用程序的入口点。
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "baby_hook_2.h"
HHOOK hooker;
HWND notepadhandle;
BOOL handled;
extern "C" {
	__declspec(dllexport) LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		char szPath[MAX_PATH] = { 0 };
		char *p = NULL;
		if (nCode >= 0) {
			if (!(lParam & 0x80000000)) {
				GetModuleFileNameA(NULL, szPath, MAX_PATH);
				p = strrchr(szPath, '\\');
				if (!_stricmp(p + 1, "Notepad.exe"))
					return 1;
			}
		}
		return CallNextHookEx(hooker, nCode, wParam, lParam);
	}
	__declspec(dllexport) void HookStop()
	{
		if (hooker) {
			UnhookWindowsHookEx(hooker);
			hooker = NULL;
		}
	}
}
/*
extern "C" __declspec(dllexport) LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam);
extern "C" __declspec(dllexport) void HookStop();
*/
void hookit(HMODULE hModule) {
	handled = FALSE;
	notepadhandle = FindWindow(L"Notepad", NULL);
	if (notepadhandle == NULL) {
		printf("Notepad Not Found.\n");
		return;
	}
	hooker = SetWindowsHookEx(WH_KEYBOARD, HookProc, (HINSTANCE)hModule, GetWindowThreadProcessId(notepadhandle, NULL));
	if (hooker) {
		printf("Hook succeed.\nHookID:%llx\n", (unsigned __int64)hooker);
	}
	else {
		printf("Hook failed.\nError:%x\n",GetLastError());
		return;
	}
	
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hookit(hModule);
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
