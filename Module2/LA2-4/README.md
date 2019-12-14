# Learning Activity 2-4: Defining and Using Classes
So far we have used classes that have already been defined and implemented. In this activity we will learn how to define and implement a class of our own.

There are videos that accompany this learning activity and demonstrate how to define and use classes.
It is recommended that you write the code as you follow along with the videos.

We will be working in the LA2-4 folder of the Module2 repository. We will be editing the following files:
- Our "driver" will be `src/main.cpp`.
- There will be a class library `carton` that contains the declaration and implementation of the carton class. The library consists of these two files:
  - `src/carton.cpp`
  - `src/carton.h`
- There will also be a class library `carton_fileio` that contains functions for reading and writing Carton objects from/to files. The library consists of these two files:
  - `src/carton_fileio.cpp`
  - `src/carton_fileio.h`
- In addition we will be using input and output files.

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

---

