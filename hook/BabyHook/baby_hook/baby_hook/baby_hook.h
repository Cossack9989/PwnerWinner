// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BABY_HOOK_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BABY_HOOK_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef BABY_HOOK_EXPORTS
#define BABY_HOOK_API __declspec(dllexport)
#else
#define BABY_HOOK_API __declspec(dllimport)
#endif
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
// �����Ǵ� baby_hook.dll ������
class BABY_HOOK_API Cbaby_hook {
public:
	Cbaby_hook(void);
	// TODO:  �ڴ�������ķ�����
};

extern BABY_HOOK_API int nbaby_hook;

BABY_HOOK_API int fnbaby_hook(void);
