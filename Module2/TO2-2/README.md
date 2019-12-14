# TO2-2: Using a Class to Work With Payroll Data 

### Student name:

### Github account:
---

A company needs a program that will compute weekly payroll. They have hours worked and wage information stored in a file.They need a program that can read the file and produce the information needed to print payroll.

For this try it out activity we will be creating a program that creates and uses the PayrollData class to create this functionality. As a starting point, we will compute and report the gross pay. Later, various deductions could be included to also compute net pay.

There are videos that walk through the activity. 

---
### Files to work on
We will be working in the TO2-2 folder of the Module2 repository. We will be editing the following files:
- Our "driver" will be `src/main.cpp`.
- There will be a class library `payroll_data` that contains the declaration and implementation of the PayrollData class. The library consists of these two files:
  - `src/payroll_data.cpp`
  - `src/payroll_data.h`
- There will also be a class library `fileio` that contains functions for reading and writing PayrollData objects from/to files and writes payroll reports to a file. The library consists of these two files:
  - `src/fileio.cpp`
  - `src/fileio.h`

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

## Part 1: CREATING THE PAYROLL DATA CLASS
Start the try it out activity by creating the PayrollData class and adding getter methods, setter methods, constructors, and a destructor. 

*Note*: Naming of the public interface is critical. It is important to name the class and public members as specified. Otherwise, the unit tests will not work.

In the header file, `payroll_data.h`, and the implementation file, `payroll_data.cpp`, add the following.

1. Use #ifndef, #define, and #endif to add an include guard to the header file.

2. Create a class named PayrollData.

3. Add the private data members. This class has five data members.
   1. The hours. This is a double that stores the number of hours worked in this pay period. 
   2. The pay type. This is a character that stores whether the employee is paid hourly or is on salary. It contains either a 'h' or 's'. 
   3. The pay rate. This is a double and stores how much the employee is paid. For hourly employees, this is the hourly wage. For salary employees, this is what their salary is for the pay period.
   4. A first name. This is a string that contains the employee's first name.
   5. A last name. This is a string that contains the employee's last name.

    *Note*: Avoid the C++ `using` and `using namespace` directives in a header file. This means when using names from the std namespace, preface them with `std::` as shown below.
    ```cpp
      std::string 
    ```

    A similar process can be used for other namespaces.

4. Add the public getter (accessor) methods. Add a getter method for each private data member that returns its current value. In addition to these methods, add one that returns the full name in first last format and another that returns the full name in last, first format.

    None of these getter methods will make changes to the actual object so they can be const methods.

    Here are the prototypes for the getter methods.

    ```cpp
      double hours() const;
      char pay_type() const;
      double pay_rate() const;
      std::string first_name() const;
      std::string last_name() const;
      std::string name() const;
      std::string name_last_first();
    ```

    These can be implemented as inline methods.


5. Add the public setter (mutator) methods. The setter methods allow us to control what values the private data members can contain. There will be a setter method for each data member. 


   1. The hours worked is between 0-168 (including 0 and 168).
   2. The pay type is either 'h' or 's'. 
   3. The pay rate is greater than minimum wage (7.25). 
   4. The name. This is a string in either first last format or last, first format. The code is to handle either format and set the first and last name data members.

    When a value outside of the allowed values is sent as an argument, throw an `out_of_range` exception with an informative message and do not create a PayrollData object.

    Here are the declarations (prototypes) for the setter methods.

    ```cpp
      void set_hours(double hours);
      void set_pay_type(char pay_type);
      void set_pay_rate(double pay_rate);
      void set_name(std::string name);
    ```
6. Add the default constructor. This constructor has no parameters and sets the following values.

   1. Set hours to 0
   2. Set pay type to 'h'
   3. Set pay rate to 7.25
   4. Set first name to "it is"
   5. Set last name to "unknown"
    
    Here is the declaration (prototype) for the default constructor.

    ```cpp
      PayrollData();
    ```

7. Add an overloaded constructor with four parameters, one for hours, pay type, pay rate, and employee name.

    1. Inside the method definition, call the setter methods. Do not re-write any of the validating code.
    2. Catch `out_of_range` exceptions that are thrown by the setter methods and rethrow them. 
    
    Here is the declaration (prototype) for the overloaded constructor.

    ```cpp              
      PayrollData(double hours, char pay_type, double pay_rate, std::string name);
    ```

8. Add a destructor. Nothing needs to be done in the destructor. For completeness, add a destructor that does nothing.
    
    Here is the declaration (prototype) and inline definition for the destructor.

    ```cpp
      ~PayrollData(){};
    ```


---
---

## Part 2: COMPUTE GROSS PAY

For the weekly payroll, the gross pay will be needed. Write a method named ComputeGross. This method has no parameters. It returns a double.

The method computes and returns the gross pay. The computation for gross pay depends on the pay type.

For a salary pay type, the gross pay is the pay rate. No computation is needed.

For an hourly pay type, the computation depends on whether the hours worked is greater than 40 hours or not. If the hours worked is 40 or less, the gross pay is the number of hours worked times the pay rate.

When the hours worked is greater than 40 and the pay type is hourly, the gross is the sum of regular pay and overtime pay. The regular pay is 40 hours times the pay rate. The overtime pay is the number of hours over 40 times the pay rate times 1.5. Define static member variables for the regular hours(40) and overtime rate (1.5).

Return the gross pay.

This method will not make changes to the actual object so it can be a const method.

  Here is the declaration (prototype) for the ComputeGross method.

  ```cpp
    double ComputeGross() const;
  ```

  ---
---

## Part 3: WRITE DATA TO AN OUTPUT STREAM

The company would like to write the payroll data to an output stream. To accomplish this, create a method named WriteData. The method has one parameter and returns nothing. This parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. It is passed by reference because it actually makes changes to the output stream such as where the file pointer is.

The WriteData method is to write the following data to the output stream. It is to be written on two lines. 

- The first line contains three items separated by a space
  - hours worked
  - pay type
  - pay rate
- The second line contains a name in last, first format and ends with a carriage return

This method will not make changes to the actual object so it can be a const method.

  Here is the declaration (prototype) for the ComputeGross method.

  ```cpp
    void WriteData(std::ostream &out) const;
  ```

---
---

## Part 4: WRITE A PAYROLL REPORT

Sometimes the company would like a payroll report that includes the data with labels. 
Write a method named PayrollReport. This method has one parameter and returns 
nothing. The parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. 

The PayrollReport method is to write the following report to the output stream. It is to be written on four lines as shown below.

    
    Name
    Hours Worked: hours
    Pay Type: type
    Pay Rate: $rate
    Gross Pay: $gross

 Replace Name with the actual name of the employee in first last format. 
 Replace hours with the actual hours worked. Replace type with either hourly 
 or salary. Replace rate with the actual pay rate. Replace gross with the 
 computed gross pay.

 Set the precision on the output stream to display two digits after the decimal place.

For example, consider the payroll data with name Kim Watson that worked 43.5 
hours, is an hourly employee, and has a pay rate of 23.50. the payroll report 
would look like this:

    Kim Watson
    Hours Worked: 43.50
    Pay Type: hourly
    Pay Rate: $23.50
    Gross Pay: $123.38

This method makes no change to the object itself so it can be a const method.


  ```cpp
    void PayrollReport(std::ostream &out) const;
  ```

---
---

## Part 5: CREATING A FILE I/O LIBRARY FOR THE PAYROLL DATA CLASS 

The payroll data is stored in files. The company would like to be able to read
payroll data from a file and write payroll data to a file. 

To support this functionality, create the fileio library. This library will 
contain two functions, one that reads payroll data from a file and stores them in 
an array and one that saves payroll data from an array to a file.

Each payroll data takes two lines in the file. The first line contains the
 hours, pay type, and pay rate each separated by a space. 
 The second line contains the employee name in last, first format. 
 There are no blank lines between payroll data.

1. Use #ifndef, #define, and #endif to add an include guard to the header file.
   
2. In the fileio.h file define a global constant named kMaxSize. This is to be an integer with a value of 32. This constant will be used when defining and passing arrays.

3. In the fileio.h file add the declarations (prototypes) for both functions. 
 
    Here are the declarations (prototypes) for the file I/O functions.

    ```cpp
      std::string ReadDataFromFile(std::string filename,
                                   std::array<PayrollData, kMaxSize> &payroll_data,
                                   int &size);
            
      void WriteDataToFile(std::string filename,
                           const std::array<PayrollData, kMaxSize> &payroll_data,
                           int size);
    ```

 1. In the fileio.cpp file write the implementation for the ReadDataFromFile function. This function is to receive a filename, an array of PayrollData objects, and the current number of useful PayrollData objects in the array. It is to read all the data in the file, create, and add each PayrollData to the array. It is also to update the number of useful PayrollData objects. Be sure to close the file before ending the function.

    The function is to return the string "Unable to open file." if the file does not open. When this happens, the function can end.
    
    It is to return the string "Unable to add payroll data for **** " (replace **** with the actual name of the employee in the format it was in the file) followed by the exception message for each exception that is thrown during construction of a PayrollData object. The function is to continue through to the end of file or until the array is full whichever comes first.

4. In the fileio.cpp file write the implementation for the WriteDataToFile function. This function is to receive a filename, an array of PayrollData objects, and the current number of useful PayrollData objects in the array. It is to write all the payroll data in the array to the file. Use the class method WriteData to do this work. Be sure to close the file before ending the function.



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
  PS C:\Users\Linda\C++ Fundamentals\C++ Fundamentals-module2\TO2-2\build> .\bin\ca_test.exe
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

Test your code with tag `[start]`:
```bash
$ .\bin\ca_test.exe [start]
```

### Validate Part 2
Test your code with tag `[record_time]`:
 
```bash
$ .\bin\ca_test.exe [record_time] 
```

### Validate Part 3
  Test your code with tag `[calculated_percent]`:
  ```bash
  $ .\ca_test.exe [calculated_percent]
  ```
### Validate Part 4
Test your code with tag `[convert]`:
```bash
$ .\bin\ca_test.exe [convert]
```

### Validate Part 5
Test your code with tag `[time_left]`:
```bash 
$ .\bin\ca_test.exe [time_left]
```

### Validate Part 6
Test your code with tag `[write_data]`:
```bash 
$ .\bin\ca_test.exe [write_data]
```

### Validate Part 7
Test your code with tag `[reports]`:
```bash
$ .\bin\ca_test.exe [reports]
```

### Validate Part 8
Test your code with tags `[read_file]` and `[write_file]`:
```bash
$ .\bin\ca_test.exe [read_file]
#or
$ .\bin\ca_test.exe [write_file]
#or both
$ .\bin\ca_test.exe [read_file],[write_file]
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
directory of your project. Uncomment `line 20` for TO2-2. 

```CMake
18: env: 
19:   - TEST_DIR=TO2-1
20:   - TEST_DIR=TO2-2
22:   # - TEST_DIR=CA1-1
```

Then [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
---
### Submit to Canvas
Submit a URL to your Module2 repository to the TO2-1 assignment in Canvas.

---