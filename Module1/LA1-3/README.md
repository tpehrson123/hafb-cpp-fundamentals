# Module 1: Work Space
You can use this workspace/sandbox to add all your demo code related to this module. 

If you add a new file, either modify the `CMakeLists.txt` and compile your code using `cmake` 

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
