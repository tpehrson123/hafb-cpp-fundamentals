# TO1-2: CALLING FUNCTION FROM MAIN()

- Create a `library` and move the function `int FactorMod3()` to it. 
A library in C++ typically consist of two or more files. 
- A `header` file (`factor.h`). This file contains the function prototypes (the signature or rules of your functions).
- A `source` file (`factor.cpp`). This is the file where the function definitions are coded. 

Let's begin in our header file defining our function prototype.  
Note: Do not forget to add your header guards:
```c++
// factor.h
#ifndef FACTOR_H_
#define FACTOR_H_

int FactorMod3();

#endif /* !FACTOR_H_ */
```

- Now, in our source file, `factor.cpp`, lets define the function. 
```c++
// factor.cpp
#include "log.h"  // local header file

int FactorMod3();
{
    // Algorithm here
}
```
- Change the `main.cpp` file to include `factor.h` and call `log()` in the `main()` function:
```c++
#include <iostream>
#include "log.h"  // local header file
using namespace std;

int main() 
{
    int result = 0;
    result = FactorMod3();
    cout << "Result is: " << result << endl;
    return 0;
}
```


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