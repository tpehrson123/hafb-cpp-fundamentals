# TO4-1: The Template MyMin Function

### Student name:

### Github account:
---

For this activity we will write a function that receives
two values and returns the smallest value. Because we want to be able 
to use this function with a variety of types, we will make it a 
template function.

Then we will test it using ints, doubles, and Carton objects.

---
### Files to work on
We will be working in the TO4-1 folder of the Module4 repository. You can work 
on and modify the following files:
- `README.md`: Update the student name and github account.
- There will also be a header file `src/min.h` where we will write the MyMin
- template function.
- There is a library `carton` that contains the carton class. The library 
- consists of these two files:
  - `src/carton.cpp`
  - `src/carton.h`
- Our "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file may result 
in the unit tests not passing.

---

#### How to compile and run the code. 

It is recommended that you do this often.

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
$ ./bin/ca
```

---
---

## Part 1: WRITE THE MYMIN TEMPLATE FUNCTION

The `MyMin` function is a template function so that it can be used with a 
variety of types. It has two parameters which are values that are of the 
variable type (type T). It returns one value of the variable type (type T) 
which is the smallest of the values sent to the function.

In the `min.h` file write is the `MyMin` function.
- the include guard is already in the min.h header file
- add the template header that includes one variable type
- add the function header that
  -  returns a value of type T (the variable type)
  -  is named MyMin
  -  receives two parameter, each of type T (the variable type) 
- add the function body
  - compare the two values sent as parameters using the < operator
  - return the value that is smaller


---
---

## Part 2: TEST THE MYMIN FUNCTION USING INTS

In the `main.cpp` file call the MyMin function with `int` parameters.
- define two variable of type `int` and give them values
- define a variable to catch the minimum value returned from the function (also
- of type `int`)
- call the `MyMin` function
- write the minimum value returned from the function to the screen
- make sure it is the value expected


---
---

## Part 3: TEST THE MYMIN FUNCTION USING DOUBLES

In the `main.cpp` file call the MyMin function with `double` parameters.
- define two variable of type `double` and give them values
- define a variable to catch the minimum value returned from the function (also
- of type `double`)
- call the `MyMin` function
- write the minimum value returned from the function to the screen
- make sure it is the value expected



---
---

## Part 4: OVERLOAD THE < OPERATOR IN THE CARTON CLASS

Before we can use the MyMin function with Carton objects, they need to work
with the `<` operator. 

In the `carton.h` file add the method declaration.
The method 
- returns a `bool`
- it is called `operator<`
- has one parameter
  - a const (no change is made to the parameter object)
  - of type Carton
  - passed by reference
- is a const method (no change is made to the calling object)


---
---


## Part 5: TEST THE MYMIN FUNCTION USING CARTONS

In the `main.cpp` file call the MyMin function with `Carton` parameters.
- define two variable of type `Carton` and give them values
- define a variable to catch the minimum value returned from the function (also
- of type `Carton`)
- call the `MyMin` function
- write the minimum value returned from the function to the screen
- make sure it is the value expected


---
---

## Validate your code
Once you are satisfied with your work, run the unit test file.


First, set the testing to ON


```bash
# Go to your build directory
$ cd build
# Clean all files
$ rm *
# Compile and build the code with USE_TEST=ON
$ cmake .. -G "MinGW Makefiles" -D USE_TEST=ON
$ cmake --build .
```
For Linux/Mac:
```bash
$ cmake ..  -D USE_TEST=ON
$ cmake --build .
```
 
 
Then run the unit tests. The format for running the tests is:


```bash
# Run tests using no tag designation - this will run all tests
$ .\bin\ca_test.exe

# Run tests with a single tag
$ .\bin\ca_test.exe [tag-name]

# Run tests with multiple tags
$ .\bin\ca_test.exe [tag1],[tag2]

# To list all available tags
$ .\bin\ca_test.exe -t

# Run tests with more information
$ .\bin\ca_test.exe -s

# Run tests with more information about a single tag
$ .\bin\ca_test.exe -s [tag-name]
#or
$ .\bin\ca_test.exe [tag-name] -s 

# For summary information in compact mode
$ .\bin\ca_test.exe -s -r compact

# Using ctest
$ ctest
```
The results will look something like this:

```bash
  PS C:\Users\Linda\C++ Fundamentals\C++ Fundamentals-module2\TO4-1\build> .\bin\ca_test.exe
  ===============================================================================
  All tests passed (8 assertions in 4 test cases)
```


### Validate Part 1

The testing starts with Part 2.

---
---
### Validate Part 2
Test your code with tag `[int]`:
 
```bash
$ .\bin\ca_test.exe [int]
```

### Validate Part 3
  Test your code with tag `[double]`:
  ```bash
  $ .\ca_test.exe [double]
  ```
### Validate Part 4
Test your code with tag `[less_than]`:
```bash
$ .\bin\ca_test.exe [less_than]
```

### Validate Part 5
Test your code with tag `[carton]`:
```bash
$ .\bin\ca_test.exe [carton] 
```

### Finally run ALL tests:
```bash
$ .\bin\ca_test.exe
```

---
---
### Publish your code
Now you are ready to publish and test the code. At this point, all the 
tests are expected to pass. 

The next step is to push the code to GitHub. Before you push your code, edit 
the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `line 19` for TO4-1. 


```CMake
18: env: 
19:  - TEST_DIR=TO4-1  
20: # - TEST_DIR=TO4-2
21: # - TEST_DIR=CA4-1
22: # - TEST_DIR=TO4-3
23: # - TEST_DIR=CA4-2
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module4 repository to the TO4-1 assignment in Canvas.

---
