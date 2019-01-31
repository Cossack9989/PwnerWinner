#include<stdio.h>
#include<windows.h>
int main(){
	LoadLibrary("baby_hook.dll");
	getchar();
	return 1;
} 