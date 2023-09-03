# Dynamic Arrays
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

## `Expanding Array Size`
```cpp

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
**Another Solution**
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
	Person person1("gaber", NULL);
	Person person2("sayed", &person1);
	Person person3("abdo", &person2);

	cout << "parent of " << person3.name << ": " << person3.parent->name << "\n";
	cout << "grand father of " << person3.name << ": " << person3.parent->parent->name;
}
```
