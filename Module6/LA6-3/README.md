# Learning Activity 6-3: Dynamically Allocate Arrays
In this activity we will see how to dynamically allocate entire arrays. Since 
these arrays are being created at run time, we do not need to know what size
they are when we are writing the code. The size of the array can be 
determined at run time. The size might be entered by the user or read from
a file.

There are videos that introduce this topic. It is recommended that you write 
the code as you follow along with the video.

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
