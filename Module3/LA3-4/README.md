# CA3.1: 

### Student name:

### Github account:
---
In the following activity, we will use a `while` loop and implement 
the previous concept from [PA1.1](../PA1.1/README.md) to print the 
numbers between `1 and 100 that are divisible by 7`.

---
### Files to work on
You are required to work/modify the following files:
- `README.md`: Update the student name an github account.
- All the functions you write, will be part of the library `factor`. The library consist of these two files: 
  - `src/factor.cpp`
- Our "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

---

Create a library with a function `int FactorMod7()`. Use the provided template files for your 
library: `factor.cpp` and `factor.h`  

Now, let's rewrite the previous code [PA1.1](../PA1.1/README.md) using a `while` loop in the following way:

1. Inside your function, create a variable of the `unsigned` type. 

2. Now, write the logic to print the numbers that are divisible by `7` 
   using the `while` loop. Remember to keep track of the number of occurrences.

3. Then, increase the value of `i` after each iteration.
```cpp
i++;
```

4.  Print the total `count`:
```c++
cout << count << endl;
```

7. Finally, return the number of occurrences. 

---

### Validate your code
Once you are satisfied with your work, run our unit test file:

```bash
$ ./bin/ca_test.exe
# You should get something like this:
===============================================================================
All tests passed (1 assertion in 1 test case)

# Or, if you want more information on the unit test run this command
$ ./bin/ca_test.exe -s

```
---

#### Notes to compile and run the code.

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
#### Notes to build a task in VS Code

- Press F1: Type Build Task