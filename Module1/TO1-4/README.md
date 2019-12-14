# TO1-4: CALCULATING AGE USING PASS BY VALUE ARGUMENTS
James wants to write a C++ program to calculate what the age of a person will be after five years by providing their current age as an `input`.

To implement such a program, he is going to write a function that takes a person's age by value and computes how old they will be in 5 years, and then prints it on the screen:

- Let's begin by creating a new library, `age.cpp` and `age.h`.
- Again, our code is organize in project form:
  ```
    .
    ├── CMakeLists.txt
    ├── .gitignore
    ├── .travis.yml
    ├── externals
    │   └── catch2
    │       └── catch.hpp
    ├── README.md
    ├── src
    │   ├── CMakeLists.txt
    │   ├── age.cpp
    │   ├── age.h
    │   └── main.cpp
    └── tests
        ├── CMakeLists.txt
        └── age_test.cpp

  ```
    - `src` folder: all our code will go here. This is basically the only folder you will work on.
    - `externals` folder (DO NOT MODIFY): contains our unit test library
    - `test` folder (DO NOT MODIFY): contains our unit code
    - The `.gitignore` hidden file instructs git to ignore our build folder and anything else we do not want to track.
    - The `.travis.yml` file controls which test `travis` is validating for us. As you complete the different TO and CA activities, you will modify this file (see below). This is what I will use to verify your code.  

- In our `src` folder, define these functions `ByValueAgeIn5Years` and `CurrentAge` , as illustrated here. Make sure that the value in the calling code does not change:
    ```c++
    // age.h
    void ByValueAgeIn5Years(int age);
    int CurrentAge(int age);
    // age.cpp
    void ByValueAgeIn5Years(int age) 
    {
        age += 5;
    }
    
    int CurrentAge(int age) 
    {
      return age;
    }
    ```
- Now, in `main()`, call the function we created in the previous step by passing the variable `age` as a value:
    ```c++
    int main() 
    {
        int age = 95;
        cout << "Current age: " << age << endl;
        ByValueAgeIn5Years(age);
        cout << "In 5 years, your age is: " << CurrentAge(age) << endl;
    }
    ```
---
**Note:**
*Pass by value should be the default way of accepting arguments: always use it unless you have a specific reason not to.*

### Compile and run your code
Compile your code (see below) and run it.  
Sample Output:
```bash
$ .\bin\ca.exe
Current age: 95
In 5 years, your age is: 95
```
Is this the output you expected?  
In the next section you will hep James fix this issue. 
# CALCULATING INCREMENTATION OF AGE USING PASS BY REFERENCE 
Now, help James create another function that will modify the age variable as we intended in the previous section.

- Let's write another function that accepts its parameters by reference:

```c++
// age.h
void ByReferenceAgeIn5Years(int& age);

// age.cpp
void ByReferenceAgeIn5Years(int& age)
{
    age += 5;
}
```

Now, in `main()`, call the function we created in the previous step by passing the variable age as a reference:
```c++
  int age = 15;
  cout << "Current age: " << age << endl;
  //ByValueAgeIn5Years(age);
  ByReferenceAgeIn5Years(age);
  cout << "In 5 years, your age is: " << CurrentAge(age) << endl;
  if (age >= 18)
  {
      cout << "Congratulations, you can vote! " << endl;
  }
```
### Compile and run your code
Compile your code (see below) and run it.  
Sample Output:
```bash
$ .\bin\ca.exe
Current age: 13
In 5 years, your age is: 18
Congratulations, you can vote!
```
Is this the output you expected?  
Yes!

### Validate your code
Once you are satisfied with your work, run our unit test file with the `TO1-4` tag to validate your code:
```bash
  # For a detail information on the unit tests 
  $ .\bin\ca_test.exe [TO1-4] -s
```
Your output should be something like this: 
```bash
............................................................................
... 
with expansion:
  10 == 10
with message:
  TO Activity 3 Points

===============================================================================
All tests passed (2 assertions in 2 test cases)
```
---
### Publish your code
Before you push your code, you need to edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Make sure you uncomment `line 20` for TO1-4 activity. 

```CMake
18: env: 
19:  - TEST_DIR=TO1-3
20:  - TEST_DIR=TO1-4
21:  # - TEST_DIR=TO1-5
22:  # - TEST_DIR=TO1-6
23:  # - TEST_DIR=CA1-1
24:  # - TEST_DIR=CA1-2
```

Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---

### Notes to compile and run the code.

#### Using `CMake` by "hand" (recommended way):

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
$ .\bin\ca
```
#### Using `g++`:
```bash
$ g++ -o ca main.cpp fibo.cpp
# Now you can run your code
$ .\ca.exe
```