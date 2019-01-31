#include<stdio.h>
#include<windows.h>
typedef void (*pM)();
int main(){
	HMODULE hDll = LoadLibrary("baby_hook_2.dll");
	if(hDll!=NULL){
		printf("Load dll DONE");
		pM fp = (pM)GetProcAddress(hDll,TEXT("HookStop"));
		if(fp!=NULL){
			printf("function loaded");
			getchar();
			fp();
		}else{
			printf("function not found");
		}
	}
	getchar();
	FreeLibrary(hDll);
	return 1;
}