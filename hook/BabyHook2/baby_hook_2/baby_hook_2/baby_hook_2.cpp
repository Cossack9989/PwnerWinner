// baby_hook_2.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "baby_hook_2.h"


// ���ǵ���������һ��ʾ��
BABY_HOOK_2_API int nbaby_hook_2=0;

// ���ǵ���������һ��ʾ����
BABY_HOOK_2_API int fnbaby_hook_2(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� baby_hook_2.h
Cbaby_hook_2::Cbaby_hook_2()
{
    return;
}
