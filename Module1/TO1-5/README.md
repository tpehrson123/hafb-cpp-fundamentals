# TO1-5: ORGANIZING FUNCTIONS IN NAMESPACES

Write a function to read the name of a car for a lottery in a namespace based on numerical input. If the user inputs `1`, they win a Lamborghini, and if the user inputs `2`, they win a Porsche:

- Let's begin by creating a new library, `cars.cpp` and `cars.h`.
- Again, our code is organize in project form:
  ```
    .
    ├── CMakeLists.txt
    ├── .gitignore
    ├── .travis.yml
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
  std::cout << "The porshe's horse power: " << porshe::HorsePower() << std::endl;
  std::cout << "A regular car's horse power: " << HorsePower() << std::endl;
```
---

### Compile and run your code
Compile your code (see below) and run it.  
Sample Output:
```bash
$.\bin\ca.exe
The lamborghini's horse power: 759
The porshe's horse power: 700
A regular car's horse power: 120
```

### Validate your code
Once you are satisfied with your work, run our unit test file with the `TO1-5` tag to validate your code:
```bash
  # For a detail information on the unit tests 
  $ .\bin\ca_test.exe [TO1-5] -s
...
===============================================================================
All tests passed (3 assertions in 3 test cases)
```
---
### Publish your code
Before you push your code, you need to edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Make sure you uncomment `line 21` for TO1-5 activity. 

```CMake
18: env: 
19:  - TEST_DIR=TO1-3
20:  - TEST_DIR=TO1-4
21:  - TEST_DIR=TO1-5
22:  # - TEST_DIR=CA1-1
23:  # - TEST_DIR=CA1-2
```

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