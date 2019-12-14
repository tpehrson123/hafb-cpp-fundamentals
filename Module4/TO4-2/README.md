# TO4-2: The Template MinInArray Function

### Student name:

### Github account:
---

For this activity we will write a function that receives
an array and returns the smallest value in the array. Because we want to be able 
to use this function with a variety of types, we will make it a 
template function.

Then we will test it using ints, doubles, and Carton objects.

---
### Files to work on
We will be working in the TO4-2 folder of the Module4 repository. You can work 
on and modify the following files:
- `README.md`: Update the student name and github account.
- There will also be a header file `src/min_array.h` where we will write the 
   MinInArray template function.
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

## Part 1: WRITE THE MININARRAY TEMPLATE FUNCTION

The `MinInArray` function is a template function so that it can be used with a 
variety of types. It has two parameters. The first is an array of the 
variable type (type T). The second is an int that specifies the number of
valid elements currently being used in the array. It returns one value of 
the variable type (type T) which is the smallest of the values in the array.

In the `min_array.h` file write the `MinInArray` function.
- the include guard is already in the min_array.h header file
- there is already a global constant for the maximum size of the array
- add the template header that includes one variable type
- add the function header that
  -  returns a value of type T (the variable type)
  -  is named MinInArray
  -  receives two parameters
     -  an array of type T (the variable type) 
        -  pass this array by reference
        -  make it a const parameter
     -  an int that specifies the number of valid elements currently being 
        used in the array  
- add the function body
  - loop through the array and return the smallest value
  - compare values using the < operator


---
---

## Part 2: TEST THE MININARRAY FUNCTION USING INTS

In the `main.cpp` file call the MinInArray function with `int` parameters.
- there is already an array of type `int` 
- there is already a variable that defines the current size of the array
- define a variable to catch the minimum value returned from the function (also
  of type `int`)
- call the `MinInArray` function
- write the minimum value returned from the function to the screen
- make sure it is the value expected


---
---

## Part 3: TEST THE MININARRAY FUNCTION USING DOUBLES

In the `main.cpp` file call the MinInArray function with `int` parameters.
- there is already an array of type `double` 
- there is already a variable that defines the current size of the array
- define a variable to catch the minimum value returned from the function (also
  of type `double`)
- call the `MinInArray` function
- write the minimum value returned from the function to the screen
- make sure it is the value expected



---
---

## Part 4: OVERLOAD THE < OPERATOR IN THE CARTON CLASS

Before we can use the MinInArray function with Carton objects, they need to work
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


In the `carton.cpp` file add the method implementation.
- method is to return `true` when the calling object (left hand side) is
  smaller than the parameter object (right hand side)
- method is to return `false` when the calling object (left hand side) is
  `not` smaller than the parameter object (right hand side)   
- smaller is defined by the volume of the Carton. A Carton with a 
  smaller volume is less than a Carton with a larger volume.
- add documentation



---
---


## Part 5: TEST THE MININARRAY FUNCTION USING CARTONS

In the `main.cpp` file call the MinInArray function with `Carton` parameters.
- there is already an array of type `Carton` 
- there is already a variable that defines the current size of the array
- define a variable to catch the minimum value returned from the function (also
  of type `Carton`)
- call the `MinInArray` function
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
  PS C:\Users\Linda\C++ Fundamentals\C++ Fundamentals-module2\TO4-2\build> .\bin\ca_test.exe
  ===============================================================================
  All tests passed (11 assertions in 10 test cases)
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
directory of your project. Uncomment `line 20` for TO4-2. 


```CMake
18: env: 
19:  - TEST_DIR=TO4-1  
20:  - TEST_DIR=TO4-2
21: # - TEST_DIR=CA4-1
22: # - TEST_DIR=TO4-3
23: # - TEST_DIR=CA4-2
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module4 repository to the TO4-2 assignment in Canvas.

---
