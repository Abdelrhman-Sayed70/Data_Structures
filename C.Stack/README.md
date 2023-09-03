# Stack 

```h
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
```
```cpp
#include "StackArr.h"
#include <assert.h>

StackArr::StackArr() {
	capacity = 10;
	arr = new int[capacity];
	size = 0;
}

int StackArr::lenght() {
	return size;
}

int StackArr::top() {
	assert(size != 0);
	return arr[size - 1];
}

void StackArr::push(int val) {
	if (size == capacity)
		expand();

	arr[size] = val;
	size++;
}

void StackArr::pop() {
	assert(size != 0);
	size--;
}

void StackArr::expand() {
	capacity *= 2;
	int* expandedArr = new int[capacity];
	for (int i = 0; i < size; i++) {
		expandedArr[i] = arr[i];
	}

	delete[] arr;
	arr = expandedArr;
}

bool StackArr::empty() {
	return size == 0;
}

StackArr::~StackArr() {
	delete[]arr;
	arr = NULL;
}
```
```cpp
#include <iostream>
#include"StackArr.h"
using namespace std;
int main()
{
	StackArr st;
	st.push(1);
	st.push(2);
	st.push(3);

	while (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	}
}
```
