// baby_hook.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "baby_hook.h"


// ���ǵ���������һ��ʾ��
BABY_HOOK_API int nbaby_hook=0;

// ���ǵ���������һ��ʾ����
BABY_HOOK_API int fnbaby_hook(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� baby_hook.h
Cbaby_hook::Cbaby_hook()
{
    return;
}
