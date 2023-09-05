# Stack Template

```h
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
```
```cpp
#include "StackArr.h"
#include <assert.h>

template<class T>
StackArr<T>::StackArr() {
	capacity = 2;
	arr = new T[capacity];
	size = 0;
}

template<class T>
int StackArr<T>::lenght() {
	return size;
}

template<class T>
T StackArr<T>::top() {
	assert(size != 0);
	return arr[size - 1];
}

template<class T>
void StackArr<T>::push(T val) {
	if (size == capacity)
		expand();

	arr[size] = val;
	size++;
}

template<class T>
void StackArr<T>::pop() {
	assert(size != 0);
	size--;
}

template<class T>
void StackArr<T>::expand() {
	capacity *= 2;
	int* expandedArr = new T[capacity];
	for (int i = 0; i < size; i++) {
		expandedArr[i] = arr[i];
	}

	delete[] arr;
	arr = expandedArr;
}

template<class T>
bool StackArr<T>::empty() {
	return size == 0;
}

template<class T>
StackArr<T>::~StackArr() {
	delete[]arr;
	arr = NULL;
}
```
```cpp
#include <iostream>
#include"StackArr.cpp"
using namespace std;
int main()
{
	StackArr<int>st;
	st.push(1);
	st.push(2);
	st.push(3);

	while (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	}
}
```
