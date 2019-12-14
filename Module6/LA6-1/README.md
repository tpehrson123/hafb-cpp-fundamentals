# Learning Activity 6-1: Intro to Pointers
So far all the memory we have used has been created at compile time. This is called static memory. This means we have to know all our memory needs at the time we are writing the program. Sometimes our memory needs vary. One day we may need lots of memory and another time we may only need a little memory. There are some advantages from being able to determine memory needs at run time. When all the memory is static we do not have this flexibility.

In this activity we will begin to learn about pointers. Pointers are a data type that stores an address. Being able to work with pointers will allow us to create dynamic memory.

There are videos that demonstrate how to declare and use pointers. It is recommended that you write the code as you follow along with 
the video.

We will be writing code in the main.cpp file.

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
