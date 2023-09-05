# Queue

```h
#pragma once
template<class T>
class QueueArr
{
public:
	T* arr;
	T front;
	T back;
	int size;
	int capacity;

	QueueArr();
	int lenght();
	T Front();
	bool empty();
	bool full();
	void push(T val);
	void pop();
	~QueueArr();
};
```
```cpp
#include "QueueArr.h"
#include<assert.h>

template<class T>
QueueArr<T>::QueueArr() {
	size = 0;
	capacity = 5;
	arr = new T(capacity);
	front = back = -1;
}

template<class T>
int QueueArr<T>::lenght() {
	return size;
}

template<class T>
bool QueueArr<T>::empty() {
	return size == 0;
}

template<class T>
bool QueueArr<T>::full() {
	return size == capacity;
}

template<class T>
void QueueArr<T>::push(T val) {
	assert(!full());
	back = (back + 1) % capacity;
	arr[back] = val;
	size++;
	if (front == -1)
		front = 0;
}

template<class T>
void QueueArr<T>::pop() {
	assert(!empty());
	front = (front + 1) % capacity;
	size--;
	if (size == 0)
		front = back = -1;
}	

template<class T>
T QueueArr<T>::Front() {
	assert(!empty());
	return arr[front];
}

template<class T>
QueueArr<T>::~QueueArr() {
	//delete[]arr;
	//arr = NULL;
}
```
```cpp
#include <iostream>
#include"QueueArr.cpp"
using namespace std;
int main()
{
	QueueArr<int>q;
	q.push(1);
	q.push(2);
	q.push(3);

	q.pop();
	// f: 1 2 3 :b
	while (!q.empty()) {
		cout << q.Front() << " ";
		q.pop();
	}
}
```
