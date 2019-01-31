// baby_hook_2.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "baby_hook_2.h"


// 这是导出变量的一个示例
BABY_HOOK_2_API int nbaby_hook_2=0;

// 这是导出函数的一个示例。
BABY_HOOK_2_API int fnbaby_hook_2(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 baby_hook_2.h
Cbaby_hook_2::Cbaby_hook_2()
{
    return;
}
