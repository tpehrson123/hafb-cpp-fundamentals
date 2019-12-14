# TO6-1: Allocating Dynamic Memory

### Student name:

### Github account:
---

## Purpose:
In this activity we are going to practice dynamically allocating memory. We will write two functions. The first one will dynamically allocate an array. The second will work with a vector of pointers, dynamically allocate objects, and store the pointers to the newly created objects in the vector.

These are two very different ways to use pointers. Being able to do both will help you be able to create and use dynamic memory.

Another important detail of using dynamic memory is managing the memory once it is created. The code will be reviewed to make sure pointers are used and any memory that is dynamically allocated is deleted correctly.


Note: This is an academic exercise. The work in these functions can be done in other ways. The purpose of this activity is to provide practice in creating and using dynamic memory. To receive credit, the functions must be implemented as instructed.  

---
### Files to work on
We will be working in the TO6-1 folder of the Module6 repository. You can work 
on and modify the following files:
- `README.md`: Update the student name and github account.
- There will also be a  library `using_pointers` that contains two functions. The library consists of these two files:
  - `src/using_pointers.cpp`
  - `src/using_pointers.h`
- Our "driver" will be `src/main.cpp`.
- While running the code you will create additional output files.
  
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

## Part 1: ADD THE FUNCTION DECLARATIONS TO THE USING_POINTERS HEADER FILE 

We will be creating two functions. The declaration for those functions need to be in the `using_pointers.h` header file.

1. Include the string header file
   
2. Add the declaration for the WriteStats function.

  void WriteStats(std::string input_file, std::string output_file);


3. Add the declaration for the WriteCartons function.
  
  void WriteCartons(std::string input_file, std::string output_file);


---
---

## Part 2: IMPLEMENT THE WRITESTATS FUNCTION 

The WriteStats function has two string parameters. The first string is the path and filename for an input file. The second string is the path and filename for an output file. The WriteStats function opens and reads the input file. The input file we will use is called integers.txt. 

The integers.txt file has many integers, each separated with a space. The first integer specifies how many integers are in the file (not counting itself). The function is to create an integer array that is just this size and fill it with the integers from the file.

Once the array has been created and filled, the function is to compute the total and the average and write these stats to the output file.

There are comments in the `using_pointers.cpp` file. Put the matching code right after each comment. 




1. Include the following header files

  - using_pointers.h
  - fstream
  - string
  - vector
  - carton.h

2. In the `using_pointers.cpp` file write the `WriteStats` function.

- Define and open an ofstream object using the filename sent for the output file


- Define and open an ifstream object using the filename sent for the input file
- Test the ifstream to make sure it worked. If it does not open as expected, write the following line to the output file and end the function. Have the statement be exact include capitalization, spacing and the ...s.

  Unable to open file. Shutting down...

- Read the first integer from the file. This specifies how may integers remain in the file.
- Dynamically allocate an integer array exactly this size.
- Fill the array by reading all the remaining integers in the file and storing them in the array.
- Close the input file.
- Loop through the array and compute the total and the average. Be careful to use static_cast when computing the average so you don't get integer division.
- Output the number of integers (not counting the first integer), the total, and the average to the output file. Put each value on a single line.
- Delete the dynamically allocated array.
- Close the output file.
  
---
---

## Part 3: IMPLEMENT THE WRITECARTONS FUNCTION 

The WriteCartons function has two string parameters. The first string is the path and filename for an input file. The second string is the path and filename for an output file. The WriteCartons function opens and reads the input file. The input file we will use is called cartons.txt. 

The cartons.txt file contains Carton object data, each on a separate line. The function is to create a vector that contains Carton pointers. Then it is to read the input file and create a new Carton object for each set of data and store the pointer to that Carton object in the vector.

Once all the data has been read from the file, the function will loop through the vector and write the Carton objects to the output file.  

There are comments in the `using_pointers.cpp` file. Put the matching code right after each comment. 




1. In the `using_pointers.cpp` file write the `WriteCartons` function.

- Define and open an ofstream object using the filename sent for the output file


- Define and open an ifstream object using the filename sent for the input file
- Test the ifstream to make sure it worked. If it does not open as expected, write the following line to the output file and end the function. Have the statement be exact include capitalization, spacing and the ...s.

  Unable to open file. Shutting down...

- Declare a vector or Carton pointers.
- Loop through file and read the Carton data. For each set of data do the following
  - create a new Carton object
  - store the pointer to this new Carton in vector
- Close the input file.
- Once the data has all been read from the file, loop through vector and write cartons to output file using the WriteCarton member function.
- Finally, loop through the vector and do the following.
  - delete the memory pointed to by the pointer
  - set the pointer to NULL
- Close the output file.
 
  
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
 


### Validate by Function

To validate the WriteStats function, use the write_stats tag. 

```bash

$ .\bin\ca_test.exe [write_stats]

```

To validate the WriteCartons function, use the write_cartons tag. 

```bash

$ .\bin\ca_test.exe [write_cartons]

```


To validate all the code, use no tag. 

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
directory of your project. Uncomment `line 19` for TO6-1. 


```CMake
18: env: 
19:   - TEST_DIR=TO6-1  
20:   # - TEST_DIR=TO6-2
21:   # - TEST_DIR=CA6-1
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---
### Submit to Canvas
Submit a URL to your Module6 repository to the TO6-1 assignment in Canvas.

---
