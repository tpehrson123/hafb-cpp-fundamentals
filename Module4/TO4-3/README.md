# TO4-3: The Template Stack Class

### Student name:

### Github account:
---

A stack is a widely used data structure. It stores data by adding new elements
at the top of the stack. It allows access to only the top element in the stack.
And when you remove an element, it removes the top element. All the action
happens at the top of the stack.

You can think of it like a stack of plates. When you want one plate, you take
the top one. When you add a new plate to the stack, you add it to the top
of the stack. When you look at the stack of plates it is mostly the top one
that you see.

Because we might want to have stacks that hold different types, we will create
a template stack class. Then we will test it with ints, strings, and Cartons.


---
### Files to work on
We will be working in the TO4-3 folder of the Module4 repository. You can work 
on and modify the following files:
- `README.md`: Update the student name and github account.
- There will also be a header file `src/stack.h` where we will write the 
   template Stack class.
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

## Part 1: BEGIN THE TEMPLATE STACK CLASS

The `Stack` class is a template class so that it can be used with a 
variety of types. It needs a private data member to store the values. 

Note: The instructions 
use an array but all the storing and retrieving of the values is internal
to the class so it does not need to be an array. If there is another type
of data structure that you are confident working with, you may use it. You 
will need to adapt the data members and methods to work with this other 
data structure. 

1. In the `stack.h` file begin the `Stack` class.
- the include guard is already in the stack.h header file
- add the template header that includes two parts
  - the variable type
  - an int that specifies the maximum size of the stack
- add the class named Stack
- add two private data members
   - an array of type T (the variable type) and the variable size  
   - an int to keep track of the top of the stack 
- add a public section with the following method declarations
  - Stack();
  - Stack(T item);
  - ~Stack();
  - void Push(T item);
  - T Pop();
  - T Top() const;
  - int Size() const;
  - bool Empty() const;
  - bool Full() const;

2. Write the implementation for the default constructor. This constructor 
   initializes the top to 0. 
   
   Remember to put the template header above this method definition and to add 
   the name of the class followed by the template types before the name of the
   method. Remember this each time you add a method implementation outside 
   the class declaration.
   
   Also, remember to keep the function implementations in the .h file.

3. Write the implementation of Push method. This method adds the item to the 
   top of the stack and changes the variable 
   that is keeping track of the top.
   If the stack is full when Push is called, there is no place to put another 
   item in the stack.
   When this happens, throw an out_of_range exception.

    When you are creating this, you might want to print the array and the 
    top position so 
    you can see how it is changing.

4. Now you can write the other constructor. This constructor needs to 
   initialize the top to 0 and call the Push method to add the one item sent.

6. Write the destructor. It does not need to do anything. Just add the {}s

---
---

## Part 2: THE POP AND TOP METHODS

A stack removes items from the top of the stack. The method that does this is 
the Pop method. 

You can also see the value at the top of the stack without making any changes
to the stack. The Top method does this.

1. Write the Pop method. This method does two things. It moves the top down one 
   and returns the item 
   at the top of the stack. (Be careful about order
   on this one. Once you return from a method, nothing else happens. So the 
   return statement has to be last.)

   If the stack is empty when Pop is called, throw an out_of_range exception.

   Notice how the item is actually still sitting in the array. However, 
   since the top has changed, we will not see it.


2. Write the Top method. This method returns the item at the top of the stack.
   If the stack is empty when Top is called, throw an out_of_range exception.

---
---

## Part 3: THE SIZE, EMPTY, AND FULL METHODS

1. Write the Size method. This method returns how many items are 
   currently in the stack.

2. Write the Empty method. This method returns true when the stack is 
   empty. When there are items in the stack, it returns false.

3. Write the Full method. This method returns true when the stack is 
   full. When there is still room for additional items in the stack, it 
   returns false.
---
---


## Part 4: OVERLOAD THE << OPERATOR

It is handy to be able to write a Stack object using the << operator. But we
have to decide what it means to write a Stack. We will write some of the 
details that describe the stack.

Note: Be careful to write it just as shown here including caps and spaces.
It will need to match exactly to pass the tests.

We will write the maximum size of the stack followed by a carriage return. 
The rest of what we write will
depends on whether the stack is empty or not. If the stack is empty write 
The stack is empty followed by a carriage return. Here is an example of 
an empty stack that has a maximum
size of 5:

```
Stack maximum size: 5
The stack is empty

```

When the stack is not empty, we will write the current size followed by a 
carriage return and the value
at the top of the stack followed by a carriage return. Here is an example of 
a stack that has a maximum
size of 20, a current size or 4 and 302 is the item at the top of the stack:

```
Stack maximum size: 20
Stack current size: 4
Value at top of stack: 302

```

1. Overload the << operator for the Stack class.

- This method is a friend method
- It returns an ostream object by reference
- It is named operator<<
- The first parameter is an ostream object passed by reference
- The second parameter is a value of the variable type (T) passed by
  reference
- Put the complete function implementation inside the class declaration
- The method is to output the text and values described above

Now the Stack class uses the << operator to write out the top value
in the stack. This means that any type used to define a Stack must also
work with the << operator. We will be defining Stacks using the Carton type
so we will need to overload the << operator for the Caron class.



2. Overload the << operator for the Carton class.

  In the carton.h file, write the method declaration.

- This method 
  - returns an ostream object by reference
  - is named operator<<
  - has two parameters
    - the first parameter is an ostream object passed by reference
    - the second parameter is a value of the variable type (T) passed by
  reference. No change is made to this parameter so it can be set as const.

  In the carton.cpp file, write the method implementation.

- Put the complete function implementation inside the class declaration
- The method is to output the text and values described above

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
  PS C:\Users\Linda\C++ Fundamentals\C++ Fundamentals-module4\TO4-3\build> .\bin\ca_test.exe
  ===============================================================================
  All tests passed (426 assertions in 34 test cases)
```


### Validate by Method

These tags test the methods of the Stack class.
  
      [constructor]
      [push]
      [size]  
      [top]
      [pop]
      [empty]
      [full]
      [insertion]


### Validate by Type

These tags test the Stack class when defined using different types.

      [carton]
      [string]      
      [int]
 
---
---
### Publish your code
Now you are ready to publish and test the code. At this point, all the 
tests are expected to pass. 

The next step is to push the code to GitHub. Before you push your code, edit 
the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `line 22` for TO4-3. 


```CMake
18: env: 
19:  - TEST_DIR=TO4-1  
20:  - TEST_DIR=TO4-2
21:  - TEST_DIR=CA4-1
22:  - TEST_DIR=TO4-3
23: # - TEST_DIR=CA4-2
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module4 repository to the TO4-3 assignment in Canvas.

---
