# CA3.1: Great Britain Monetary System

### Student name:

### Github account:
---
## Skills:
This activity will help you practice the following skills that essential to know for basic programming in `C++`:
  - Define libraries with classes
  - Call methods
  - Operator overload
  - Friend functions

## Knowledge:
This lab will also help you to become familiar with the following important content knowledge in CS:
  - Create C++ libraries with classes. 
  - Improve Object Oriented programming concepts.
  - Use source version control: `git`.
  - Use basic unit testing to validate your code: `catch2`.
---

## Challenge Activity
In the heyday of the British empire, Great Britain used a monetary system based on pounds, shillings, and pence. There are 20 shillings to a pound, and 12 pence to a shilling. The notation for this `old system` used the pound sign, `£`, and two decimal points so that for example, `£5.2.8` meant 5 pounds, 2 shillings, and 8 pence (Pence is the plural of penny).  
The new monetary system, introduced in the 1950s, consists of only pounds and pence, with 100 pence to a pound. For this activity we will call this new system `decimal pounds`. For example 

Old-System | Decimal Pound
---------- | ------------
£5.2.8 | £5.32

Your task is to write a program that can capture in the monetary system in both old and new system. 

**Note: In most compilers you can use the decimal number 156 (hex character constant '\x9c') to represent the pound sign (£). In some compilers, you can put the pound sign into your program directly by pasting it from the Windows Character Map accessory (Alt+0163)**

---
### Files to work on
You are required to work/modify the following files:
- `README.md`: Update the student name an github account.
- All the functions you write, will be part of the library `sterling`. The library consist of these two files: 
  - `src/sterling.cpp`
  - `src/sterling.h`
- Yur "driver/test" file is be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

---

## Part I
Create a class library with the following data items: 
```c++
class Sterling
{
private:
    long pounds_;               // pounds
    int shills_;                // shillings: 20 per pound
    int pence_;                 // pence: 12 per shilling
};

```
Your class should be able to support the following constructors:

```c++
    Sterling();                                     // no-arg constructor
    Sterling(long pounds, int shills, int pence);   // 3-arg constructor

```
The following methods for your setters/getters to interact with your class data members:
```c++
    long pounds() const; 

    int shills() const; 

    int pence() const; 
```
### Sample output Part I
Add code to `main` to test  your code. Sample Output
```bash
.\bin\ca.exe
Constructor with no arguments gives you:
Pounds: 0 Shilling: 0 pence: 0

Constructor with three arguments (12, 18, 9) gives you:
Pounds: 12 Shilling: 18 pence: 9

# Note: you have to convert extra pence to shillings and extra shillings to pounds
Constructor with three arguments (12, 48, 29) gives you:
Pounds: 14 Shilling: 10 pence: 5
```
---
## Part II
Add the following data item: 
```c++
private:
    // ...
    std::string old_system_;    // 13.18.1 
```
Add two another constructors:
```c++
    Sterling(const std::string &old_system); // 1-arg constructor old_system
```
Make sure your constructor will set the `old_system` data member, as well as setting the other 
three data members: `pound_, shills_, and pence_`. 

For this, you probably (optional) need to create
another auxiliary method to help you split the string into the three integers. For example, you can create a boolean method that will help you split the input string based on a record delimeter.
```c++
    bool Split_(std::string stringToBeSplitted, std::string delimiter);
```
The `Split_` function takes two arguments, the string to be parsed, and the delimiter. In our case the delimiter is `"."`. 

Once you have split the string via the delimeter, update the `private` data members with the information extracted. Your function should return `true` if you successfully update the data members, and `false` if you fail to split the string.  


*Hint 1:* Check the `<string>` library, specially the `size()`, `find()`, `to_string()`, `substr()`, among others.   

*Hint 2:* You can convert strings to integers using the `stoi()` function.

The following methods for your setters/getters to interact with your class data members:
```c++
    const std::string &old_system() const;                // gets "7.10.6"
```
### Sample output Part II
Add code to `main` to test  your code. Sample Output
```bash
.\bin\ca.exe

Constructor with one arguments ("12.8.9") gives you:
Pounds: 12 Shilling: 8 pence: 9
 or using old_system() method: 12.8.9
```

---
## Part III
Add another constructors that takes the input in `decimal pound` format. This is the modern format.
```c++
    Sterling(double dec_pounds);              // 1-arg constructor dec pounds
```
For this, you will need to do the conversions from the decimal representation to extract the `pound_, shills_, and pence_` data members. 
```c++
    // You may use something like this
    long pounds;  // integer variables for pounds
    int shills, pence;
	
    // .. 
	// calculate pounds and shills
    // .. 
    // the ceil() function comes in the <math> library
	pence = ceil((dec_pounds*240 - pounds*240 - (shills*12)));
    // ... use setters to set values
```

### Sample output Part III
Add code to `main` to test  your code. Sample Output
```bash
.\bin\ca.exe

Constructor with one arguments (45.67) gives you:
Pounds: 45 Shilling: 13 pence: 5
```

---
## Part IV
Next, we will add a `friend` function to overload the stream output `<<` operator. 
```c++
 friend std::ostream &operator<<(std::ostream &os, const Sterling &sterling);
```
Your method should print a friendly output for the Sterling object.
### Sample output Part IV
You may use this code to test your operator in `main`
```c++
  cout << "Constructor with one arguments (45.67) and using << operator " << endl;
  Sterling s6(45.67);
  cout << s6;

```
Output:
```bash
.\bin\ca.exe

Constructor with one arguments (45.67) and using << operator
pounds_: 45 shills_: 13 pence_: 5
```
---
## Part V
We have been testing a lot our "getters" a lot, but in this part, you will test your "setters" to make sure you can update information in your class.
```c++
    void set_pound(long pnd);
    void set_shills(int sh);
    void set_pence(int pence);
    void set_old_system(const std::string &sterling);     // user types "7.10.6"      
```

### Sample output Part V

```bash
.\bin\ca.exe
Constructor with one arguments (42.27)
pounds_: 42 shills_: 5 pence_: 5
Update pounds to 23
pounds_: 23 shills_: 5 pence_: 5

Constructor with one arguments (42.27)
pounds_: 42 shills_: 5 pence_: 5
Update shills to 67, and adjust numbers
pounds_: 45 shills_: 7 pence_: 5

Constructor with one arguments (42.27)
pounds_: 42 shills_: 5 pence_: 5
Update shills to 31, and adjust numbers
pounds_: 42 shills_: 7 pence_: 7
```
---
## Part VI
Next, we will develop the following comparison operators: 
```c++
    bool operator == (const Sterling &rhs) const;
    bool operator != (const Sterling &rhs) const;
```
Your operators should compare the `pounds_`, `shills_`, and `pence_` data members. If they are the same, return `true` for the `==` and `false` for the `!=` operator. 

### Sample output Part VI

```bash
.\bin\ca.exe
# Testing == operator
Create two objects:
pounds_: 9 shills_: 4 pence_: 7
pounds_: 9 shills_: 4 pence_: 7
object1 and object2 are equal

Create two objects:
pounds_: 9 shills_: 4 pence_: 7
pounds_: 12 shills_: 4 pence_: 2
object1 and object2 are not equal

# Testing != operator
Create two objects:
pounds_: 67 shills_: 17 pence_: 7
pounds_: 33 shills_: 2 pence_: 2
object1 and object2 are not equal

Create two objects:
pounds_: 33 shills_: 2 pence_: 2
pounds_: 33 shills_: 2 pence_: 2
object1 and object2 are equal
```

---
## Part VII
Next, add a method to convert back to `decimal pound` system. Your method should take
the `pounds_`, `shills_`, and `pence_` data members 
```c++
    float decimal_pound();
```
This method will return the decimal pound form of the Sterling. For this you need to use the following formula:
```c++
  pounds + shills/20.0 + pence/240.0
```
### Sample output Part VII

```bash
.\bin\ca.exe
Constructor with one arguments (12.27)
pounds_: 12 shills_: 5 pence_: 5
Using decimal_pound() operator 12.2708
```

---

## Part VIII
Finally, add some arithmetic operator overload to add and subtract to Sterling objects
```c++
    Sterling operator + (Sterling s2) const; // sterling + sterling
    Sterling operator - (Sterling s2) const; // sterling - sterling
    //
    // or with friend function
    //
    friend Sterling operator + (Sterling const &s1, Sterling const &s2); // sterling + sterling
    friend Sterling operator - (Sterling const &s1, Sterling const &s2); // sterling + sterling
```
Hint: Remember to use `static_cast<double>()` to convert from `int` type to `double`.

### Sample output Part VIII
```c++
    // You may use this code to test your operators
  cout << "\nCreate two objects:" << endl;
  Sterling s13(33.15);
  Sterling s14(6.21);
  cout << s13 << endl;
  cout << s14 << endl;
  Sterling s15 = s13 + s14;
  cout << "The sum of obj1 + obj2 = " << s15.decimal_pound() << endl;
  ```
Sample Output
```bash
.\bin\ca.exe
# Testing + operator
Create two objects:
pounds_: 33 shills_: 2 pence_: 12
pounds_: 6 shills_: 4 pence_: 2
The sum of obj1 + obj2 = 39.3083

# Testing - operator
Create two objects:
pounds_: 33 shills_: 2 pence_: 12
pounds_: 6 shills_: 4 pence_: 2
The difference of obj1 - obj2 = 26.9417
```

## Validate your code
Once you are satisfied with your work, run our unit test file:
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

```bash
# Use the following tag to validate Part 1
$ ./bin/ca_test.exe -s [part1]

# Use the following tag to validate Part 2
$ ./bin/ca_test.exe -s [part2]

# Use the following tag to validate Part 3
$ ./bin/ca_test.exe -s [part3]

# Use the following tag to validate Part 4
$ ./bin/ca_test.exe -s [part4]

# Use the following tag to validate Part 5
$ ./bin/ca_test.exe -s [part5]

# Use the following tag to validate Part 6
$ ./bin/ca_test.exe -s [part6]

# Use the following tag to validate Part 7
$ ./bin/ca_test.exe -s [part7]

# Use the following tag to validate Part 8
$ ./bin/ca_test.exe -s [part8]
```

### Finally run ALL Test your code:
```bash
# Run test with the tag
$ .\bin\ca_test.exe

# To list all available tags
$ .\bin\ca_test.exe -t

# For summary information in compact mode
$ .\bin\ca_test.exe -s -r compact

# Using ctest
$ ctest
```

---
### Publish your code
Before you push your code, you need to edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `TEST_DIR=CA3-1`. 

```CMake
env: 
  - TEST_DIR=TO3-1
  - TEST_DIR=TO3-2
  - TEST_DIR=CA3-1
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

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