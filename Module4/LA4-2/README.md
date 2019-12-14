# Learning Activity 4-2: The Template MyMax Function
In this activity we will develop a template max function. Then we will 
call the function using ints, doubles, and Carton objects. To get this 
function to work with Carton objects we will overload the > operator in
the Carton class.

There are videos that demonstrate how to create and use the max template 
function. It is recommended that you write the code as you follow along with 
the video.

We will be writing code in the main.cpp, max.h, carton.h and carton.cpp files. 
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
