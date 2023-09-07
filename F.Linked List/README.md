# Linked List
- Data are not consecutive like dynamic arrays
- Consists of a collection of nodes each node contains val and a pointer to another node
- **`Finding element at certain position`** done using traversing from the front of the linked list

  
```h
#pragma once
template<class T>
class Node {
public:
	T val;
	Node<T>* next;
	Node();
	Node(T val);
};

template<class T>
class LinkedList
{
	int size;
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList();
	int lenght();
	T at(int position);
	void append(T val);
	void insertAt(int position, T val);
	void deleteAt(int position);
	~LinkedList(void);
};
```

```cpp
#include "LinkedList.h"
#include<assert.h>

template<class T>
Node<T>::Node() {
	this->val = 0;
	this->next = NULL;
}

template<class T>
Node<T>::Node(T val) {
	this->val = val;
	this->next = NULL;
}

template<class T>
LinkedList<T>::LinkedList() {
	head = tail = nullptr;
	size = 0;
}

template<class T>
int LinkedList<T>::lenght() {
	return size;
}

template<class T>
void LinkedList<T>::append(T val) {
	Node<T>* node = new Node<T>(val);

	if (size == 0)
		head = tail = node;
	
	else {
		tail->next = node;
		tail = node;
	}

	size++;
}

template<class T>
void LinkedList<T>::insertAt(int position, T val) {
	assert(position >= 0 and position < size);

	Node<T>* newNode = new Node<T>(val);
	if (position == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		// locate the previous node
		Node<T>* tmp = head;
		for (int i = 0; i < position - 1; i++) {
			tmp = tmp->next;	
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	size++;
}

template<class T>
void LinkedList<T>::deleteAt(int position) {
	assert(position >= 0 and position < size);
	Node<T>* tmp = head;
	if (position == 0) {
		head = head->next;
		delete tmp;
	}
	else {
		for (int i = 0; i < position - 1; i++) {
			tmp = tmp->next;
		}
		Node<T>* d = tmp->next;
		tmp->next = d->next;
		delete d;
		if (pos == size - 1)
			tail = tmp;
	} 
	size--;
}

template<class T>
T LinkedList<T>::at(int position) {
	assert(position >= 0 and position < size);

	// start traversing from head;
	Node<T>* node = head;
	for (int i = 0; i < position; i++)
		node = node->next;

	return node->val;
}

template<class T>
LinkedList<T>::~LinkedList() {

}
```
```cpp
#include <iostream>
#include"LinkedList.cpp"
using namespace std;
int main(){
	LinkedList<int>ls;
	ls.append(1);
	ls.append(2);
	ls.append(3);
	ls.insertAt(0, 100);

	for (int i = 0; i < ls.lenght(); i++) {
		cout << ls.at(i) << "\n";
	}
}
```
