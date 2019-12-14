# Try-It-Out Activity 5-1
How to Convert Numerical Values to Roman Numbers
Roman numerals, as they are known today, use seven symbols: `I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, and M = 1000`. The system uses additions and subtractions in composing the numerical symbols. 

The symbols from 1 to 10 are `I, II, III, IV, V, VI, VII, VIII, IX, and X`.
Romans did not have a symbol for `zero` and used to write `nulla` to represent it. 

In this system, the `largest` symbols are on the `left`, and the `least significant` are on the `right`. 

As an example, the Roman numeral for `1994` =  `MCMXCIV`. If you are not familiar with the rules for Roman numerals, you should read more on the web.

# Part 1
To determine the Roman numeral of a number, use the following algorithm:

  * Check every Roman base symbol from the highest (M) to the lowest (I)
  * If the current value is greater than the value of the symbol, then concatenate the symbol to the Roman numeral and subtract its value from the current one    
  * Repeat until the current value reaches zero

For example, consider `42`: the first Roman base symbol smaller than 42 is `XL`, which is `40`. We concatenate it to the numeral, resulting in `XL`, and subtract from the current number, resulting in `2`. The first Roman base symbol smaller than `2` is `I`, which is `1`. We add that to the numeral, resulting in `XLI`, and subtract `1` from the number, resulting in `1`. We add one more `I` to the numeral, which becomes `XLII`, and subtract again `1` from the number, reaching `0` and therefore stopping
---
## Validate your code
Once you are satisfied with your work, run our unit test file:
```bash
# Go to your build directory
$ cd build
# Clean all files
$ rm *
# Compile and build the code with UNIT_TEST=ON
$ cmake .. -G "MinGW Makefiles" -D UNIT_TEST=ON
$ cmake --build .
```
For Linux/Mac:
```bash
$ cmake -D UNIT_TEST=ON ..
$ cmake --build .
```

### Validate Part 1

```bash
# Use the following tag to validate Part 1
$ ./bin/ca_test.exe -s [part1]
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
directory of your project. Uncomment `TEST_DIR=TO1-1 line`. 

```CMake
env: 
  - TEST_DIR=TO1-1
  # - TEST_DIR=CA1-1 
  # - TEST_DIR=TO1-2   # Uncomment this if you have more than CAs or TOs
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