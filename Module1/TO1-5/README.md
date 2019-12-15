# TO1-5: ORGANIZING FUNCTIONS IN NAMESPACES

Write a function to read the name of a car for a lottery in a namespace based on numerical input. If the user inputs `1`, they win a Lamborghini, and if the user inputs `2`, they win a Porsche:

- Let's begin by creating a new library, `cars.cpp` and `cars.h`.
- Again, our code is organize in project form:
  ```
    .
    ├── CMakeLists.txt
    ├── .gitignore
    ├── externals
    │   └── catch2
    │       └── catch.hpp
    ├── README.md
    ├── src
    │   ├── CMakeLists.txt
    │   ├── cars.cpp
    │   ├── cars.h
    │   └── main.cpp
    └── tests
        ├── CMakeLists.txt
        └── age_test.cpp

  ```
- In our library, define the first namespace as `lamborghini` with an `HorsePower()` function that will return `759`. 
```c++
// cars.h

// Open a namespace called Lamborghini
namespace lamborghini 
{
    // Define a function named 'HorsePower' inside the namespace LamborghiniCar
    int HorsePower();
}  // The namespace 'Lamborghini' is closed here


// cars.cpp
int lamborghini::HorsePower() 
{ 
    return 759;
}
```

- Define the second namespace as `porsche` with an `HorsePower()` function as well. The function should return `700`.

- Finally, create a third function `HorsePower()` outside any namespace. This function should return `150`. 

```c++
// cars.h
int HorsePower();
```

- Now, test your functions in `main()`. This time around, DO NOT use `using namespace std;` in your program.  
```c++
  std::cout << "The lamborghini's horse power: " << lamborghini::HorsePower() << std::endl;
  std::cout << "The porsche's horse power: " << porsche::HorsePower() << std::endl;
  std::cout << "A regular car's horse power: " << HorsePower() << std::endl;
```
---

### Compile and run your code
Compile your code (see below) and run it.  
Sample Output:
```bash
$.\bin\ca.exe
The lamborghini's horse power: 759
The porsche's horse power: 700
A regular car's horse power: 120
```

### Validate your code
Once you are satisfied with your work, run our unit test file:
```bash
# Go to your build directory
$ cd build
# Clean all files
$ rm *
# Compile and build the code with USE_TEST=ON
$ cmake .. -G "MinGW Makefiles" -DUSE_TEST=ON
$ cmake --build .
```
For Linux/Mac:
```bash
$ cmake ..  -DUSE_TEST=ON
$ cmake --build .
```
```bash
  # For a detail information on the unit tests 
  $ .\bin\ca_test.exe [TO1-5] -s
...
===============================================================================
All tests passed (3 assertions in 3 test cases)
```
---
### Publish your code
Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---

### Notes to compile and run the code.

#### Using `CMake` by "hand" (recommended way):

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
$ .\bin\ca
```
#### Using `g++`:
```bash
$ g++ -o ca main.cpp fibo.cpp
# Now you can run your code
$ .\ca.exe
```