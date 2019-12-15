# TO1.1: COUNTING THE NUMBER OF TIMES A SPECIFIC NUMBER APPEARS IN A GIVEN LIST
In this exercise, we will discuss using the `if` statement and a for `loop` to count our magic 
number. Here, we will be trying to find all numbers that are divisible by 3, ranging from 1 to 30.

*Hint*
_To find out if a number is divisible by another, use the `modulo (%) operator`.

## Part 1:
Now, let's perform the following steps:

1. Import all the required header files and create `main function` body. For most of our purposes, this is going to be our c++ file template. 
  ```c++
  #include <iostream>
  using namespace std;
  
  int main()
  {
    return 0;
  }
  ```

2. We need to store the number of times a number is divisible by 3 in a counter. For this reason, 
we define and initialize the `count` variable to 0:
  ```c++
  unsigned int count = 0;
  ```

3. Now, we will use a `for` loop that produces values from 1 to 30 so that we can check whether 
they are divisible by 3 or not:
```c++
for(unsigned int x = 1; x <= 30; ++x)
{
   
}
```

4. Finally, we will check in the `body` of the for loop by using an if statement and the expression 
`x % 3 == 0`, which evaluates to `true` if the division has a remainder equal to `0`:
```c++
if (x % 3 == 0)
{
  count++;
}
```

5. If the previous condition returns to `true`, then the `X` variable is divisible by `3` and 
we can increment the counter.


6. Next, we can print `count`:
```c++
cout << count << endl;
```

7. Finally, create a function `int FactorMod3()` and move the code from steps 1-5 to it. Your function should return  an `integer` with the count of
our magic number. 
  ```c++
  // Function Prototype
  int FactorMod3();

  int main()
  {
    int result = 0;
    result = FactorMod3();
    cout << "Result is: " << result << endl;
    return 0;
  }
  // Function Definition
  int FactorMod3()
  {
    int result;
    // algorithm

    return result;
  }
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
$ .\main.exe
```
For Linux/Mac:
```bash
$ mkdir -p build
$ cd build
$ cmake ..
$ cmake --build .
# Now you can run your code
$ .\main
```