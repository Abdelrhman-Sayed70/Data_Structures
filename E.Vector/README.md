# Vector [Array List]


```h
#pragma once
template<class T>
class ArrList
{
	T* arr;
	int capacity;
	int size;

public:
	ArrList();
	void insertAt(int position, T val);
	void deleteAt(int position);
	void append(T val);
	void expand();
	T at(int position);
	int lenght();
	void dispaly();
	~ArrList(void);
};
```
```cpp
#include "ArrList.h"
#include<assert.h>
#include<iostream>
using namespace std;

template<class T>
ArrList<T>::ArrList() {
	capacity = 5;
	arr = new T[capacity];
	size = 0;
}

template<class T>
void ArrList<T>::expand() {
	capacity *= 2;
	int* expandedArr = new int[capacity];
	for (int i = 0; i < size; i++) {
		expandedArr[i] = arr[i];
	}

	delete[] arr;
	arr = expandedArr;
}

template<class T>
int ArrList<T>::lenght() {
	return size;
}

template <class T>
void ArrList<T>::append(T val) {
	if (size == capacity)
		expand();

	arr[size] = val;
	size++;
}

template<class T>
void ArrList<T>::dispaly() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

template<class T>
void ArrList<T>::insertAt(int position, T val) {
	assert(position >= 0 and position < size);

	if (capacity == size)
		expand();

	// shift elements
	for (int i = size; i > position; i--) {
		arr[i] = arr[i - 1];
	}

	// insert new element
	arr[position] = val;
	size++;
}

template<class T>
void ArrList<T>::deleteAt(int position) {
	assert(position >= 0 and position < size);

	// shift elements
	for (int i = position; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

template<class T>
T ArrList<T>::at(int position) {
	assert(position >= 0 and position < size);
	return arr[position];
}

template<class T>
ArrList<T>::~ArrList() {
	delete[] arr;
}
```

```cpp
#include <iostream>
#include"ArrList.cpp"
using namespace std;
int main()
{
	ArrList<int>arr;
	arr.append(1);
	arr.append(2);
	arr.append(3);
	arr.dispaly();
	cout << "\n";
	arr.deleteAt(0);
	arr.insertAt(1, 20);
	arr.dispaly();
}

```
