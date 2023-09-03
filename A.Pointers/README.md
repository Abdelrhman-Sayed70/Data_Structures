# Pointers
- `pointer` is a memory address of a variable
- `pointer variable` holds a pointer value
- `*` sign is used to declare a pointer `int *ptr;` creates a pointer that will point to an int variable
- `&` sign is used to get the address of a variable `int *ptr = &val;`
- `*` sign is used to get the value of a pointer `cout << *ptr;`

```cpp
int val = 5;
int* ptr;
ptr = &val;
cout << *ptr; // 5
```
```cpp
int* p1, * p2, v1, v2;
p1 = &v1;
p2 = &v2;
v1 = 7;
cout << "v1: " << v1 << " val at p1: " << *p1 << " p1 address: " << p1 << "\n";
cout << "v2: " << v2 << " val at p2: " << *p2 << " p2 address: " << p2 << "\n";
```
```
v1: 7 val at p1: 7 p1 address: 000000634B0FFC14
v2: -858993460 val at p2: -858993460 p2 address: 000000634B0FFC34 [v2 assigned to garbage value]
```
```cpp
int v, w;
int* p;
p = &v;
v = 3;
*p = 7;
p = &w;
*p = 12;
cout << v << " " << w; // 7 12
```


## `Pointer Arithmetic Operations`
- `ptr++` pointer moves to the next integer location in the memory [next 4 bytes]
- `++ *ptr` will increment the value at address ptr
- `* ++ptr` pointer will point to the next int location then **`dereference`** the value of the pointer
```cpp
int val = 5;
int *ptr = &val;
cout << *ptr << "\n"; // 5
++ *ptr;
cout << *ptr << "\n"; // 6
cout << *(++ptr); // pointer to next int in memmory. value = garbage
```

## `Pointer Assignment`
- **`ptr1 = ptr2`** make ptr1 points to what ptr2 points to
- **`*ptr1 = *ptr2`** value assignment. make the val of p1 equal to val of p2

## `Dynamic Variable`
- **`int *ptr = new int;`**
- **`int *ptr = new int(5);`** initialize the pointer value
  
**Create a new nameless variable in memory and make ptr points to it**
```cpp
int *p1, *p2;
p1 = new int;
*p1 = 42;
p2 = p1;
cout << "*p1: " << *p1 << ", *p2: " << p2 << "\n"; // 42 42
*p2 = 53;
cout << "*p1: " << *p1 << ", *p2: " << p2 << "\n"; // 53 53
p1 = new int;
*p1 = 88;
cout << "*p1: " << *p1 << ", *p2: " << p2 << "\n"; // 88 53
```

## `Memory Management`
![image](https://github.com/Abdelrhman-Sayed70/Data_Structures/assets/99830416/810e9e05-9fe6-4f41-bb96-d3a122055f38)
- **Text** segment contains `executable instructions`
- **Initialized Data** segment contains `global variable` `static variables` that are initialized by the programmer
- **Uninitialized Data** segment contains `global variable` `static variables` that are NOT initialized in the source code

### Stack
- Contains all variables declared in functions including `main()`
- When the function call is over, the memory for the variables is deallocated

### Heap [Free Store]
- Reserved for dynamically allocated variables [new]
- `new` operation fails when heap is complete


## `Delete Dynamic Pointer from Heap`
delete ptr destroys dynamic memory but ptr still points there! Called **`dangling pointer`** so make it points to null
```cpp
int *ptr = new int(5);
delete ptr;
ptr = NULL;
```

## `Pointers & Array`
**arr name is a [const] pointer that points to the first location of an array so we cannot change the address of the array**
```cpp
int numbers[5];
int *p;
p = numbers;
*p = 1;
p++;
*p = 2;
p = &numbers[2];
*p = 3;
p = numbers + 3;
*p = 4;
p = numbers;
*(p + 4) = 5;
for(auto it : numbers)
    cout << it << " "; // 1 2 3 4 5
```
**Indexing pointer. Actually, it takes the address of the pointer and adds to it the index value but does not move the pointer** </br>
`ptr[0] = ptr + 0` `ptr[1] = ptr + 1` `ptr[2] = ptr + 2`
```cpp
int numbers[5] = {1, 2, 3, 4, 5};
int *p = numbers + 1; // points to numbers [1] = 2
cout << *p << "\n";
cout << p[0]; // indexing pointer p + 0 = p -> *p = 2
```

**Printing Array Elements**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
for(int i = 0; i < 5; i++){
    cout << arr[i] << " ";
    cout << *ptr++ << " ";
    // or cout << ptr[i] << " ";
    // or cout << *(ptr + i) << " ";
    cout << "\n";
}
```


## `Dynamic Arrays`
- Size not specified at program design time
- Determined while the program runs
- Can grow and shrink as needed•
- Initially initialized with garbage values of the size instead of the static array which initially initialized by zeroes
```cpp
int sz;
cin >> sz;
int *arr = new int[sz];   
```
**Can be initialized with zeroes**
```cpp
int *arr = new int[sz]();
```
**delete the ptr**
```cpp
delete []arr;
arr = NULL 
```

## Exercise
- Use pointers to represent a family tree.
- We need to know each person’s name as well as who their parent is.

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Person {
	string name;
	Person* parent;

	Person(){}

	Person(string name, Person* parent) {
		this->name = name;
		this->parent = parent;
	}
};
int main()
{
	Person *person1 = new Person("gaber", NULL);
	Person *person2 = new Person("sayed", person1);
	Person* person3 = new Person("abdo", person2);

	cout << person3->parent->name; // sayed
}
```

