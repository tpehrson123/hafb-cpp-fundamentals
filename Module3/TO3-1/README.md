# TA03.1: Adding an overload operators to the Distance Class 

### Student name:

### Github account:
---
In the following activity, we will add to the `Distance` class a few features like some extra "getters" and some operator overloads.

We will continue the work from the library you created in [LA3-3](../LA3-3/README.md). 


---
### Files to work on
You are required to work/modify the following files:
- `README.md`: Update the student name an github account.
- All the functions you write, will be part of the library `distance`. The library consist of these two files: 
  - `src/distance.cpp`
  - `src/distance.h`
- Your "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

---
## Task 1
Make sure you copy over the code from your `distance` library as a starting point. 

Your first task is to add two getter methods to retrieve the feet and inches from the `Distance` class.
```cpp
int feet() const;
float inches() const;
```
To test your code, create some instances of the `Distance` class without any parameters (set default values to zero), and another constructor that takes two parameters. 
```cpp
Distance dist1;
Distance dist2(34, 5.7);   //define distances
```
In main test your code, and make sure you get the expected values back. 


## Task 2
To the `Distance` class, add an overload `- operator` that subtracts two distances. It should allow statements like: 
```cpp
dist3 = dist1 - dist2;
```
You could assume that the operator will never be used to subtract a larger number from a smaller one (that is, negative distances are not allowed), but you should take into account the inches. For example
`(12',6.6")  -  (3',10.8") = (8',4.2")`

Finally, make sure you add another method to update your `Distance` class variables:
```cpp
void update_distance(int ft, float in); 
```

Test your code in main.
---


## Validate your code
Once you are satisfied with your work, run our unit test file.
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
 
### Validate Part 1
Test your code with tag `[start]`:
```bash
# Run test with the tag 
$ .\bin\ca_test.exe [start] -s
```
---
### Validate Part 2
Test your code with tag `[sub]`:
```bash
# Run test with the tag 
$ .\bin\ca_test.exe [sub] -s
```

### Validate Part 3
Test your code with tag `[update]`:
```bash
# Run test with the tag 
$ .\bin\ca_test.exe [update] -s
```

--
### Publish your code
Before you push your code, you need to edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `TEST_DIR=TO3-1` line. 

```CMake
env: 
   - TEST_DIR=TO3-1
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---


#### Notes to compile and run the code.

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
#### Notes to build a task in VS Code

- Press F1: Type Build Task