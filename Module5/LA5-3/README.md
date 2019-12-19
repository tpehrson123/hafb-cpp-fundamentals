# Learning Activities 5-3: Unconventional Containers and Iterators
You can use this workspace/sandbox to add all your demo code related to this module. 

## Useful links for this activities:
Variant:  
https://en.cppreference.com/w/cpp/header/variant 

Iterators:
https://en.cppreference.com/w/cpp/iterator   


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
