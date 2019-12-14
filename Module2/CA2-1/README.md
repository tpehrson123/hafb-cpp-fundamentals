# CA2-1: CREATING A PROJECT CLASS

### Student name:

### Github account:
---
## Purpose:
Classes are central to object oriented programming. In this activity we will 
use some of the standard classes such as string, ifstream, and ofstream.
Then we will create and use our own Project class.

## Skills:
This activity will help you practice the following skills that are essential to know for basic programming in `C++`:
  - Create objects
  - Call class methods
  - Work with the standard string class
  - Work with file I/O classes ifstream, and ofstream
  - Define a Project class
  - Create objects of type Project
  - Use objects to access the functionality of the Project class
  - Generate and handle exceptions

## Knowledge:
This lab will also help you to become familiar with the following important content knowledge in CS:
  - Use source version control: `git`.
  - Use basic unit testing to validate your code: `catch2`.
---

## Challenge Activity
The team manager wants to track the time spent on projects. When a project starts, there is an idea of how much time the project will take. However, it is not clear if those estimates are accurate or not. 

To develop a better sense of whether projects are getting done in the time alloted, the team wants a way to track the original estimate and the actual time spent on the project. 

For this challenge activity we will be creating a Project class and a File I/O library that provides this tracking functionality.

---
### Files to work on
You are required to work/modify the following files:
- `README.md`: Update the student name and github account.
- The Project class will be part of the library `project`. The library consists of these two files:  
  - `src/project.cpp`
  - `src/project.h`.
- - There will also be a library `fileio` with functions to read and write Projects. The library consist of these two files: 
  - `src/fileio.cpp`
  - `src/fileio.h`
- Our "driver" will be `src/main.cpp`.
- In addition you can create additional input and output files for testing purposes.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

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

## Part 1: CREATING THE PROJECT CLASS (50 POINTS)
Start the challenge activity by creating the Project class and adding getter methods, setter methods, constructors, and a destructor. 

*Note*: Naming of the public interface is critical. It is important to name the class and public members as specified. Otherwise, the unit tests will not work.

In the header file, `project.h`, and the implementation file, `project.cpp`, add the following.

1. Use #ifndef, #define, and #endif to add an include guard to the header file.

2. Create a class named Project.

3. Add the private data members. This class has four data members.
   1. A name. This is a string that contains the name of the Project.
   2. The estimated time. This is an integer that stores the estimated time to complete the project in minutes. 
   Sometimes we will want to access the estimated time in hours and sometimes in minutes. Since it is reasonable to identify estimated time in hours and in minutes, we will need to provide methods for both types of time. It is simple to convert from one to the other so we only need to store a single version of estimated time. This Project class will store estimated time in minutes.
   1. The actual time. This is an integer that stores how much time has been spent on the project in minutes. 
   Sometimes we will want to access the actual time in hours and sometimes in minutes. Since it is reasonable to identify actual time in hours and in minutes, we will need to provide methods for both types of time. It is simple to convert from one to the other so we only need to store a single version of actual time. This Project class will store actual time in minutes. 
   1. The reported percent complete. This stores how much of the project is complete as reported by the user. This value is an integer so 25% complete is stored as 25.

    *Note*: Avoid the C++ `using` and `using namespace` directives in a header file. This means when using names from the std namespace, preface them with `std::` as shown below.
    ```cpp
      std::string 
    ```

    A similar process can be used for other namespaces.

4. Add the public getter (accessor) methods. Add a getter method for each private data member that returns its current value. In addition to these methods, add one that returns the estimated time in hours and one that returns the actual time in hours.

    None of these getter methods will make changes to the actual object so they can be const methods.

    Here are the prototypes for the getter methods.

    ```cpp
      std::string name() const;
      int estimated_time_minutes() const;
      double estimated_time_hours() const;
      int actual_time_minutes() const
      double actual_time_hours() const
      int reported_percent_complete() const;
    ```

    These can be implemented as inline methods.


5. Add the public setter (mutator) methods. The setter methods allow us to control what values the private data members can contain. There will be a setter method for each data member. 

    In addition to these methods, add one that receives the estimated time in hours and stores it as minutes.

    Add another one that receives the actual time in hours and stores it as minutes.

   1. The name does not need any validation. It can be any string.
   2. The estimated time must be greater than zero (zero is not allowed).
   3. The actual time can be zero or greater.
   4. The reported percent complete must be 0-100, including both 0 and 100.

    When a value outside of the allowed values is sent as an argument, throw an `out_of_range` exception with an informative message and do not create a Project.

    Here are the declarations (prototypes) for the setter methods.

    ```cpp
      void set_name(std::string name);
      void set_estimated_time_minutes(int estimated_time_minutes);
      void set_estimated_time_hours(double estimated_time_hours);
      void set_actual_time_minutes(int actual_time_hours);
      void set_actual_time_hours(double actual_time_minutes);
      void set_percent_complete(int percent_complete);
    ```
6. Add the default constructor. This constructor has no parameters and sets the following values.

   1. set name to "unnamed"
   2. set estimated time to 60 minutes
   3. set actual time to 0
   4. set reported percent complete to 0
    
    Here is the declaration (prototype) for the default constructor.

    ```cpp
      Project();
    ```

7. Add an overloaded constructor with four parameters, one for each data member. The estimated time and actual time parameters will receive the values in hours. Set default values for the last two parameters, actual time to 0 and recorded percent complete to 0. 

    1. Inside the method definition, call the setter methods. Do not re-write any of the validating code.
    2. Catch `out_of_range` exceptions that are thrown by the setter methods and rethrow them. 
    
    Here is the declaration (prototype) for the overloaded constructor.

    ```cpp
      Project(std::string name, double estimated_time_hours,
              double actual_time_hours = 0, int percent_complete = 0);
    ```

8. Add a destructor. Nothing needs to be done in the destructor. For completeness, add a destructor that does nothing.
    
    Here is the declaration (prototype) and inline definition for the destructor.

    ```cpp
      ~Project(){};
    ```


---
---

## Part 2: RECORDING ACTIVITY ON A PROJECT (10 POINTS)
Next we will add the functionality to record actual time worked on the project. This will allow tracking. We will create two methods to do this, one that receives time worked in minutes and one that receives time worked in hours. 

Each method will receive the time worked on the project since the last report and an estimate of how complete the project is. For example, consider a project that is estimated to take 40 hours to complete. So far the team has worked 12 hours on this project and estimated it was 20% complete. Today Kim worked for 90 minutes on the project and estimates the project is 25% complete.

To record this time the RecordTimeSpentMinutes or RecordTimeSpentHours method can be called.

```cpp
my_project.RecordTimeSpentMinutes(90, 25);
//or
my_project.RecordTimeSpentHours(1.5, 25);

```

Now the project will have an estimated time of 2400 minutes (40 hours), an actual time of 810 minutes (13.5 hours), and an estimated percent complete of 25 (25%).


1. Write the RecordTimeSpentMinutes method that receives the number of minutes worked and estimated percent complete. This method is to update the actual time spent and estimated percent complete data members.

    The minutes worked is added to whatever actual time is already recorded. The estimated percent complete replaces the previous estimate.

    1. Inside the method definition call the setter methods. Do not re-write any of the validating code.
    2. Catch `out_of_range` exceptions that are thrown by the setter methods and rethrow them. 
    
    Here is the declaration (prototype) for the RecordTimeSpentMinutes method.

    ```cpp
      void RecordTimeSpentMinutes(int minutes, int percent_complete);
    ```



2. Write the RecordTimeSpentHours method that receives the number of hours worked and estimated percent complete. This method is to update the actual time spent and estimated percent complete data members.

    This method works just like the RecordTimeSpentMinutes method except the actual time received is in hours instead of minutes. This makes it possible to reuse the code already written in RecordTimeSpentMinutes by simply converting the hours to minutes and calling the RecordTimeSpentMinutes method.



    1. Inside the method definition call the RecordTimeSpentMinutes method. Do not re-write any of the code already written.
    2. Catch `out_of_range` exceptions that are thrown by the RecordTimeSpentMinutes method and rethrow them. 
    
    Here is the declaration (prototype) for the RecordTimeSpentMinutes method.

    ```cpp
      void RecordTimeSpentHours(double hours, int percent_complete);
    ```

---
---    


## Part 3: CALCULATING PERCENT COMPLETE (5 POINTS)
One of values we store is the estimated percent complete. Another interesting value is the calculated percent complete. This is a simple calculation of the actual time divided by the estimated time.

This method makes no change to the object itself so it can be a const method.



1. Write the CalculatedPercentComplete method. This method has no parameters. 

    Here is the declaration (prototype) for the RecordTimeSpentMinutes method.

    ```cpp
      int CalculatedPercentComplete() const;
    ```

---
---    
   

## Part 4: CONVERTING MINUTES TO HH:MM FORMAT (10 POINTS)
Sometimes when working with time it is helpful to present it in the HH:MM format. For example, printing that there are 2468 minutes in a project may not be as clear as saying the time on the project is 41:08 In this section we will be creating a method that converts minutes to a string in the HH:MM format. This is an amount of time rather than clock time.

This method is not related to any specific object so it can be a static method.

There are some details to code into this conversion method.

- When minutes is less than 10, a 0 will be added so the minutes are always two digits. For example:

      13:02
      28:00
      3:09
      128:03

- Hours can take up 1 or more digits. If the amount of time is less than one hour, precede the : with a single 0.
  For example:

      2459:30
      123:22
      38:19
      4:08
      0:43

- When a negative number of minutes is being converted, there is only a single negative sign in the resulting string. 


      -14:22
      -6:08

    To make this work for the minutes section, the absolute value may be needed. There are two absolute value functions available in the cmath library, abs (for integers) and fabs (for floating point numbers). To access these, include the cmath header file.

    ```cpp
    #include <cmath>
    ```

1. Write a static member method that converts minutes to HH:MM This method has one parameter that specifies the number of minutes. This method does not access any of the members of the Project class. 

    Here is the declaration (prototype) for the ConvertMinutesToString method.

    ```cpp
      static std::string ConvertMinutesToString(int minutes);
    ```

---
---    



## Part 5: REPORTING TIME LEFT ON PROJECT (5 POINTS)
Sometimes the team wants to know how many hours are left on the project. This is the difference between the estimated time and the actual time spent on the project. This time is to be returned as a string in the HH:MM format. When the actual time spent is larger than the estimated time, this value will be negative.

This method makes no change to the object itself so it can be a const method.


1. Write the TimeLeftOnProject method. This method has no parameters. 

    Here is the declaration (prototype) for the RecordTimeSpentMinutes method.

    ```cpp
      std::string TimeLeftOnProject() const;
    ```

---
---


## Part 6: WRITING DATA (5 POINTS)
The team would like to write the data of an object to an output stream. The data will be written on two lines. The first line contains the estimated minutes, actual minutes, and percent complete separated by a space. The second line contains the name of the project. The second line is to include a carriage return at the end of the name.

This method is to receive an ostream object. The data is to be sent to that output stream.

This method makes no change to the object itself so it can be a const method.

1. Write a method that writes the project data. This method has a parameter that specifies which output stream to write to. 

    Here is the declaration (prototype) for the ProjectReport method.

    ```cpp
        void WriteData(std::ostream& out) const;
    ```

---
---

  

## Part 7: PROJECT REPORT (10 POINTS)
The team would like to have a standard format to report the current status of a project. This report will include the details they are most interested in. The report is to contain the following including labels, spacing, and carriage returns.

    
    Project Name
    Estimated time: HH:MM
    Actual time spent: HH:MM
    Calculated percent complete: P%
    Reported percent complete: P%
    
Replace Project Name with the actual name of the project. Replace the HH:MM with the current values for estimated and actual time. Replace the P with the current values for calculated and reported percent. 

For example, consider a project name Create Database Diagrams that is estimated to take 1320 minutes (22 hours), has actual time spent of 90 minutes (1.5 hours), and has a reported percent complete of 12. The report for this project will look like this;

    Create Database Diagrams
    Estimated time: 22:00
    Actual time spent: 1:30
    Calculated percent complete: 7%
    Reported percent complete: 12%

This method is to receive an ostream object. The report is to be sent to that output stream.

This method makes no change to the object itself so it can be a const method.


1. Write a method that creates a project report and returns it as a string. This method has no parameters. 

    Here is the declaration (prototype) for the ProjectReport method.

    ```cpp
        void ProjectReport(std::ostream& out) const;
    ```

---
---


## Part 8: CREATING A FILE I/O LIBRARY FOR THE PROJECT CLASS (15 POINTS)
There are times when the program will be shut down. When this happens the team would like to save the information about all the projects. They would also like to be able to load those projects when the program starts up again.

To support this functionality, create the fileio library. This library will contain two functions, one that reads projects from a file and stores them in an array and one that saves projects from an array to a file.

Each Project takes two lines in the file. The first line contains the estimated minutes, actual minutes, and percent complete separated by a space. The second line contains the name of the project. There are no blank lines between Projects.

1. Use #ifndef, #define, and #endif to add an include guard to the header file.
   
2. In the fileio.h file define a global constant named kMaxSize. This is to be an integer with a value of 20. This constant will be used when defining and passing arrays.

3. In the fileio.h file add the declarations (prototypes) for both functions. 
 
    Here are the declarations (prototypes) for the file I/O functions.

    ```cpp
      std::string ReadProjectsFromFile(
          const std::string filename,
          std::array<Project, kMaxSize>& projects,
          int& size);
            
      void WriteProjectsToFile(
          const std::string filename,
          const std::array<Project, kMaxSize>& projects,
          const int size);
    ```

 1. In the fileio.cpp file write the implementation for the ReadProjectsFromFile function. This function is to receive a filename, an array of Projects, and the current number of useful Projects in the array. It is to read all the data in the file, create, and add each Project to the array. It is also to update the number of useful Projects. Be sure to close the file before ending the function.

    The function is to return the string "Unable to open file." if the file does not open. When this happens, the function can end.
    
    It is to return the string "Unable to add project named **** " (replace **** with the actual name of the project) followed by the exception message for each exception that is thrown during construction of a Project. The function is to continue through to the end of file or until the array is full whichever comes first.

4. In the fileio.cpp file write the implementation for the WriteProjectsToFile function. This function is to receive a filename, an array of Projects, and the current number of useful Projects in the array. It is to write all the project data in the array to the file. Use the class method WriteData to do this work. Be sure to close the file before ending the function.

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
  PS C:\Users\Linda\C++ Fundamentals\C++ Fundamentals-module2\CA2-1\build> .\bin\ca_test.exe
  ===============================================================================
  All tests passed (405 assertions in 75 test cases)
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
directory of your project. Uncomment `line 22` for CA2-1. 

```CMake
18: env: 
19:   - TEST_DIR=TO2-1
20:   - TEST_DIR=TO2-2
22:   - TEST_DIR=CA2-1
```

Then [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
---


### Reviewing the code
The unit tests identify much of what this project is expected to do. There are some details that will need to be manually reviewed to determine the final score for this assignment. 

  Here is a list of expectations that will be manually reviewed.

  - Using namespace is not included in .h files
  - Data members use snake case and end with _
  - Reuse code rather than rewrite it, for example:
    - Constructors call setter methods
    - RecordTimeSpentHours calls RecordTimeSpentMinutes
    - File I/O function WriteProjectsToFile calls the WriteData method
    - etc.
  - kMaxSize is defined as a constant
  - Loops that read to end of file protect from going out of bounds
  - Files are closed before leaving the function that opened them
  - Used consistent, high-quality style
  - Doxygen documented code 


---
---    
