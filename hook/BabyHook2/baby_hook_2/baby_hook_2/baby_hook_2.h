// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BABY_HOOK_2_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BABY_HOOK_2_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef BABY_HOOK_2_EXPORTS
#define BABY_HOOK_2_API __declspec(dllexport)
#else
#define BABY_HOOK_2_API __declspec(dllimport)
#endif
#include<stdio.h>
#include<stdlib.h>
// �����Ǵ� baby_hook_2.dll ������
class BABY_HOOK_2_API Cbaby_hook_2 {
public:
	Cbaby_hook_2(void);
	// TODO:  �ڴ�������ķ�����
};

extern BABY_HOOK_2_API int nbaby_hook_2;

BABY_HOOK_2_API int fnbaby_hook_2(void);
