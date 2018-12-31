#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include"Node.h"

using namespace std;

Node* list[0x20];
int Nindex = 0;

void welcome() {
	cout << "=========================================" << endl;
	cout << "      Welcome to WinPWN Challenge-01     " << endl;
	cout << "=========================================" << endl;
	cout << "Now you can play with 128 nodes, have fun" << endl;
	list[0] = new Node();
}

int menu() {
	int op = 0;
	cout << "1.Add a node" << endl;
	cout << "2.Del a node" << endl;
	cout << "3.Change it" << endl;
	cout << "4.Exit" << endl;
	cout << ">>> ";
	cin >> op;
	return op;
}

bool judgeUse(int index) {
	if (list[index] == 0) return false;
	else {
		if (list[index]->isDel() == true) return false;
		else return true;
	}
}

void AddNode() {
	char* str;
	int size;
	do {
		cout << "Size : ";
		cin >> size;
		cin.get();
	} while (size < 0 || size > 0x400);
	str = new char[size];
	cout << "Data : ";
	fread(str, 1, size + 1, stdin);
	str[size] = '\x00';
	list[Nindex] = new Node(size + 1);
	list[Nindex]->FillNode(str);
	cout << "[+]Done! Here is the info of this node" << endl;
	list[Nindex]->ShowNode();
}
void DelNode() {
	int index;
	do {
		cout << "Index : ";
		cin >> index;
		cin.get();
	} while (judgeUse(index) == false || index < 0 || index >= 0x20);
	list[index]->~Node();
	cout << "[-]Done! this node has been dead" << endl;
}
void Change() {
	int index;
	char* str;
	char op;
	do {
		cout << "Index : ";
		cin >> index;
		cin.get();
	} while (judgeUse(index) == false || index < 0 || index >= 0x20);
	cout << "[+]Here is the original info of this node" << endl;
	list[index]->ShowNode();
	cout << "[*]Now new data in need" << endl;
	str = (char*)malloc(list[index]->getSize());
	fread(str, 1, list[index]->getSize(), stdin);
	cin.get();
	list[index]->FillNode(str);
	cout << "[*]Anything wrong?(y/n)";
	cin >> op;
	cin.get();
	if (op == 'y') {
		list[index]->err_msg();
	} else {
		cout << "See you" << endl;
	}
}

int main() {
	welcome();
	while (1) {
		switch (menu()) {
		case 1:
			AddNode();
			break;
		case 2:
			DelNode();
			break;
		case 3:
			Change();
			break;
		case 4:
			cout << "Bye" << endl;
			exit(0);
		default:
			cout << "WTF???" << endl;
			break;
		}
	}
	return 0;
}