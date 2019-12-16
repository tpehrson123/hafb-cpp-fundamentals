# TO2-1: Using Functions to Work With Payroll Data

### Student name:

### Github account:
---

A company needs a program that will compute weekly payroll. They have hours worked and wage information stored in a file.They need a program that can read the file and produce the information needed to print payroll.

For this try it out activity we will be creating a program that uses arrays and functions to read from the file and produce the payroll information needed. As a starting point, we will compute and report the gross pay. Later, various deductions could be included to also compute net pay.

There are videos that walk through the activity. 

---
### Files to work on
We will be working in the TO2-1 folder of the Module2 repository. You can work on and modify the following files:
- `README.md`: Update the student name and github account.
- There will also be a library `functions` that contains the functions needed for this program. The library consists of these two files:
  - `src/functions.cpp`
  - `src/functions.h`
- Our "driver" will be `src/main.cpp`.
- In addition you can create additional input and output files for testing purposes.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in a score reduction and may result in the unit tests not passing.

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

## Part 1: READ DATA FROM A FILE

The first function we will write is the `ReadDataFromFile` function. This function has six parameters.
- a string, the name of the file to read, including the path, filename, and extension
- four arrays
   - an array of type double for hours worked during the pay period
   - an array of type char for pay types, these are to be an 'h' for hourly pay or 's' for salary pay
   - an array of type double for pay rates
   - an array of strings for employee names in last, first format
- an int, the index that identifies the location to add the next element in the array

The arrays and the index parameter will be changed as the function executes. These are to be passed by reference.

It returns a `string`.

In the `functions.h` file use `#ifndef, #define, and #endif` to add an include guard to the header file.

In the `functions.h` file add the function declaration. Since the declaration will include arrays, we will need to specify how big they are. Add a constant integer named `kMaxSize` and set it to `32`. Use this for the size of the arrays.

In the `functions.cpp` file write the implementation of this function.

The function is to open the file to read the data. If the file does not open, return the string "Unable to open file". 

The function reads data from the file specified in the parameter and stores the values in the parameter arrays. The code is to protect the arrays from going out of bounds. Each time a set of values is added, the index parameter is increased. The file contains payroll data. Each set of data is on two lines.
- The first line contains three items separated by a space
  - hours worked
  - pay type
  - pay rate
- The second line contains a name in last, first format 

Add the data to the arrays. Validate the following. Notice there is a space at the end of each validation message. This keeps the messages from running together when there is more than one.
 - hours worked is between 0-168 (including 0 and 168). If it is smaller or larger add the string "Hours is out of range, set to 0 " to the error message and set hours to 0. 
 - pay type is either 'h' or 's'. If it is any other character, add the string "Incorrect pay type, set to s " to the error message and set the pay type to 's'. 
 - pay rate is greater than minimum wage (7.25). If the rate is smaller than this,  add the string "Pay is less than minimum wage, set to 7.25 " to the error message and set the pay to 7.25. 
 - name contains a comma. If there is no comma, add the string "Name is not in last, first format " to the error message and set the name to "unknown". 

After the data is read, `close` the file.

Finally, `return` the error message or the empty string if there are no error messages.

---
---

## Part 2: ADD A SET OF PAYROLL DATA

The next function is the `AddPayrollData` function. This function has nine parameters.

- four arrays
   - an array of type double for hours worked during the pay period
   - an array of type char for pay types, these are to be an 'h' for hourly pay or 's' for salary pay
   - an array of type double for pay rates
   - an array of strings for employee names in last, first format
- four data values
   - a double for hours worked during the pay period
   - a char for pay type
   - a double for pay rate
   - a string for employee name in last, first format
- an int, the index that identifies the location to add the next element in the array

The arrays and the index parameter will be changed as the function executes. These are to be passed by reference.

It `returns` a `string`.

In the `functions.h` file add the function declaration. 

In the `functions.cpp` file write the implementation of this function.

The function validates the data values, adds them to the parameter arrays, and increases the index parameter. The code is to protect the arrays from going out of bounds. 

When the arrays are full, adding the payroll data will cause the arrays to go out of bounds. Check and if the arrays are full, return the string "Arrays are full, no payroll data added".

Add the data to the arrays. Validate the following. Notice there is a space at the end of each validation message. This keeps the messages from running together when there is more than one.
 - hours worked is between 0-168 (including 0 and 168). If it is smaller or larger add the string "Hours is out of range, set to 0 " to the error message and set hours to 0. 
 - pay type is either 'h' or 's'. If it is any other character, add the string "Incorrect pay type, set to s " to the error message and set the pay type to 's'. 
 - pay rate is greater than minimum wage (7.25). If the rate is smaller than this,  add the string "Pay is less than minimum wage, set to 7.25 " to the error message and set the pay to 7.25. 
 - name contains a comma. If there is no comma, add the string "Name is not in last, first format " to the error message and set the name to "unknown". 

Finally, return the error message or the empty string if there are no error messages.

---
---

## Part 3: COMPUTE GROSS PAY

The next function is the `ComputeGross` function. This function has three parameters.

   - a double for hours worked during the pay period
   - a char for pay type
   - a double for pay rate


It `returns a double`.

In the `functions.h` file add the function declaration. 

In the `functions.cpp` file write the implementation of this function.

The function computes and returns the gross pay. The computation for gross pay depends on the pay type.

For a salary pay type, the gross pay is the pay rate. No computation is needed.

For an hourly pay type, the computation depends on whether the hours worked is greater than 40 hours or not. If the hours worked is 40 or less, the gross pay is the number of hours worked times the pay rate.

When the hours worked is greater than 40 and the pay type is hourly, the gross is the sum of regular pay and overtime pay. The regular pay is 40 hours times the pay rate. The overtime pay is the number of hours over 40 times the pay rate times 1.5. Define constants for the regular hours(40) and overtime rate (1.5).

Return the gross pay.

---
---

## Part 4: PRINT A PAYROLL REPORT TO A FILE

The next function we will write is the `WritePayrollReportToFile` function. This function has six parameters.
- a string, the name of the file to write to, including the path, filename, and extension
- four arrays
   - an array of type double for hours worked during the pay period
   - an array of type char for pay types, these are to be an 'h' for hourly pay or 's' for salary pay
   - an array of type double for pay rates
   - an array of strings for employee names in last, first format
- an int, the index that identifies the number of array elements that are valid

None of these values will change. Pass the arrays by reference and use the const specifier.

This function does `not` return anything.

In the `functions.h` file add the function declaration. 

In the `functions.cpp` file write the implementation of this function.

The function is to open the file to write the reports to.  

The function uses the data in the arrays to produce a report for each valid set of payroll data. Each report will take two lines.

- The first line contains a name in first last format 
- The second line contains four items separated by a space
  - hours worked
  - pay type
  - pay rate
  - gross pay

The hours worked, pay rate, and gross pay values are to be printed with `two digits` after the decimal place. The name is to be printed in first last form.  
Hint: Use `setprecision` and `fixed` from the `<iomanip>` [library](http://www.cplusplus.com/reference/iomanip/setprecision/)

`Close` the output file.


---
---

## Part 5: PRINT PAYROLL DATA TO A FILE

Now add the `WritePayrollDataToFile` function. This function has `six` parameters.
- a string, the name of the file to write to, including the path, filename, and extension
- four arrays
   - an array of type double for hours worked during the pay period
   - an array of type char for pay types, these are to be an 'h' for hourly pay or 's' for salary pay
   - an array of type double for pay rates
   - an array of strings for employee names in last, first format
- an int, the index that identifies the number of array elements that are valid

None of these values will change. Pass the arrays by reference and use the const specifier.

This function `does not return` anything.

In the `functions.h` file add the function declaration. 

In the `functions.cpp` file write the implementation of this function.

The function is to `open` the file to write the reports to.  

The function uses the data in the arrays to produce a report for each valid set of payroll data. Each report will take two lines.

- The first line contains three items separated by a space
  - hours worked
  - pay type
  - pay rate
- The second line contains a name in last, first format 

`Close` the output file.

---
---

## Validate your code
Once you are satisfied with your work, run our unit test file.


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
  PS C:\Users\Linda\cs1410\cs1410-module2\TO2-2\build> .\bin\ca_test.exe
  ===============================================================================
  All tests passed (345 assertions in 46 test cases)
```
Note: If nothing is displayed after running the tests, something is
not as expected. Some of the tests check to see if the data can be written
outside the bounds of the array. When data is written outside of bounds, it is 
uncertain how a program will behave. One of the things that may happen is
the tests stop running and nothing is reported.

If this happens, I suggest looking at the code to make sure any reading loop
stops before going past the end of the array.

### Validate Part 1

Test your code with tag `[read]`:
```bash
$ .\bin\ca_test.exe [read]

```
---
---
### Validate Part 2
Test your code with tag `[add]`:
 
```bash
$ .\bin\ca_test.exe [add]
```

### Validate Part 3
  Test your code with tag `[gross]`:
  ```bash
  $ .\ca_test.exe [gross]
  ```
### Validate Part 4
Test your code with tag `[write_report]`:
```bash
$ .\bin\ca_test.exe [write_report]
```

### Validate Part 5
Test your code with tag `[write_data]`:
```bash
$ .\bin\ca_test.exe [write_data] 
```

### Finally run ALL tests:
```bash
$ .\bin\ca_test.exe
```

---
---
### Publish your code
Now you are ready to publish and test the code. At this point, all the tests are expected to pass. 

The next step is to push the code to GitHub. Before you push your code, edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `line 19` for TO2-1. 


```CMake
18: env: 
19:   - TEST_DIR=TO2-1
20:   # - TEST_DIR=TO2-2
22:   # - TEST_DIR=CA1-1
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module2 repository to the TO2-1 assignment in Canvas.

---
