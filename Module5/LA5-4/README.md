# Learning Activities 5-4: Lambdas, Counting, Finding, and Sorting
You can use this workspace/sandbox to add all your demo code related to this module. 

## Useful links for this activities:
Lambdas:  
https://en.cppreference.com/w/cpp/language/lambda 

Read-Only Algorithms:  
https://en.cppreference.com/w/cpp/algorithm 

Mutating or Modifying Algorithms:  
https://en.cppreference.com/w/cpp/numeric/random

Sorting Algorithms:  
https://en.cppreference.com/w/cpp/algorithm/sort




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
