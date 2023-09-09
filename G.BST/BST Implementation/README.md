# BST Implementation

```h
#pragma once
enum Order
{
	INORDER = 0,
	PREORDER = 1,
	POSTORDER = 2,
	XOrder = 3
};

template<class T>
class Node {
public:
	T val;
	Node<T>* right;
	Node<T>* left;

	Node();
	Node(T val);
};

template<class T>
class BST
{
	Node<T>* root;

public:
	BST();
	bool contains(T val);
	void insert(T val);
	Node<T>* findNode(T val);
	void traverse(Order order);
	void inOrder(Node<T>* node);
	void preOrder(Node<T>* node);
	void postOrder(Node<T>* node);
};
```

```cpp
#include "BST.h"
#include<assert.h>
#include<iostream>
using namespace std;

template<class T>
Node<T>::Node() {
	left = right = NULL;
}

template<class T>
Node<T>::Node(T val) {
	this->val = val;
	left = right = NULL;
}

template<class T>
BST<T>::BST() {
	root = NULL;
}

template<class T>
Node<T>* BST<T>::findNode(T val) {
	Node<T>* tmp = root;
	while (tmp != NULL) {
		if (val == tmp->val)
			return tmp;

		else if (val > tmp->val)
			tmp = tmp->right;
		
		else 
			tmp = tmp->left;	
	}
	return tmp;
}

template<class T>
bool BST<T>::contains(T val) {
	Node<T>* tmp = findNode(val);
	return tmp != NULL;
}

template<class T>
void BST<T>::insert(T val) {
	assert(!contains(val));

	Node<T>* newNode = new Node<T>(val);
	if (root == NULL) {
		root = newNode;
		return;
	}

	Node<T>* tmp = root;
	while (true) {
		if (val > tmp->val) {
			if (tmp->right == NULL) {
				tmp->right = newNode;
				return;
			}
			tmp = tmp->right;
		}

		else if (val < tmp->val) {
			if (tmp->left == NULL) {
				tmp->left = newNode;
				return;
			}
			tmp = tmp->left;
		}
	}
}

template<class T>
void BST<T>::traverse(Order order) {
	if (order == INORDER)
		inOrder(root);

	else if (order == PREORDER)
		preOrder(root);
	
	else if (order == POSTORDER) 
		postOrder(root);
}

template<class T>
void BST<T>::inOrder(Node<T>* node) {
	// left root right
	if (node != NULL) 
	{
		inOrder(node->left);
		cout << node->val << "\n";
		inOrder(node->right);
	}
}

template<class T>
void BST<T>::preOrder(Node<T>* node) {
	// root left right
	if (node != NULL) 
	{
		cout << node->val << "\n";
		preOrder(node->left);
		preOrder(node->right);
	}
}

template<class T>
void BST<T>::postOrder(Node<T>* node) {
	// left right root;
	if (node != NULL) 
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->val << "\n";
	}
}
```

```cpp
#include <iostream>
#include"BST.cpp"
using namespace std;
int main()
{
	BST<int> B;
	B.insert(100);
	B.insert(200);
	B.insert(90);
	B.insert(150);
	B.insert(125);
	B.insert(88);
	B.insert(99);
	B.insert(210);

	B.traverse(POSTORDER);
}
```
