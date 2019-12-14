# Learning Activity 6-6: Using Inheritance
Sometimes classes have some things in common with other classes. When two or more classes have some of the same data members and methods it can be efficient to work with them together. To do this we will use inheritance. Inheritance allows us to only code the common parts once but has the flexibility to allow differences.

In this activity we will code four classes: RoundShape, Sphere, Cylinder, and Cone. These shapes have some things in common and some things that are different. We will use inheritance to share the common parts.

There are videos that introduce this topic. It is recommended that you write 
the code as you follow along with the video.

We will be writing code in the main.cpp file.

---
---


To see how the classes are related, consider the following UML class diagram.

![UML class diagram of the PayrollData base class and subclasses](images/cs1410_la6-6_class_diagram_start.png)

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
