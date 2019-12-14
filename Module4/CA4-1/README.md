# CA4-1: The Template HowMany Function

### Student name:

### Github account:
---

## Purpose:
It can be efficient to create a single function that can work with a 
variety of types. To accomplish this a template function (a pattern) can be 
created. 
When this template function is called, the compiler will automatically create 
a function that matches the type in the call. 

This is one form of code reuse.


## Skills:
This activity will help you practice the following skills that are essential to 
know for basic programming in `C++`:
- Define template functions
- Use template functions with a variety of built in data types
- Use template functions with user defined data types
- comparing floating point numbers for equality
- Git and Github

## Knowledge:
This lab will also help you to become familiar with the following important 
content knowledge in CS:  
  - generic programming
  - code reuse
  - limitations of floating point accuracy 
  - Source version control
  - Use unit testing to validate code


## Challenge Activity
For this activity we will write a function that receives a single value,
an array of values, and the number of valid values in the array. This function
counts how many of the single value are found in the array and returns the
count. 

For example, if the values sent to the function are:
- the value 18
- an array with values 12, 17, 22, 18, 33, 27, 18, 29, 18, 13
- a size of 10

The function would count how many 18s are in the array and return 3.

Because we want to be able 
to use this function with a variety of types, we will make it a 
template function.

Then we will test it using ints, strings, and Carton objects.

---
### Files to work on
We will be working in the CA4-1 folder of the Module4 repository. You can work 
on and modify the following files:
- `README.md`: Update the student name and github account.
- There will also be a header file `src/how_many.h` where we will write the 
   HowMany template function.
- There is a library `carton` that contains the carton class. The library 
  consists of these two files:
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

## Part 1: WRITE THE HOWMANY TEMPLATE FUNCTION (8 POINTS)

The `HowMany` function is a template function so that it can be used with a 
variety of types. It has three parameters, a single value, an array, and the 
number of valid elements currently being used in the array. It returns a 
count of how many times the value is in the array.

In the `how_many.h` file write the `HowMany` template function.
- add include guards to protect the header file from being included more
  than once
- add a global constant for the maximum size of the arrays, set this to 20
- add the template header that includes one variable type
- write a function named `HowMany` that has three parameters
  - a single value of the variable type
  - an array with elements of the the variable type
  - an integer the specifies how many valid values are being used in the array
- the function is to count how many times the single value is found in the 
  array and return that count  
- compare values using the == operator


---
---

## Part 2: TEST THE HOWMANY FUNCTION USING INTS (3 POINTS)

In the `main.cpp` file call the HowMany function with `int` parameters.
- declare and fill an array of type `int` 
- declare a variable to hold the size of the array (how many elements are 
  currently being used in the array)
- define a variable to catch the count value returned from the function
- call the `HowMany` function
- write the count returned from the function to the screen
- make sure it is the value expected


---
---

## Part 3: TEST THE HOWMANY FUNCTION USING STRINGS (3 POINTS)

In the `main.cpp` file call the HowMany function with `string` parameters.
- declare and fill an array of type `string` 
- declare a variable to hold the size of the array (how many elements are 
  currently being used in the array)
- define a variable to catch the count value returned from the function
- call the `HowMany` function
- write the count returned from the function to the screen
- make sure it is the value expected



---
---

## Part 4: OVERLOAD THE == OPERATOR IN THE CARTON CLASS (3 POINTS)

Before we can use the HowMany function with Carton objects, they need to work
with the `==` operator. 

In the `carton.h` file add the method declaration.
The method 
- returns a `bool`
- it is called `operator==`
- has one parameter
  - a const (no change is made to the parameter object)
  - of type Carton
  - passed by reference
- is a const method (no change is made to the calling object)


In the `carton.cpp` file add the method implementation.
- method is to return `true` when the calling object (left hand side) is
  `equal to` the parameter object (right hand side)
- method is to return `false` when the calling object (left hand side) is
  `not equal to` the parameter object (right hand side)   
- equal is defined by the volume of the Carton. Two Cartons that have the same
  volume are equal. These are floating point numbers to they may not be 
  exactly the same. Require that the volumes are the same up to a precision
  of .1
- add documentation



---
---


## Part 5: TEST THE HOWMANY FUNCTION USING CARTONS (3 POINTS)

In the `main.cpp` file call the HowMany function with `Carton` parameters.
- declare and fill an array of type `Carton` 
- declare a variable to hold the size of the array (how many elements are 
  currently being used in the array)
- define a variable to catch the count value returned from the function
- call the `HowMany` function
- write the count returned from the function to the screen
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
  PS C:\Users\Linda\C++ Fundamentals\C++ Fundamentals-module4\CA4-1\build> .\bin\ca_test.exe
  ===============================================================================
  All tests passed (14 assertions in 10 test cases)
```


### Validate Part 1

The unit tests will test the HowMany function with ints, strings, and 
Cartons.  Test your code with the tags `[int]`, `[string]`, and `[carton]`.

  ```bash
  $ .\ca_test.exe [int]
  $ .\ca_test.exe [string]
  $ .\ca_test.exe [carton]
  $ .\ca_test.exe [int], [string], [carton]
  ```

### Validate Part 2
Part 2 will not be tested by the unit tests. It will be manually reviewed.

### Validate Part 3
Part 3 will not be tested by the unit tests. It will be manually reviewed.

### Validate Part 4
Test your code with tag `[is_equal]`:
```bash
$ .\bin\ca_test.exe [is_equal]
```

### Validate Part 5
Part 5 will not be tested by the unit tests. It will be manually reviewed.

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
directory of your project. Uncomment `line 21` for CA4-1. 


```CMake
18: env: 
19:  - TEST_DIR=TO4-1  
20:  - TEST_DIR=TO4-2
21:  - TEST_DIR=CA4-1
22: # - TEST_DIR=TO4-3
23: # - TEST_DIR=CA4-2
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module4 repository to the CA4-1  assignment in Canvas.

---
