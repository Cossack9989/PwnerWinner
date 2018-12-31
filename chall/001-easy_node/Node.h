#pragma once
#include<iostream>
using namespace std;

extern int Nindex;

class Event
{
public:
	virtual void err_msg();
};
void Event::err_msg() {
	cout << "Event error" << endl;
	cout << "ERROR -> " << hex << static_cast<void *>(this) << endl;
}

class Node: public Event
{
public:
	Node();
	Node(int);
	void ShowNode();
	void FillNode(char*);
	bool isDel();
	int getSize();
	void err_msg();
	~Node();
private:
	int size;
	int index;
	char *data;
};

Node::Node()
{
}

Node::Node(int size) {
	this->size = size;
	this->data = (char*)malloc(this->size);
	Nindex++;
	this->index = Nindex;
}

Node::~Node()
{
	free(this->data);
	this->index = -1;
	this->size = -1;
	this->data = 0x0;
}

void Node::ShowNode() {
	cout << "Index : " << this->index << endl;
	cout << "Data : " << this->data << endl;
}

void Node::FillNode(char* str) {
	memcpy(this->data, str, strlen(str) + 1);
}

bool Node::isDel() {
	if (this->index == -1 && this->size == -1)return true;
	else return false;
}

int Node::getSize() {
	return (this->size) - 1;
}

void Node::err_msg() {
	cout << "Node error" << endl;
	cout << "ERROR -> " << hex << static_cast<void *>(this) << endl;
}