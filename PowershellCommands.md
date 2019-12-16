## C++ Environment in Windows
- VSCode  https://code.visualstudio.com/   // code editor
- git   https://git-scm.com/        // for source control
- cmake    https://cmake.org/     // to work with project
- g++ (mingw) http://www.mingw.org/  // compiler for windows. You need to add binaries to PATH env. variable
- github.com  http://github.com  // for cloud service

## Terminal Commands 
Note: ($ means terminal prompt):
```bash
$   ls          # list folder 
$ cd  <dest>  	# change directories
$ cd   ..		# .. parent directory 
$ pwd           # show present working directory
$ rm <name>     # remove/delete file/directory
```
## File System
``` bash
.    # (one dot) present working directory
..   # (two dots) parent directory
```
## C++ Basics
- File extension: `.cpp`
- https://en.cppreference.com/w/  C++ reference

## g++ Compiler for 1 file
```bash
# To compile
# -o for output file name
$ g++ main.cpp -o main
# To run
$ ./main.exe

- g++ (mingw) http:\\www.ming.org\
compiler for windows.
- Add c:\MingGW\bin\ to path env
variable
 - mingw32.make // use by cmake
 - mingw32-gcc-g++  // c+

```

## g++ Compiler for 1 file
   For example, if you have a library under the 'functions.cpp' and
   'functions.h' files, and you have a driver under 'run_funtions.cpp' you
   need to compile as follows:
   ```bash
   # To compile, list ALL source (cpp) files
   # - o for output file name
   $ g++ functions.cpp run_functions.cpp -o run_functions
   # To run
   $ .\run_functions.exe

```

### C++ File Template
```cpp
#include <iostream>
using namespace std;

int main()
{
    return 0;
}
```
## Plugins and Doxygen documentation

// Add C/C++ Intellisense
// Add Code Spell Extension 
// Add Doxygen Documentation Generator

  - C/C++ Intellisense
  - Code Spell Extension
  - Doxygen Documenation Generator
  - Markdown All in One
  - CMake
  - CMake Tools


```cpp
To generate Doxygen documentation: 
// Run /** and <Enter>
```