# Learning Activity 6-2: Dynamic Memory and the New Operator
Dynamic memory is memory that is not allocated until run time. Since we can 
allocate memory while the program is running we can use as much or as little 
memory as we need.

Now that we know a little about pointers we can learn about dynamic memory. 
In this activity we will see how to create memory at run time.

There are videos that demonstrate how to use pointers and dynamically 
allocate memory. It is recommended that you write the code as you follow 
along with 
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
