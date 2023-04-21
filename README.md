# univeristy-db

I write this project to excercise C++ syntax and advanced aspects of object-oriented programing, but also mechanisms like CMake or GIT itself.

This project contains mechanisms like: abstarction, polymorphism, interfaces and smart pointers. The goal was to create a simple database program, capable
of managing data storeged in it.

This project contains 6 classes:
- main class for managing data called "DB"
- base class called "Person"
- 2 child classes "Student" and "Employee"
- 2 interfaces thanks to wich it is possible to distinguish child classes from each other when using polymorphism. Those weren't really needed - just wanted to use "interfaces" in my code to try it.


"Database" itself is just a class (DB) with vector of smart pointers to Person class, and a few functions for managing the data.
