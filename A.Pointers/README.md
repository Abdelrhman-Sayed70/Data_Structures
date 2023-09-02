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
