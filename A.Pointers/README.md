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


## Pointer Increment
```cpp
int *p = &val;
p++
```
- p will point to the next integer location in the memory [next 4 bytes]
