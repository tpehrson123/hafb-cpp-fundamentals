# TO3.2: Coordinate Points 

### Student name:

### Github account:
---

### Files to work on
You are required to work/modify the following files:
- `README.md`: Update the student name an github account.
- All the functions you write, will be part of the library `coordiantes`. The library consist of these two files: 
  - `src/coordinate.cpp` and `src/coordinate.h`. All the code will be under the `point` namespace.
- Our "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

---
## Task 1
Your have been given a basic class `Coordinate`. Your first task is to add some operator overloads. 

Add the following comparison operators:
-  `!= operator` overload to compare if the coordinates are not the same. It should return `boolean`.
-  `== operator` overload to compare if the coordinates are not the same. It should return `boolean`.

Sample test cases:
```c++
  Coordinates ogden( 41.2230, -111.9738);
  Coordinates ogden2(41.2230, -111.9738);
  Coordinates logan( 41.7370, -111.8338);
```

## Task 2
Next you to define the output operator:
-  `<< operator` to get a better output. 
for:
```c++
  Coordinates ogden( 41.2230, -111.9738);
  cout << ogden << endl
```
Sample Output:
```bash
"lat_: 41.223 long_: -111.974"
```
Note: Make sure you take care of the spaces between the `lat_:` and `long_:` and their corresponding values. 

To test this correctly, make sure you have fixed the following to 3, and only 3 decimal places
```c++
    os << std::fixed;
    os << std::setprecision(3);
```


## Task 3
Finally, you will add a function that converts the coordinate into GPS Notation in string form. 
```c++
std::string show_gps();
```
First, you will use the provided help function:
```c++
  void from_float_to_gps_(float number, int &degrees, int &minutes, int &seconds);
```
to convert either the latitude or longitude to `degrees, minutes, and seconds`. 

You job for this function is to convert the integer values of degrees, minutes, and seconds, to one string including the North, South, East, and West characters.

For example: 
```c++
  Coordinates ogden(41.2230, -111.970420);
  cout<<"Ogden's Location: " << ogden << endl;
  cout<< "GPS Format: " << ogden.show_gps() << endl;
```
Sample Output:
```bash
Ogden's Location: lat_: 41.223 long_: -111.97
GPS Format: 41°13'22" N  111°58'13" W
```
Tip 1: to display the degree symbol, use the string "\370".  
Tip 2: the `to_string()` function might help here. 



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
Test your code with tag `[part1]`:
```bash
# Run test with the tag 
$ .\bin\ca_test.exe [part1] -s
...
...
===============================================================================
All tests passed (4 assertions in 2 test cases)

```
---
### Validate Part 2
Test your code with tag `[part2]`:
```bash
# Run test with the tag 
$ .\bin\ca_test.exe [part2] -s
...
...
==============================================================================
All tests passed (2 assertions in 2 test cases)
```
Note: if your program fails this test, check you have the correct
format for the string. Check for missing spaces. 
### Validate Part 3
Test your code with tag `[part3]`:
```bash
# Run test with the tag 
$ .\bin\ca_test.exe [part3] -s
...
...
==============================================================================
All tests passed (5 assertions in 5 test cases)
```
Note: if your program fails this test, check you have the correct
format for the string. Check for missing spaces.  
Note 2: Make sure you do NOT have any `cout` in the `show_gps()` function 
--
### Publish your code
Before you push your code, you need to edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `TEST_DIR=TO3-2` line. 

```CMake
env: 
   - TEST_DIR=TO3-1
   - TEST_DIR=TO3-2
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