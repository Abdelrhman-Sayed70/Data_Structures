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


## Pointer Arithmetic Operations
- `ptr++` will point to the next integer location in the memory [next 4 bytes]
- `++ *ptr` will increment the value at address ptr
```cpp
int val = 5;
int *ptr = &val;
cout << *ptr << "\n"; // 5
++ *ptr;
cout << *ptr << "\n"; // 6
cout << *(++ptr); // pointer to next int in memmory. value = garbage
```

## Pointer Assignment
- **`ptr1 = ptr2`** make ptr1 points to what ptr2 points to
- **`*ptr1 = *ptr2`** value assignment. make the val of p1 equal to val of p2

## Dynamic Variable
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

## Memory Management
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


## Delete Dynamic Pointer from Heap
Delete dynamic memory `5 in memory` not the pointer at stack so it still **`dangling pointer`**
```cpp
int *ptr = new int(5);
delete ptr;
```

