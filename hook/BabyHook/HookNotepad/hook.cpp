#include<stdio.h>
#include<windows.h>
int main(){
	LoadLibrary("IAT_Hook.dll");
	getchar();
	return 1;
} 
