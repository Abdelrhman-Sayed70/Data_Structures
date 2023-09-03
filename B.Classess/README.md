# Classess

## `Access Modifiers`
- `private` cannot be accessed outside the class
- `public` can be accessed anywhere in the program
- Convention is to make the fields private and the methods public

## `Constructor`
- Method that describes how an instance of the class is constructed
- Used  to initialize the data of an object of a class
- Same name as class name
- Cannot return anything not even void
- If no constructor is explicitly defined the default [no-arg] constructor will be invoked automatically
- Class can have more than one constructor which is different in signature [method overloading]
- In C++ if you do not initialize the variables using a constructor they will take the default garbage value</br>
instead of Java which assigns default values for each variable `int -> 0` `String -> null` `float -> 0.0f`

## `Destructor`
- Special member function of a class which is executed when the object of the class goes out of scope or the program ends
- Used to delete dynamic pointers as C++ doesn't have a garbage collector so we should delete them ourselves
- It can neither return a value nor take any parameter `~ClassName(void){body}`
- Class has only ONE destructor




## Class Interface and Implementation
### Header File
- Interface `[.h file]` contains the declaration of the class, variables, and the prototype of methods
- Can contain more than one class definition


### CPP File
- Implementation `[.cpp file]` contains the implementation of the class methods
