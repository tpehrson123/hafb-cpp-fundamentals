# TO1-3: USING LOCAL AND GLOBAL VARIABLES IN A FIBONACCI SEQUENCE
Write a `library` with a function that `returns` the nth number in a Fibonacci sequence.

**Note:** The nth Fibonacci number is defined as the sum of the n-1th and the n-2th, with the first number in the sequence being 0 and the second being 1.

Example:
```
10th Fibonacci number = 8th Fibonacci number + 9th Fibonacci number
```
- Let's begin by creating a new library. Our libray will consist of these two files `fibo.cpp` and `fibo.h`.

- This time around, and from now on, we will organize our code in project form:
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

-  In your `fibo.h` file declare a function with the following characteristics: 
   -  Takes `one `integer argument/parameter as input parameter `GetNthFibonacci(int nth)`.
   -  Returns the `nth` Fibo number using index notation. The return value comes as an integer variable `int GetNthFibonacci(int nth)`.
   -  Note: Do not forget to add the file [header guards](https://google.github.io/styleguide/cppguide.html#Header_Files).  
   All together, our function prototype looks like this:
    ```c++
    // Header guards here
    
    int GetNthFibonacci(int nth);
    
    // Header guards here
    ```

-  In your source `fibo.cpp` file:
  - Define two constant variables for fixed values. 
    ```c++
    const int kValue = 1;
    const int kAlreadyComputed = 2;
    ```
   - Implement the function. We will also use two local variables in the function to remember the `n-1th` and the `n-2th` number:

   - Within the function, include three local variables, named n_1, n_2, and current of type int, as shown here:
    ```c++
    int GetNthFibonacci(int nth)
    {
      int n_1 = 0, n_2 = 1, current;
      // algorithm here
      if(nth <= kValue)
      {
        return nth;
      }
      else
      {
        // loop here ...
      }
     
      return current;
    }
    ```
   
   - Let's create a `for` loop to generate the remaining Fibonacci numbers until we reach the 10th, using the global variables we defined previously as starting and ending indices:
    ```c++
    for(int i = kAlreadyComputed; i <= nth; ++i)
    {
        current = n_1 + n_2;   // calculate the new value
        n_1 = n_2;            // get the previous value
        n_2 = current;        // get the new calculated number
    }
    ```
   - Now, after the previous `for` loop, add the following print statement to print the last value stored in the `current` variable:

    ```c++
    return n_2;
    ```

* In the `main()` function, call `GetNthFibonacci()` and print the value of the 10th element of the Fibonacci sequence:
```c++
int main() 
{
    int num = 4;
    cout << "Computing the " << num << " Fibonacci number: " << GetNthFibonacci(num) << endl;
    
    return 0;
}
```
---
### Notes to compile and run the code.

For Windows:
```bash
$ mkdir -p build
$ cd build
$ cmake .. -G "MinGW Makefiles"
$ cmake --build .
# Now you can run your code
$ ./bin/ca.exe
```
For Linux/Mac:
```bash
$ mkdir -p build
$ cd build
$ cmake ..
$ cmake --build .
# Now you can run your code
$ ./bin/ca
```

---
## Validate your code
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