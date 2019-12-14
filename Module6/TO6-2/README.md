# TO6-2: The Payroll Class

### Student name:

### Github account:
---

## Purpose:
In this activity we are going to revisit the PayrollData class. Remember that this class contained payroll information and was able to compute and display the gross pay. We computed gross pay for hourly and salaried employees.
Now we are going to expand the options to include commission employees as well.

Instead of having this functionality in a single class we are going to use inheritance. We will have a base class, PayrollData that will contain the common data members and functionality. Then we will have three subclasses: HourlyPayroll, SalaryPayroll, and CommissionPayroll. Each of these classes will implement the details that are specific to this type of payroll.

Then we will write a function the uses a vector of PayrollData pointers to run payroll for several employees. 


---
### Files to work on
We will be working in the TO6-2 folder of the Module6 repository. You can work 
on and modify the following files:
- `README.md`: Update the student name and github account.
- There is a library of classes that work with the `payroll_data` library. The library 
  consists of the following files:
  - `src/payroll_data.cpp`
  - `src/payroll_data.h`
  - `src/hourly_payroll.cpp`
  - `src/hourly_payroll.h`
  - `src/salary_payroll.cpp`
  - `src/salary_payroll.h`
  - `src/commission_payroll.cpp`
  - `src/commission_payroll.h`
- There will also be a  library `process_payroll` that contains the function for reading  PayrollData objects and writing payroll reports to a file. The library consists of these two files:
  - `src/process_payroll.cpp`
  - `src/process_payroll.h`
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


In this activity we will be creating several classes. To see how the classes are related, consider the following UML class diagram.

![UML class diagram of the PayrollData base class and subclasses](images/cs1410_to6-2_class_diagram.png)

---
---

## Part 1: ADAPT THE PAYROLLDATA CLASS 

We have worked with the `PayrollData` class in previous activities. We will be using it again in this activity. We will start with the version from TO2-2. 

1. Use the `PayrollData` class from TO2-2. You can copy the class code from this previous activity into the payroll_data.h and payroll_data.cpp files.


2. Remove the data members and associated functionality that are not common to a payroll data types.

  Note: as you are removing code you might want to keep a copy as some of the code may be useful in one of the subclasses.


- Remove two private data members
  - hours_, this only applies to one of the payroll types so we will not have it in the base class
  - pay_type_, this will no longer be needed as each subclass will specify a type
- Remove the initialization of these types in the default constructor
- Remove the matching parameters from the non-default constructor and the related code in the implementation of this constructor.
- Remove the getters for hours and pay_type.
- Remove the setters for hours and pay_type.
- Remove the declaration of the static data members kRegularHours and kOvertimeRate.
- Remove the definition of the static data members kRegularHours and kOvertimeRate.

3. Change the remaining private data members to protected. This will allow the subclasses to have direct access to these data members.
4. Adapt the `set_pay_rate` method. The minimum pay rate of $7.25 only applies to hourly payroll. The more general use minimum is 0. This more general value is what we will want in the base class. But we will want the subclasses to overwrite this method when needed. To make sure the subclass version is used we will make this a virtual method.    
   - Change the declaration of the set_pay_rate method by adding virtual before void in the method declaration.  
   - Change the implementation of the set_pay_rate method so that it sets the pay rate to the value sent. If the pay rate is less than zero, throw an out_of_range exception.
5. The `set_name` method is to work as it did previously. It is to receive the name in either `first last` format or `last, first` format. No matter which format it comes in, the first name is to identified and stored individually. The last name is to identified and stored individually. 
6. Change the `default constructor` to reflect this change in the minimum pay rate.
   - In the `default constructor` set the pay rate to 0.
7. Adapt the `ComputeGross` method. Computing the gross pay will be different for each payroll type so we don't want to implement it in the base class. 
 
   In this base class we can do the following to force it to be written in the subclasses.
   - Remove the implementation for the ComputeGross method in the payroll_data.cpp file.
   - In the payroll_data.h file, change the declaration by adding virtual before the return type and setting the declaration equal to 0.

8. Adapt the `WriteData` method and the `PayrollReport` method in the same way. 
   - Remove the implementation in the payroll_data.cpp file.
   - In the payroll_data.h file, change the declaration by adding virtual before the return type and setting the declaration equal to 0.


Since the `PayrollData` class now has pure virtual functions we are not able to declare any objects of type PayrollData. We will not be able to do any testing at this point.


---
---

## Part 2: CREATE THE HOURLYPAYROLL CLASS 

Now we will create the HourlyPayroll class. This type of payroll is computed using pay rate and number of hours worked. 

The HourlyPayroll class will inherit from the PayrollData class so it will get the data members and functionality that is defined in the PayrollData class. 

We will need an additional private data member and associated getters and setters. We will need to adapt the pay rate setter as there is a minimum wage for hourly employees. We will also need to implement the virtual functions of the base class.


1. In the `hourly_payroll.h` file add a declaration for the class named `HourlyPayroll`.

- The include guards are already in the file
- Add a declaration for the class `HourlyPayroll`
- Add the notation at the top of the `HourlyPayroll` class that has it inherit from the `PayrollData` class. Use public inheritance.

- Add one private data member.
   - a double that keeps track of hours worked
  
  
- add a public section with the following
  - five static constant data members
    - kMinHours - a double for the minimum number of hours allowed
    - kMaxHours - a double for the maximum number of hours allowed
    - kRegularHours - a double for the regular hours in a pay period
    - kOvertimeRate - a double that specifies the increase in rate for overtime hours
    - kMinimumWage - a double that specifies the minimum pay rate for hourly employees
  - two constructors and a destructor
    - HourlyPayroll();
    - HourlyPayroll(double pay_rate, double hours_worked,std::string name);
    - ~HourlyPayroll();
  - one getter
    - double hours() const;
  - two setters
    - void set_pay_rate(double pay_rate);
    - void set_hours(double hours_worked);
  - three other methods    
    - double ComputeGross() const;
    - void WriteData(std::ostream &out) const;
    - void PayrollReport(std::ostream &out) const;

2. In the hourly_payroll.cpp file `include` the hourly_payroll.h header file.


3. Write the definition for the static constants.
  - Set kMinHours to 0
  - Set kMaxHours to 168
  - Set kRegularHours to 40
  - Set kOvertimeRate to 1.5
  - Set kMinWage to 7.25

4. Write the implementation for the `getter`. The getter returns the value of the matching data member.

5. Write the implementation for the `setters`. 
-  The set_pay_rate method sets the pay rate to the value sent. If the pay rate sent is less than kMinWage it throws an out_of_range exception.
-  The set_hours_worked method sets the hours worked data member to the value sent. If the hours sent is less than kMinHours or greater than kMaxHours it throws an out_of_range exception.

6. Write the `default constructor`. 

- The following will automatically be set by the PayrollData default constructor:
  - pay rate to 0
  - first name to 'it is'
  - last name to 'unknown'
- Write the code to set the following:
  - pay rate to kMinWage
  - hours worked to kMinHours


7. Write the `non-default constructor`. 

- This constructor is to call the setters in the HourlyPayroll class to set the pay_rate, hours worked, and name to the value sent.  
  
8. Write the `destructor`. It does not need to do anything. Just add the { }s
 
9. Implement the `ComputeGross` method. This method has no parameters. The method computes and returns the gross pay. 

    For hourly payroll, the computation depends on whether the hours worked is greater than 40 hours or not. If the hours worked is 40 or less, the gross pay is the number of hours worked times the pay rate.

    When the hours worked is greater than 40 and the pay type is hourly, the gross is the sum of regular pay and overtime pay. The regular pay is 40 hours times the pay rate. The overtime pay is the number of hours over 40 times the pay rate times 1.5. 

    You can use the static member variables in the base class for the regular hours(40) and overtime rate (1.5).

    Return the gross pay.

Note: There are some differences in the order of the WriteData and PayrollReport output. Watch carefully.
  
10. Implement the `WriteData` method.
  
    This method will output the data for the hourly payroll. The method has one parameter and returns nothing. This parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. It is passed by reference because it actually makes changes to the output stream such as where the file pointer is.


    The WriteData method is to write the following data to the output stream. It is to be written on two lines. Be careful to output the details exactly including capitalization, comma, and spacing.

  - The first line contains three items separated by a space
    - H
    - pay rate
    - hours worked
  - The second line contains a name in last, first format and ends with a carriage return
    - For example, consider the payroll data with name Kim Watson that has a pay rate of 23.50 and worked 43.5 hours. The payroll data would look like this:
    ```
    H 23.5 43.5
    Kim Watson
    ```
    This method will not make changes to the actual object so it can be a const method.
    
11. Implement the `PayrollReport` method. This prints the payroll data in a more human readable form. It includes the data with labels. This method has one parameter and returns nothing. The parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. 

    The PayrollReport method is to write the following report to the output stream. It is to be written on four lines as shown below.
    ```     
      Name
      Pay Type: hourly
      Pay Rate: $rate
      Hours Worked: hours
      Gross Pay: $gross
    ```
    Replace Name, hours, rate, and gross with the 
    actual values. Be careful to output the details exactly including capitalization, :, $, and spacing.

    Use setprecision and fixed on the output stream to display two digits after the decimal place.

    For example, consider the payroll data with name Kim Watson that worked 43.5 
    hours, and has a pay rate of 23.50. The payroll report 
    would look like this:
    ```
        Kim Watson
        Pay Type: hourly
        Pay Rate: $23.50
        Hours Worked: 43.50
        Gross Pay: $123.38
    ```
    This method makes no change to the object itself so it can be a const method.


12. Now we can run the unit tests on the `PayrollData` and `HourlyPayroll` classes. This will let us verify the code is working as expected. 
  
   - First, set the testing to ON


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
 

   -Now run all the tests on the  `PayrollData` and `HourlyPayroll` classes.

  ```bash
  $ .\bin\ca_test.exe
  ```


13. If any of the tests fail, make changes until everything works as expected




---
---

## Part 3: CREATE THE SALARYPAYROLL CLASS 

Now we will create the SalaryPayroll class. The gross pay for this type of payroll takes no computation at all. The pay rate is the salary amount which is the gross amount the employee will be paid for the pay period. 

The SalaryPayroll class will inherit from the PayrollData class so it will get the data members and functionality that is defined in the PayrollData class. 

There will be no additional private data members so no associated getters and setters. We will need to implement the virtual functions of the base class.


1. In the `salary_payroll.h` file add a declaration for the class named `SalaryPayroll`.

- The include guards are already in the file
- Add a declaration for the class `SalaryPayroll`
- Add the notation at the top of the `SalaryPayroll` class that has it inherit from the `PayrollData` class. Use public inheritance.

- add a public section with the following
  - two constructors and a destructor
    - SalaryPayroll();
    - SalaryPayroll(double pay_rate, std::string name);
    - ~SalaryPayroll();
  - three other methods    
    - double ComputeGross() const;
    - void WriteData(std::ostream &out) const;
    - void PayrollReport(std::ostream &out) const;

2. In the salary_payroll.cpp file `include` the salary_payroll.h header file.


3. Write the `default constructor`. 

- The following will automatically be set by the PayrollData default constructor:
  - pay rate to 0
  - first name to 'it is'
  - last name to 'unknown'
- These values will work fine for us so nothing else needs to be done in the default constructor.


4. Write the `non-default constructor`. 

- This constructor is to call the base class constructor with the values sent for pay rate and name.
  
5. Write the `destructor`. It does not need to do anything. Just add the { }s
 
6. Implement the `ComputeGross` method. This method has no parameters. The method computes and returns the gross pay. 

    For salary payroll, the pay rate for the employee is the gross pay for the pay period. This method just returns the pay rate.
  
7.  Implement the `WriteData` method.
  
    This method will output the data for the salary payroll. The method has one parameter and returns nothing. This parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. It is passed by reference because it actually makes changes to the output stream such as where the file pointer is.


    The WriteData method is to write the following data to the output stream. It is to be written on two lines. Be careful to output the details exactly including capitalization, comma, and spacing.

  - The first line contains two items separated by a space
    - S
    - pay rate
  - The second line contains a name in last, first format and ends with a carriage return
  - For example, consider the payroll data with name Kim Watson that has a pay rate of 2350. The payroll data would look like this:
    ```
    S 2350
    Kim Watson
    ```
    This method will not make changes to the actual object so it can be a const method.
    
8.  Implement the `PayrollReport` method. This prints the payroll data in a more human readable form. It includes the data with labels. This method has one parameter and returns nothing. The parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. 

    The PayrollReport method is to write the following report to the output stream. It is to be written on three lines as shown below.
    ```  
      Name
      Pay Type: salary
      Pay Rate: $rate
      Gross Pay: $gross
    ```
    Replace Name, rate, and gross with the 
    actual values. Be careful to output the details exactly including capitalization, :, $, and spacing.

    Use setprecision and fixed on the output stream to display two digits after the decimal place.

    For example, consider the payroll data with name Kim Watson who has a pay rate of 2350. The payroll report 
    would look like this:
    ```
        Kim Watson
        Pay Type: salary
        Pay Rate: $2350.00
        Gross Pay: $2350.00
    ```
    This method makes no change to the object itself so it can be a const method.


9.  Now we can run the unit tests on the `PayrollData`, `HourlyPayroll`, and `SalaryPayroll` classes. This will let us verify the code is working as expected.
   
  In the tests/CMakeLists.txt (there are three CMakeLists.txt files so be sure to get the one in the tests folder) uncomment the line for salary_payroll by removing the # at the beginning of the line.

  ```
  set(UNIT_TEST_LIST 
    hourly_payroll
    salary_payroll          #uncomment to run salary_payroll tests
    #commission_payroll      #uncomment to run commission_payroll tests
    #process_payroll         #uncomment to run process_payroll tests
  )  
  ```

10.   Now run all the tests on the `PayrollData`, `HourlyPayroll`, and `SalaryPayroll`  classes.

  ```bash
  $ .\bin\ca_test.exe
  ```



11.  If any of the tests fail, make changes until everything works as expected


  
---
---

## Part 4: CREATE THE COMMISSIONPAYROLL CLASS 

Now we will create the CommissionPayroll class. This type employee gets a base wage plus commission. The total pay is computed using pay rate, how many, and base pay. The commission is computed by multiplying the pay rate by how many. For example if the pay rate is $35.50 and the how many is 82, then the commission is $2911.00. The gross pay is the base pay plus commission. So if this same employee has a base pay of 820.00, then the gross pay is $3731.00.

The CommissionPayroll class will inherit from the PayrollData class so it will get the data members and functionality that is defined in the PayrollData class. 

We will need an additional private data member and associated getters and setters. We will add a new method that computes the commission. We will also need to implement the virtual functions of the base class.


1. In the `commission_payroll.h` file add a declaration for the class named `CommissionPayroll`.

- The include guards are already in the file
- Add a declaration for the class `CommissionPayroll`
- Add the notation at the top of the `CommissionPayroll` class that has it inherit from the `PayrollData` class. Use public inheritance.

- Add two private data members.
   - an int that keeps track of how many
   - a double that keeps track of base pay
  
  
- add a public section with the following
  - two constructors and a destructor
    - CommissionPayroll();
    - CommissionPayroll(double pay_rate, int how_many, double base_pay,
                    std::string name);
    - ~CommissionPayroll();
  - two getters
    - int how_many() const;
    - double base_pay() const;
  - two setters
    - void set_how_many(int how_many);
    - void set_base_pay(double base_pay);
  - four other methods    
    - double ComputeCommission() const;
    - double ComputeGross() const;
    - void WriteData(std::ostream &out) const;
    - void PayrollReport(std::ostream &out) const;

2. In the commission_payroll.cpp file `include` the commission_payroll.h header file.


3. Write the implementation for the `getters`. The getters return the values of the matching data members.

4. Write the implementation for the `setters`. 
-  The set_how_many method sets how many to the value sent. If how many is less than 0 it throws an out_of_range exception.
-  The set_base_pay method sets the base pay data member to the value sent. If the base pay sent is less than 0 it throws an out_of_range exception.

5. Write the `default constructor`. 

- The following will automatically be set by the PayrollData default constructor:
  - pay rate to 0
  - first name to 'it is'
  - last name to 'unknown'
- Write the code to set the following:
  - how many to 0
  - base rate to 0


6. Write the `non-default constructor`. 

- This constructor is to call the base class constructor with the values sent for pay rate and name.
- Then it is to call the setters in the CommissionPayroll class to set how many and base pay to the values sent. 
  
7. Write the `destructor`. It does not need to do anything. Just add the { }s


8. Implement the `ComputeCommission` method. This method has no parameters. The method computes and returns the commission. Commission is computed by multiplying pay rate by how many.
 
9. Implement the `ComputeGross` method. This method has no parameters. The method computes and returns the gross pay. Gross pay is computed by adding the base pay and the commission.
  
10. Implement the `WriteData` method.
  
    This method will output the data for the commission payroll. The method has one parameter and returns nothing. This parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. It is passed by reference because it actually makes changes to the output stream such as where the file pointer is.


    The WriteData method is to write the following data to the output stream. It is to be written on two lines. Be careful to output the details exactly including capitalization, comma, and spacing.

  - The first line contains three items separated by a space
    - C
    - pay rate
    - how many
    - base pay
  - The second line contains a name in last, first format and ends with a carriage return
  - For example, consider the payroll data with name Kim Watson that has a pay rate of 41.80, sold 12 items, and has a base pay of 880. The payroll data would look like this:
    ```
    C 41.8 12 880
    Kim Watson
    ```

    This method will not make changes to the actual object so it can be a const method.
    
11. Implement the `PayrollReport` method. This prints the payroll data in a more human readable form. It includes the data with labels. This method has one parameter and returns nothing. The parameter is of type ostream which is an output stream and can be either the standard cout or an ofstream object. 

    The PayrollReport method is to write the following report to the output stream. It is to be written on four lines as shown below.

     ``` 
      Name
      Pay Type: commission
      Pay Rate: $rate
      How Many: how many
      Commission: $commission
      Base Pay: $base
      Gross Pay: $gross
      ```

    Replace Name, rate, how many, commission, base, and gross with the 
    actual values. Be careful to output the details exactly including capitalization, :, $, and spacing.

    Use setprecision and fixed on the output stream to display two digits after the decimal place.

    For example, consider the payroll data with name Kim Watson that has a pay rate of 41.80, sold 12 items, and has a base pay of 880. The payroll report 
    would look like this:

    ```
      Kim Watson
      Pay Type: commission
      Pay Rate: $41.80
      How Many: 12
      Commission: $501.60
      Base Pay: $880.00
      Gross Pay: $1381.60
    ```
    This method makes no change to the object itself so it can be a const method.


12.  Now we can run the unit tests on the `PayrollData`, `HourlyPayroll`, `SalaryPayroll`, and `CommissionPayroll` classes. This will let us verify the code is working as expected.
   
  In the tests/CMakeLists.txt (there are three CMakeLists.txt files so be sure to get the one in the tests folder) uncomment the line for commission_payroll by removing the # at the beginning of the line.

  ```
  set(UNIT_TEST_LIST 
    hourly_payroll
    salary_payroll          #uncomment to run salary_payroll tests
    commission_payroll      #uncomment to run commission_payroll tests
    #process_payroll         #uncomment to run process_payroll tests
  )  
  ```

13.   Now run all the tests on the `PayrollData`, `HourlyPayroll`, `SalaryPayroll`, and `CommissionPayroll`  classes.

  ```bash
  $ .\bin\ca_test.exe
  ```



14. If any of the tests fail, make changes until everything is working as expected




## Part 5: WRITE THE PROCESSPAYROLL FUNCTION (30 POINTS) 

Now that we have all the payroll data classes developed we can process payroll data. We will do this in the ProcessPayroll function. The declaration for this function will be written in the process_payroll.h file and the implementation will be in the process_payroll.cpp file.

This function receives two strings. The first string is the path and filename for the input file that contains the payroll data. The second string is the path and filename for the output file where the payroll reports will be written.

The ProcessPayroll function has a vector of PayrollData pointers. This can contain pointers to HourlyPayroll, SalaryPayroll, and CommissionPayroll objects. The function reads a set of data from the file. Then it creates a new object that matches the payroll type and stores the pointer in the vector. 

After all the data in the file has been read and stored, the ProcessPayroll function loops through the vector and prints a payroll report for each object to the output file. 

There is a sample set of payroll data in the file payroll_week23.txt. You can use this to test your function.



1. In the `process_payroll.h` file add a declaration for the function named `ProcessPayroll`. 
   - The include guards are already in the file
   - Include the string header file
   - Add the declaration for the ProcessPayroll function:
   
   void ProcessPayroll(std::string inputFile, std::string outputFile);


2. In the process_payroll.cpp file `include` all the header files needed.
   - start with the process_payroll.h header file
   - fstream
   - string
   - vector
   - commission_payroll.h
   - include "hourly_payroll.h
   - include "payroll_data.h
   - include "salary_payroll.h


3. Write the implementation for the `ProcessPayroll` function. 

    - declare and open an ifstream object with the filename sent in first parameter
    - if the file does not work for some reason, print an error message and return from the function
    - declare a vector of PayrollData pointers
    - declare variables to hold the following values as they are read from the file
      - type
      - pay rate
      - hours
      - how many
      - base pay
      - name
    - create a loop that will read all the data from the file

      The first thing for each set of payroll data is the payroll type. This is a single character. You can use this in the condition of the while loop. 
      
      For the condition of the while loop read in the payroll type. This loop will read until it gets to the end of the file.

      The payroll data will be different for each type so inside the while loop use a switch statement or an if/else if statement to read the specific data for each type of payroll. Remember to use the ignore and getline functions when reading the name. 

      With that data, create a new object of the matching payroll type and add the pointer to the vector. Put this statement inside a try/catch block. If an exception happens when creating new payroll objects, throw an out_of_range exception that includes the name just read and the message from the exception.

      If the payroll type is something other than H, S, or C throw an out_of_range exception. This can be added in the default section of the switch statement or the trailing else of the if/else if statement depending on which you use.

    - declare and open an ofstream object with the filename sent in second parameter
    - loop through the vector and output a payroll report for each object
    - loop through the vector and do the following
      - delete the dynamic memory pointed to by each pointer
      - set the pointer to NULL
         
        If you are using a for range loop, remember to pass the value by reference so the pointer will actually be changed.

4.  Now we can run the unit tests on the `PayrollData`, `HourlyPayroll`, `SalaryPayroll`, and `CommissionPayroll` classes, and the `process_payroll` function. This will let us verify the code is working as expected.
   
  In the tests/CMakeLists.txt (there are three CMakeLists.txt files so be sure to get the one in the tests folder) uncomment the line for commission_payroll by removing the # at the beginning of the line.

  ```
  set(UNIT_TEST_LIST 
    hourly_payroll
    salary_payroll          #uncomment to run salary_payroll tests
    commission_payroll      #uncomment to run commission_payroll tests
    process_payroll         #uncomment to run process_payroll tests
  )  
  ```

5.    Now run all the tests.

  ```bash
  $ .\bin\ca_test.exe
  ```



6.  If any of the tests fail, make changes until everything is working as expected


---
---


### Publish your code
Now you are ready to publish and test the code. At this point, all the 
tests are expected to pass. 

The next step is to push the code to GitHub. Before you push your code, edit 
the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `line 20` for TO6-2. 


```CMake
18: env: 
19:   - TEST_DIR=TO6-1  
20:   - TEST_DIR=TO6-2
21:   # - TEST_DIR=CA6-1
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module6 repository to the CA6-1 assignment in Canvas.

---
