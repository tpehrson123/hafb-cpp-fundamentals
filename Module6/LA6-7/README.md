# Learning Activity 6-7: Polymorphism
It is possible to have an array of base class types and subclass types in the same array. However, they behave like base class objects. To get subclass objects to behave like themselves we need to use polymorphism. Polymorphism is when each subclass uses the functionality that is specific to that subclass.

To get polymorphism we need to do two things. 

1. We need to use an array of base class pointers.
2. The method in the base class must be set to virtual.

In this activity we will make the changes needed to get polymorphism from an array of RoundShape pointers. Also, we will see how to create a pure virtual function and create an abstract base class.

There are videos that introduce this topic. It is recommended that you write 
the code as you follow along with the video.

We will be writing code in the main.cpp file.

---
---


To see how the classes are related, consider the following UML class diagram. This is before the Volume method is addeded to the RoundShape class.

![UML class diagram of the PayrollData base class and subclasses](images/cs1410_la6-6_class_diagram_start.png)

---
---


This is updated version of the UML class diagram after the pure virtual version of the Volume method is addeded to the RoundShape class.

![UML class diagram of the PayrollData base class and subclasses](images/cs1410_la6-6_class_diagram.png)

---
---
#### How to compile and run the code. 

It is recommended that you do this often.

For Windows:
```bash
$ mkdir build
$ cd build
$ cmake .. -G "MinGW Makefiles"
$ cmake --build .
# Now you can run your code
$ .\bin\ca.exe
```
For Linux/Mac:
```bash
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
# Now you can run your code
$ ./bin/ca
```


