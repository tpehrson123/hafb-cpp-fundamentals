# CA1-2: WRITING A MATH LIBRARY FOR A 4D GAME

### Student name:

### Github account:
---
## Purpose:
This is an introductory assignment. The purpose of this assignment is to help you review all the basic programming concepts plus some new `C++` concepts.  

## Skills:
This activity will help you practice the following skills that essential to know for basic programming in `C++`:
  - Define libraries
  - Call functions
  - Define namespaces

## Knowledge:
This lab will also help you to become familiar with the following important content knowledge in CS:
  - Setting and working in your development environment either Windows or Linux.
  - Review basic programming concepts.
  - Use source version control: `git`.
  - Use basic unit testing to validate your code: `catch2`.
---

## Challenge Activity
Maria wants to implement a math library for the video game she is making. It will be a 3D game, so she will need to operate on points representing the three coordinates: `x, y, and z`.

Before she can code this library, she needs to create some support functions for her library. Your challenge activity consist in helping her code these functions 

---
### Files to work on
You are required to work/modify the following files:
- `README.md`: Update the student name an github account.
- All the functions you write, will be part of the library `math3dlib`. The library consist of these two files: 
  - `src/math3dlib.cpp`
  - `src/math3dlib.h`.
- Our "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

---
## Part 1: USING PASS BY VALUE (10 POINTS)
*Note*: As you write the next set of functions, keep in mind the following
  * Should it take the arguments by value or reference?
  * Should it return by value or by reference?*
---
In your library, define all of the following function under the `video namespace`. 
### Distance() function
The first task is to write a function named `distance()` that takes two integer numbers and returns their distance between them. 

1. In your header file, `math3dlib.h`, declare the function:
    ```c++
    int video::Distance(int point_a, int point_b);
    ```
  *note: remember to take the absolute value of the distance before you return it*.

2. In your implementation file, `math3dlib.cpp`, define the function. Your function should `return` the distance of the two input values. 

3. Test your function by calling it in `main()` and display the result. You may use `cin` to take the two integer numbers as input from the user.

4. [Compile and run](#How-to-compile-and-run-the-code) your code (see below).

### Sample output
```bash
$ .\bin\ca.exe
********Part 1********
Enter two integer points: 45 23
Distance between 45 and 23 = 22
 
 $ .\bin\ca.exe
********Part 1********
Enter two integer points: 14 86
Distance between 14 and 86 = 72
```
### Validate your code
Once you are satisfied with your work, run our unit test file: Test your code with tag `[distance1]`:
 
```bash
# Run test with the tag 
$ .\bin\ca_test.exe [distance1] -s
...
...
with expansion:
  17 == 17
with message:
  Part 1: 10 points

===============================================================================
All tests passed (2 assertions in 2 test cases)
```
---
---

## Part 2: USING PASS BY REFERENCE AND PASS BY VALUE (30 POINTS)

### Circumference() function
Now, help Maria to compute a function to calculate the `Circumference` of a circle from its radius (defined as `2*pi*r`). This is going to help her understand how far enemies can see. 

1. Once again, the function declaration should go in your header file (`math3dlib.h`), and the function definition in your implementation file (`math3dlib.cpp`). This should be your function signature:
```c++
float video::Circumference(float radius);
``` 

2. You need to declare a `constant` value for `pi` for the duration of the program (which can be declared globally in the `math3dlib.cpp` file).

3. Test your function by calling it in `main()` and display the result. You may use `cin` to take the radius as input from the user.
    - If the user enters a `negative` number, your function should `return 0`.

4. [Compile and run](#How-to-compile-and-run-the-code) your code (see below).
### Sample output
```bash
$ .\bin\ca.exe
********Part 2********
Enter circle radius: 23.6
With radius 23.6 circumference = 148.208

$ .\bin\ca.exe
********Part 2********
Enter circle radius: -8.1
With radius -8.1 circumference = 0
```
### Validate your code
Once you are satisfied with your work, run our unit test file: Test your code with tag `[circumference]`:
 
```bash
# For a detail information on the unit tests 
$ .\bin\ca_test.exe [circumference] -s
```

### BiArray() function
Next, define a bi-dimensional array 
`(3x3)` of type integer and write a program to assign each element 
the addition of their corresponding index entries in the array:
For this function, you will need the `array` library
   ```c++
   #include <array>
   ```

The first library function should accomplish the following:
1. In your header file, `math3dlib.h`, declare the function 
   ```c++
   int video::BiArray();
   ``` 
2. In your implementation file, `math3dlib.cpp`, define the function. 
   - Begin your function by declaring an array of integers of size **3x3**.
   ```c++
    // Array of arrays
    array<array<int,3>,3> foo {{
    {11, 25, 73}, 
    {44, 51, -6}, 
    {-72, 80, 92}
    }};
   ```
  - Iterate over each element of the array using a nested `for` 
   loop and display the values of all the `x` and `y` elements.

  - Your function should `return` the `sum` of the values displayed in previous step, so keep track of the values as you iterate over them.

3. Call the `BiArray()` function in `main()` and display the result.

4. [Compile and run](#How-to-compile-and-run-the-code) your code (see below).

### Sample output
```bash
$.\bin\ca.exe
foo[0][0]: 11
foo[0][1]: 25
foo[0][2]: 73
foo[1][0]: 44
foo[1][1]: 51
foo[1][2]: -6
foo[2][0]: -72
foo[2][1]: 80
foo[2][2]: 92
The sum of 3*3 array elements is: 298
```

### Validate your code
Once you are satisfied with your work, run our unit test file with the `bi_array` tag to validate your code:
```bash
  # For a detail information on the unit tests 
  $ .\bin\ca_test.exe [bi_array] -s
```

### GetMaxOf() function
Next, write a function that takes two `std::arrays` of `ten` integers and an `integer` index (guaranteed to be less than 10) and returns the **greater** of the two elements to the given index in the two arrays. 

Once again, the function declaration should go in your header file (`math3dlib.h`), and the function definition in your implementation file (`math3dlib.cpp`). This should be your function signature:

```c++
int& video::GetMaxOf(std::array<int, 10> &array1, std::array<int, 10> &array2, int index);
```
1. Your function should take the arrays by `reference` and `return by reference` because we are saying that the calling function is supposed to modify the element. Take the index by `value` since there is no reason to use references.
   * If the values are the same, the element from the first array is returned.

2. In `main()` the calling function should then `modify` the element. Use the following code to test it: 
   ```c++
    // GetMaxOf() Function
    array<int, 10> sorted = {11, 22, 37, 41, 53, 66, 79, 80, 95, 101};
    array<int, 10> reversed = {101, 95, 80, 79, 66, 53, 41, 37, 22, 11};
    cout << "sorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << endl;

    // We want to modify the element, so we need to make sure we take the result as reference.
    // If we were to return the result as a value, when we modify it it will not propagate
    // to the original element
    int& element = video::GetMaxOf(sorted, reversed, 0);
    cout << "\nMax Element: " << element << endl;

    element = 0;    // update value by reference
    cout << "\nsorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << endl;
    cout << "The original value has been updated though the reference!" << endl;

    // Note: we are taking by value. This creates a new local copy, and changes to it will not modify
    // the original value
    int value = video::GetMaxOf(sorted, reversed, 0);
    value = 10;
    cout << "\nsorted[0] = " << sorted[0] << "\n" << "reversed[0] = " << reversed[0] << endl;
    cout << "The original value has *not* been updated though the value!" << endl;
    ```

3. [Compile and run](#How-to-compile-and-run-the-code) your code (see below).

### Sample output
```bash
$ .\bin\ca.exe
sorted[0] = 11
reversed[0] = 101

Max Element: 101
sorted[0] = 11
reversed[0] = 0
The original value has been updated though the reference!

sorted[0] = 11
reversed[0] = 0
The original value has *not* been updated though the value!
```
### Validate your code
Once you are satisfied with your work, run our unit test file: Test your code with tag `[get_max_of]`:
 
```bash
# For a detail information on the unit tests 
$ .\bin\ca_test.exe [get_max_of] -s
```

---
---

## Part 3: FUNCTION OVERLOAD (45 POINTS)
The next part will help Maria handle the `point` information. The points are represented as `std::array<float, 3>`. 

1. Finding the distance between points could come in floats, integers, or 2 points(`array<float,3>`) form. We already have a function that handles two integer inputs. You will need to create another functions and overflow the name `Distance()`.
    ```c++
    float video::Distance(float point_a, float point_b);
    ```
    *note: remember to take the absolute value of the distance before you return it*.

- Add test code to main.
### Validate your code
  Test your code with tag `[distance2]`:
  ```bash
  # For a detail information on the unit tests 
  $ .\ca_test.exe [distance2] -s
  ```
2. Now, we will overflow the function `distance()` one more time for `points`. If only one of the 2 points is provided, the other one is assumed to be the `origin` (the point at location `(0,0,0)`).
```c++
float video::Distance(std::array<float, 3> point_a, std::array<float, 3> point_b = {0, 0, 0});
```
For this function, you may use this library:
```c++
#include <cmath> // for pow(), sqrt() function
```
- Add test code to main.

### Validate your code
Test your code with tag `[distance_point]`:
```bash
# For a detail information on the unit tests 
$ .\bin\ca_test.exe [distance_point] -s
```

3. When an enemy moves, it visits several points. Johnny needs to compute the total distance travel by the enemy. Define a new function `total_distance()` that it would take to walk along those points.

   * For simplicity, we will limit the number of points to 10, but Johnny might need up to 100. The function would take `array<std::array<float, 3>, 10> ` as input parameter, which is an array of "3D" points, and compute the distance between consecutive points. 
   * For example (with a list of 5 points): for the array `{{0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {0,1,1}}`, the total distance is 5, because going from `{0,0,0} to {1,0,0}` is a distance of 1, then going from `{1,0,0} to {1,1,0}` is a distance of 1 again, and so on for the remaining 3 points.
    
  You may use the following code in `main()` to test your program:
  ```c++
    std::array<float, 3> enemy1_location = {2, 2 ,0};
    std::array<float, 3> enemy2_location = {2, 4 ,0};

    float enemy_distance = video::Distance(enemy1_location, enemy2_location);
    float distance_from_center = video::Distance(enemy1_location);

    float view_circumference_for_enemy = video::Circumference(34.5);
    // Function that takes an array of 10 3D points. 
    float total_distance = video::TotalWalkingDistance(
        { enemy1_location,
        {2, 3, 0}, // y += 1
        {2, 3, 3}, // z += 3
        {5, 3, 3}, // x += 3
        {8, 3, 3}, // x += 3
        {8, 3, 2}, // z -= 1
        {2, 3, 2}, // x -= 6
        {2, 3, 1}, // z -= 1
        {2, 3, 0}, // z -= 1
        enemy2_location
    });

    std::cout << "The two enemies are " << enemy_distance << " m apart and can see for a circumference of "
              << view_circumference_for_enemy << " m. To go to from one to the other they need to walk "
              << total_distance << " m.";

  ```
  ### Sample output.

  ```bash
  The two enemies are 2 m apart and can see for a circumference of 216.66 m. To go to from one to the other they need to walk 20 m.
  ```
  - Add test code to main.
  ### Validate your code
    Test your code with tag `[total]`:
    ```bash
    # For a detail information on the unit tests 
    $ .\bin\ca_test.exe [total] -s
    ```

Finally run ALL Test your code:
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
Make sure you [commit and push](https://code.visualstudio.com/docs/editor/versioncontrol) your code to your online repository.

---

#### How to compile and run the code.

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
Note: The first time you compile your code, it will take 
a little longer since it needs to compile your unit_test code
as well.