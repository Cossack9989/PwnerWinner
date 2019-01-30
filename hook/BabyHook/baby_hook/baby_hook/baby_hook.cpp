// baby_hook.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "baby_hook.h"


// 这是导出变量的一个示例
BABY_HOOK_API int nbaby_hook=0;

// 这是导出函数的一个示例。
BABY_HOOK_API int fnbaby_hook(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 baby_hook.h
Cbaby_hook::Cbaby_hook()
{
    return;
}
