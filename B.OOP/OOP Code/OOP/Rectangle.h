#pragma once
class Rectangle
{
private:
	int width;
	int lenght;

public:
	Rectangle();
	Rectangle(int lenght, int width);
	int getArea();
	~Rectangle(void);
};

