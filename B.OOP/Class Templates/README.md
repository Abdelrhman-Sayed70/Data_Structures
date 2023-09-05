# Class Templates
- Some algorithms are type-independent (the logic does not depend on the data type of items processed).
- It’s preferable to write the code once rather than recode it for each different type.
- Achieved by using Templates: Function Template, Class Templates
- In the main function include class name .cpp not .h 

```h
#pragma once

template<class T>
class Test
{
private:
	T val;

public:
	Test(T);
	T getVal();
};
```
```cpp
#include "Test.h"

template<class T>
T Test<T>::getVal() {
	return this->val;
}

template<class T>
Test<T>::Test(T val) {
	this->val = val;
}
```
```cpp
#include<iostream>
#include"Test.cpp"
using namespace std;
int main()
{
	Test<string>t("csd");
	cout << t.getVal();
}
```
