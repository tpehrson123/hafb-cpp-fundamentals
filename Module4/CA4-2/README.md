# CA4-1: The Template KeyValue Class

### Student name:

### Github account:
---

## Purpose:
It can be efficient to create a single class that can work with a 
variety of types. To accomplish this a template class (a pattern) can be 
created. 
When this template class is called, the compiler will automatically create 
a complete class that matches the type in the object declaration. 

This is one form of code reuse.


## Skills:
This activity will help you practice the following skills that are essential to 
know for basic programming in `C++`:
- Define template class
- Use a template class with a C++ primitive data type
- Use a template class with a user defined data type
- Git and Github
- Catch2

## Knowledge:
This lab will also help you to become familiar with the following important 
content knowledge in CS:  
  - generic programming
  - code reuse
  - Source version control
  - Use unit testing to validate code


## Challenge Activity
For this activity we will create a class for a key-value container. This
container works with two different variable types. One type is for the key
and the other type is for the value. The class stores key-value pairs.

For example, there may be a KeyValue object that stores the month and the
number of days in the month. The KeyValue object could have keys of type int
and values of type int.

KeyValue<int, int, 12> days_in_month_number;

This object would have key-value pairs of 

    1 31
    2 28
    3 31
    4 30
    5 31
    6 30
    7 31
    8 31
    9 30
    10 31
    11 30
    12 31

Another KeyValue object that stores the month and the
number of days in the month could have keys of type string
and values of type int.

KeyValue<string, int, 12> days_in_month_string;

This object would have key-value pairs of 

    January 31
    February 28
    March 31
    April 30
    May 31
    June 30
    July 31
    August 31
    September 30
    October 31
    November 30
    December 31

Another KeyValue object could use a name for the key and their favorite color  
as the value. The
key (name) would be of type string
and value (color) would be of type string.

KeyValue<string, string, 20> days_in_month_string;

This object would have key-value pairs of 

    John green
    Mary blue
    Kim lavender
    Kelly yellow
    Walter orange


---
### Files to work on
We will be working in the CA4-2 folder of the Module4 repository. You can work 
on and modify the following files:
- `README.md`: Update the student name and github account.
- There will also be a header file `src/key_value.h` where we will write the 
   KeyValue template class.
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

## Part 1: BEGIN THE TEMPLATE KEYVALUE CLASS (10 POINTS)

The `KeyValue` class is a template class so that it can be used with a 
variety of types. The KeyValue class is a container for key-value pairs. 



1. In the `key_value.h` file begin the `KeyValue` class.
   - add include guards to protect the header file from being included more
     than once
   - add the template header that includes three parts
     - the variable type for the `keys`
     - the variable type for the `values`
     - an int that specifies the maximum size of the KeyValue container
   - add the class named `KeyValue`
   - add private data members to store the keys and the values and one to keep
     track of the current size

   - add a public section with the following method declarations
   ```
       KeyValue();
       ~KeyValue();
       int Size() const;
       bool Found(K key) const;
       void Add(K key, V item);
       V ValueAt(K key) const;
       bool Full() const;
       bool Empty() const;
       bool RemoveOne(K key);
       int RemoveAll(K key);
   ```  
    Notice that I have used `K` for the variable type for keys and `V` for the 
    variable type for values. You can follow this pattern or use a different
    name for the types. This will not matter when doing the unit tests.

   - add the following method declaration in the private section

    ```
        int Find(K key) const;
    ```

2. Write the implementation for the `default constructor`. This constructor 
   initializes the size to 0. 
   
   Remember to put the template header above this method definition and to add 
   the name of the class followed by the template variables before the name of 
   the method. Remember this each time you add a method implementation outside 
   the class declaration.
   
   Also, remember to keep the function implementations in the .h file.

3. Write the `destructor`. It does not need to do anything. Just add the { }s
   
4. Write the implementation of `Size` method. This is a getter for the 
   private data member `size` and simply returns the current size of the 
   KeyValue container. This data member keeps track of how many key-value
   pairs are currently being stored in the KeyValue container. 


---
---

## Part 2: THE ADDING AND FINDING METHODS (10 POINTS)

The `Add` method provides the functionality to add key-value pairs to the 
container. Then the `Find`, `Found`, and `ValueAt` methods provide the means
to identify if a key exists in the KeyValue container and what the matching 
value is for that key.

1. Write the implementation for the `Add` method. 
   
   This method receives two values.
    - a new `key`
    - a new `value`

   It adds these to the key and value containers and increases the size. If 
   the KeyValue container is full, it throws an out_of_range exception that
   reports the KeyValue container is full.

   It returns nothing. 

2. Write the implementation for the private method `Find`. This method can 
   be used be other methods in the the KeyValue class. 
   
   This method receives one value.
    - a `key`

   It looks in the key container for this key.

   It returns either
      - the index for the first matching key. 
      - a -1 if the key is not found
   
   This index can be used 
   to access the key or the matching value in the containers.

3. Write the implementation for the `Found` method.
   This method receives one value.
    - a `key`

   It looks in the key container for this key. (Notice that this is what the
   Find method does. This is an opportunity to reuse code by calling the 
   Find method instead of re-writing code.)

   This method can be used to make sure a key exists before trying to 
   access the matching value. Using this check, can avoid an exception.

   It returns either
      - `true` if the key is found
      - `false` if the key is not found
   
4. Write the implementation for the `ValueAt` method.
   This method receives one value.
    - a `key`

   It looks in the key container for this key. When the key is found, it 
   returns the value that matches the key. When the key is not found it
   throws an out_of_range exception that reports the key was not found.

   It returns 
      - the first `value` that matches the key
   

---
---

## Part 3: THE EMPTY AND FULL METHODS (5 POINTS)

These methods report if a KeyValue container is full or empty. This information
can be used to avoid trying to add an item to a full container or
trying to remove an item from an empty container. When users of this class
use these methods effectively, they can avoid exceptions being thrown.

1. Write the implementation for the `Empty` method. 
   
   This method receives nothing.

   It returns true if the KeyValue container is empty and false otherwise. 

2. Write the implementation for the `Full` method. 
   
   This method receives nothing.

   It returns true if the KeyValue container is full and false otherwise. 


---
---

## Part 4: THE REMOVEONE AND REMOVEALL METHODS (15 POINTS)

The `RemoveOne` and `RemoveAll` methods provide the functionality to 
remove items from the KeyValue container. 

1. Write the implementation for the `RemoveOne` method. 
   
   This method receives one value.
    - a `key`

   It removes the first occurrence of the key and its matching value. To do
   this all key-value pairs that come after the removed item will need to be
   shifted to fill the gap.

   It returns  
      - `true` if the item was found and removed
      - `false` if the item was not found in the KeyValue container

2. Write the implementation for the `RemoveAll` method. 
   
   This method receives one value.
    - a `key`

   It removes the all occurrences of the key and its matching value(s).

   It returns the number of items removed.
   

---
---

## Part 5: OVERLOAD THE == OPERATOR (15 POINTS)

It is handy to be able to write a KeyValue object using the << operator. To 
write a KeyValue object, we will write each 
key-value pair with a : and a space between them followed by a carriage return. 
  ```
  key: value

  ```

For example, the KeyValue that has months and number of days in the month 
would be output like this.
  ```
    January: 31
    February: 28
    March: 31
    April: 30
    May: 31
    June: 30
    July: 31
    August: 31
    September: 30
    October: 31
    November: 30
    December: 31

  ```

The KeyValue that has names and colors would be output like this.

  ```
    John: green
    Mary: blue
    Kim: lavender
    Kelly: yellow
    Walter: orange

  ```

1. Overload the << operator for the KeyValue class.

- This method is a friend method
- It returns an ostream object by reference
- It is named operator<<
- The first parameter is an ostream object passed by reference
- The second parameter is a value of the variable type KeyValue passed by
  reference. No change is made to this parameter so set it to const.
- Put the complete function implementation inside the class declaration
- The method is to output the text and values described above. Be careful to
  add the :, spaces, and carriage returns as shown so it will pass the 
  unit tests.

Now the KeyValue class uses the << operator to write out the key-value
pairs. This means whatever type the key is and whatever type the value is 
will need to work with the
<< operator. Ints, doubles, and strings all work with the << operator. 
However, the Carton class does not. To be able to create a KeyValue that 
contains Cartons we will need to overload the << operator in the Carton
class.

To do this we need to specify what it means to output a Carton object. The
output will look like this:
  ```
  Carton length x width x height
  ```
The words length, width, and height will be replaced by the actual values.
  ```
  Carton 16 x 12 x 14

  Carton 19.8 x 13.0 x 16.2
  ```


1. Overload the << operator for the Carton class.

- In the carton.h file write the method declaration
  - it returns an ostream object by reference
  - it is named operator<<
  - it has two parameters
    - The first parameter is an ostream object passed by reference
    - The second parameter is a value of the variable type (T) passed by
      reference. No change is made to this parameter so set it to const.

  
- In the carton.cpp file write the method implementation 
  - The method is to output the text and values described above
  - There is a space between Carton and length
  - There is a space on both sides of each x
  - There is NO carriage return or space after height
  - To limit the output to display only a single digit after the decimal
    place, set the output to fixed and precision to 1 

Note: The keys are compared using the == operator in several of the methods.
This means whatever type the key is will need to work with the == operator.
We will be testing the KeyValue class with ints and strings as the key type.
We will not use any type for keys that need to overload the == operator.

---
---


## Part 6: DEMONSTRATE USING THE KEYVALUE TEMPLATE CLASS WITH A VARIETY OF TYPES (15 POINTS)

The unit tests will test KeyValue objects using the following
six types.

  | Key    | Value  |
  | ------ | ------ |
  | int    | int    |
  | int    | string |
  | int    | Carton |
  | string | int    |
  | string | string |
  | string | Carton |

Demonstrate how to create and use KeyValue objects.

1. In the `main.cpp` file create two KeyValue objects with different types from
  the table above. 
  Use each type of key, int and string. Have one work with
  values of type Carton and the other work with values of type int or string.
  For each of the two types do the following.

     - Define a KeyValue object
     - Add 3-12 key-value pairs
     - Call the ValueAt method to get a value
       - This can potentially throw an exception. Handle this by choosing one
         (not both) of the following 
           - use a try/catch block to handle the exception
           - use the Found method to make sure the key exists before calling the 
             ValueAt method
     - Remove one or more key-value pairs
     - Output the KeyValue object to the screen using the << operator


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
  PS C:\Users\Linda\C++ Fundamentals\C++ Fundamentals-module4\CA4-2\build> .\bin\ca_test.exe
  ===============================================================================
  All tests passed (553 assertions in 83 test cases)
```

### Validate Part 1
Test your code with tag `[start]`:
 
```bash
$ .\bin\ca_test.exe [start]
```

### Validate Part 2
Test your code with tags `[add]`, `[found]` and `[value]`:
 
```bash
$ .\bin\ca_test.exe [add], [found], [value]
```

### Validate Part 3
Test your code with tags `[empty]` and `[full]`:

  ```bash
  $ .\ca_test.exe [empty], [full]
  ```

### Validate Part 4
Test your code with tags `[remove_one]` and `[remove_all]`:

  ```bash
  $ .\ca_test.exe [remove_one], [remove_all]
  ```
  
### Validate Part 5
Test your code with tag `[insertion]`:
```bash
$ .\bin\ca_test.exe [insertion]
```

### Validate Part 6
Part 6 will not be tested by the unit tests. It will be manually reviewed.

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
directory of your project. Uncomment `line 23` for CA4-2. 


```CMake
18: env: 
19:  - TEST_DIR=TO4-1  
20:  - TEST_DIR=TO4-2
21:  - TEST_DIR=CA4-1
22:  - TEST_DIR=TO4-3
23:  - TEST_DIR=CA4-2
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module4 repository to the CA4-2 assignment in Canvas.

---
