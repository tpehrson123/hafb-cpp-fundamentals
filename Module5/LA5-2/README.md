# Learning Activities 5-2: Associative Containers and CSV Files
You can use this workspace/sandbox to add all your demo code related to this module. 

## Useful links for this activities:
Set:  
https://en.cppreference.com/w/cpp/container/set  

Map:  
https://en.cppreference.com/w/cpp/container/map   

CSV Files:  
https://github.com/awdeorio/csvstream



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
