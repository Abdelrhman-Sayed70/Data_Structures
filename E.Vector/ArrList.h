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