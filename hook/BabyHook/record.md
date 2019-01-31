# BabyHook
## How to use it
- put hook.exe and baby_hook.dll into the same dir
- run hook.exe and you can see notepad being hooked
## some notes
```
typedef struct tagMSG {
  HWND   hwnd;
  UINT   message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD  time;
  POINT  pt;
  DWORD  lPrivate;
} MSG, *PMSG, *NPMSG, *LPMSG;
//Contains message information from a thread's message queue
```
