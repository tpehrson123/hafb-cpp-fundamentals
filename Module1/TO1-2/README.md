# TO1-2: CALLING FUNCTION FROM MAIN()
In our application, we want to log errors. To do so, we have to specify a function called `log()`, which prints `Error!` to the standard output when called.

Let's create a function that can be called from several files, and put it in a different header file that can be included:

- Create a file named `log.h` and declare a function called `log()` with no parameters and that returns nothing:

```c++
void log();
```
Do not forget to add your header guards:
```c++
#ifndef LOG_H_
#define LOG_H_

void log();

#endif /* !LOG_H_ */
```

- Now, let's create a new file, `log.cpp`, where we define the `log()` function to print to the standard output:
```c++
#include <iostream>
using namespace std;
// This is where cout and endl are defined

void log() 
{
    cout << "Error!" << endl;
}
```
- Change the `main.cpp` file to include `log.h` and call `log()` in the `main()` function:
```c++
#include "log.h"  // local header file

int main() 
{
    log();

    return 0;
}
```
- Using the terminal, compile the two files and run the executable (see below). You will see that the message **Error!** is printed when we execute it.

---

#### Notes to compile and run the code.

##### Using g++:
```bash
$ g++ -o main main.cpp log.cpp
# Now you can run your code
$ .\main.exe
```

##### Using CMake:

For Windows:
```bash
$ mkdir build
$ cd build
$ cmake .. -G "MinGW Makefiles"
$ cmake --build .
# Now you can run your code
$ .\main.exe
```
For Linux/Mac:
```bash
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
# Now you can run your code
$ .\main
```