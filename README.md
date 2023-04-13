# univeristy-db

I write this project to excercise and understand advanced aspects of object-oriented programing and C++ syntax.

This project contains mechanisms like: abstarction, polymorphism, interfaces, smart pointers etc. The goal is to create a simple database program, capable
of managing data storeged in it.

This project contains 6 classes:
- main class for managing data called "DB"
- base class called "Person"
- 2 child classes "Student" and "Employee"
- 2 interfaces thanks to wich it is possible to distinguish child classes from each other when using polymorphism. Those weren't really needed - just wanted to use "interfaces" in my code to try it.


"Database" itself in reality is just a class (DB) with vector of smart pointers to Person class and a few functions for managing the data.
