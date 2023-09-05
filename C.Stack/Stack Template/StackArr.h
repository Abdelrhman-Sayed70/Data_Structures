#pragma once
template <class T>
class StackArr
{
private:
	T* arr;
	int size;
	int capacity;

public:
	StackArr();
	void push(T val);
	void pop();
	void expand();
	int lenght();
	T top();
	bool empty();
	~StackArr();
};