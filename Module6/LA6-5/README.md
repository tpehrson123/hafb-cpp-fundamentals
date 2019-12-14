# Learning Activity 6-5: A Vector of Pointers
One of the advantages of dynamic memory is that we don't need to know how much memory we will need at the time we are coding. A vector of pointers provides a mechanism for us to dynamically allocate only the memory we need. In this activity we will see how to use a vector of pointers to primitive data types and user defined data types to create doubles and Carton objects at run time.

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
