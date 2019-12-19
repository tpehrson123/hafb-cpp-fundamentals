# Learning Activities 5-1: Structures, Sequence Containers, and Debugger in VS Code
You can use this workspace/sandbox to add all your demo code related to this module. 

## Useful links for this activities:
Structures:  
https://en.cppreference.com/w/c/language/struct  
https://www.learncpp.com/cpp-tutorial/47-structs/  

Sequence Containers:   
https://en.cppreference.com/w/cpp/container  
https://en.cppreference.com/w/cpp/container/array  
https://en.cppreference.com/w/cpp/container/vector  

Debugger:  
https://code.visualstudio.com/docs/cpp/cpp-debug  



### How to compile

On Windows:
```bash
$ mkdir -p build
$ cd build
$ cmake .. -G "MinGW Makefiles"
$ cmake --build .
```
On Linux/Mac:
```bash
$ mkdir -p build
$ cd build
$ cmake ..
$ cmake --build .
```

or you can compile the code directly using `g++`
```bash
$ g++ -o main.out main.cpp
```

The compilation process will produce an executable file, which will be named `main.exe` on a Windows system and `main.out` on a UNIX one.

If you get no errors, run your code:
```bash
$ .\main.exe

# or 
 
$ ./main.out
```
