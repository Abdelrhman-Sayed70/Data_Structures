#include "Rectangle.h"
#include<iostream>
using namespace std;

Rectangle::Rectangle() {
	this->lenght = 0;
	this->width = 0;
}

Rectangle::Rectangle(int lenght, int width) {
	this->lenght = lenght;
	this->width = width;
}

int Rectangle::getArea() {
	return lenght * width;
}

Rectangle::~Rectangle(void) {
	cout << "destructor";
}