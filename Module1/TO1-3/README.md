# TO1-3: USING LOCAL AND GLOBAL VARIABLES IN A FIBONACCI SEQUENCE
Write a library with a function that `returns` the 10th number in a Fibonacci sequence.

**Note:** The nth Fibonacci number is defined as the sum of the n-1th and the n-2th, with the first number in the sequence being 0 and the second being 1.

Example:
```
10th Fibonacci number = 8th Fibonacci number + 9th Fibonacci number
```
- Let's begin by creating a new library, `fibo.cpp` and `fibo.h`.

- This time around, and from now on, we will organize our project in project form:
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
    │   ├── fibo.cpp
    │   ├── fibo.h
    │   └── main.cpp
    └── tests
        ├── CMakeLists.txt
        └── fibo_test.cpp

  ```
    - `src` folder: all our code will go here. This is basically the only folder you will work on.
    - `externals` folder (DO NOT MODIFY): contains our unit test library
    - `test` folder (DO NOT MODIFY): contains our unit code
    - The `.gitignore` hidden file instructs git to ignore our build folder and anything else we do not want to track.
    - The `.travis.yml` file controls which test `travis` is validating for us. As you complete the different TO and CA activities, you will modify this file (see below). This is what I will use to verify your code.  

-  In your `fibo.h` file:
   -  Declare a function `unsigned int GetTenthFibonacci()` in our `fibo.h`. Note: Do not forget to add the file [header guards](https://google.github.io/styleguide/cppguide.html#Header_Files).  

    ```c++
    unsigned int GetTenthFibonacci()
    ```

-  In your `fibo.cpp` file:
   - We want to use the best practice of giving a name and a meaning to values, so instead of using 10 in the code, we are going to define a `const` global variable, named `kPosition`.
    ```c++
    const int kPosition = 10;
    const int kAlreadyComputed = 3;
    ```
   - Implement the function. We will also use two local variables in the function to remember the `n-1th` and the `n-2th` number:

   - Within the function, include three local variables, named n_1, n_2, and current of type int, as shown here:
    ```c++
    unsigned int n_1 = 1;
    unsigned int n_2 = 0;
    unsigned int current = n_1 + n_2;
    ```
   
   - Let's create a `for` loop to generate the remaining Fibonacci numbers until we reach the 10th, using the global variables we defined previously as starting and ending indices:
    ```c++
    for(auto i = kAlreadyComputed; i < position; ++i)
    {
        n_2 = n_1;
        n_1 = current;
        current = n_1 + n_2;
    }
    ```
   - Now, after the previous `for` loop, add the following print statement to print the last value stored in the `current` variable:

    ```c++
    return current;
    ```

* In the `main()` function, call `GetTenthFibonacci()` and print the value of the 10th element of the Fibonacci sequence:
```c++
int main() 
{
    cout << "Computing the 10th Fibonacci number: " << GetTenthFibonacci() << endl;
    
    return 0;
}
```

### Validate your code
Once you are satisfied with your work, run our unit test file with the `TO1-3` tag to validate your code:
```bash
  # For a detail information on the unit tests 
  $ .\bin\ca_test.exe [TO1-3] -s
```
Your output should be something like this: 
```bash
............................................................................

fibo_test.cpp:14: PASSED:
  REQUIRE( GetTenthFibonacci() == 144 )
with expansion:
  144 == 144
with message:
  TO Activity 3 Points

===============================================================================
All tests passed (1 assertion in 1 test case)
```
---
### Publish your code
Before you push your code, you need to edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Make sure you uncomment `line 19` for TO1-3 activity. 

```CMake
18: env: 
19:  - TEST_DIR=TO1-3
20:  # - TEST_DIR=TO1-4
21:  # - TEST_DIR=TO1-5
22:  # - TEST_DIR=TO1-6
23:  # - TEST_DIR=CA1-1
24:  # - TEST_DIR=CA1-2
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