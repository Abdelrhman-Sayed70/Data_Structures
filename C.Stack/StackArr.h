#pragma once
class StackArr
{
private:
	int* arr;
	int size;
	int capacity;

public:
	StackArr();
	void push(int val);
	void pop();
	void expand();
	int lenght();
	int top();
	bool empty();
	~StackArr();
};