# Learning Activity 4-4: The Template Point Class
In this activity we will develop a template class. A template class is a 
pattern of what a class is to be. It can be instantiated with a variety of 
types. This allows us to code a single class pattern and have it be used 
to create a new class for each type that uses it.

In this activity we will create and use the Point class. There are 
videos that demonstrate how to create and use the Point class.  
It is recommended that you write the code 
as you follow along with the videos.

We will be writing code in the main.cpp and point.h files. 
These files can be found in the src folder.


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
