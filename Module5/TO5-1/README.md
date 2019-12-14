# Try-It-Out Activity 5-1: Introduction to Data Analytics

### Student name:

### Github account:
---
In this activity we will begin doing some data analytics. Your job is to do some quick analysis in a data set (simulated) 
related to level of education, gender, and state.

---
### Files to work on
You are required to work/modify the following files:
- `README.md`: Update the student name an github account.
- All the functions you write, will be part of the library `collection`. The library consist of these two files: 
  - `src/collection.cpp`
  - `src/collection.h`
- Your "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file will result in penalty to your grade.

---
# Part 1
The first thing you need to do is to load the data from a csv file. For this, we will use the `csvstream.h` library. 

The sample simulated data is located in the `data/sample_data.csv` file, and it has the following format:
```csv
id,gender,school,state
1,Male,Public university,Maine
2,Female,Corporate university,Florida
3,Male,Corporate university,Connecticut
...
...
```
The file contains `100,000 records` for you to analyzed.


To read the data, create a function that will take 2 parameters. The first one will be a `vector of Data structures` (see `structure Data` below), and the second parameters will be the location of the csv file relative to the location where the executable runs(`build/bin`) in the form of a `string`. Both parameters will be passed as references for efficiency.  
```cpp
// containers.h
// Structure for data from file
struct Data
{
    int id;
    std::string gender;
    std::string school;
    std::string state;
};

void Load_Data(std::vector<Data> &data, const std::string &in_file);

// containers.cpp
void Load_Data(std::vector<Data> &data, const std::string &in_file)
{
  // TODO: Load data from file

  // TODO: Create a Data structure with the column information

  // TODO: Loop over file and add Data objects to the vector

  return;
}
```
You can use the following testing scenario in your main:
```cpp
// TODO: Define an empty vector of Data Structures called: information
std::string input = "../data/sample_data.csv";     // DO NOT MODIFY THIS LINE

Load_Data(information, input); // Load Data

cout <<"Information size: " << information.size() << endl;
```
Sample Output:
```bash
Information size: 100000
```

# Part 2
Your next task is to create a function that will count the instances of `gender` entries in the data file. Your function should take two parameters. The first parameter is once again a `reference` to a `vector of Data objects`, which you loaded in `part 1`, and the second parameter is the matching gender `string`.
```cpp
int Count_Gender(std::vector<Data> &data, const std::string gender);
```
Your function should `return the number of records` based on  the gender string. If you take a look at the data file, the only two valid strings are: `Male` and `Female`. However, you function should test for an unsupported gender string. If the user enters an invalid string, your function should return `0`. 

You may use the following statements to test your code in main:
```cpp
  cout <<"Number of Males: " << Count_Gender(information, "Male")<< endl;
  cout <<"Number of Females: " << Count_Gender(information, "Female")<< endl;
  cout <<"Number of Cars: " << Count_Gender(information, "Car")<< endl;
```

Sample Output:
```bash
Number of Males: 43001
Number of Females: 56999
Number of Cars: 0
```

# Part 3
Finally, you need to create another function that will count the number of records for each of the `states`. Your function will take two parameters. The first parameters is once again a `reference` to a `vector of Data objects` from `part 1`, and the second parameter is a `reference` to a `map of strings and integers` key->values. 

Your `map` should use the `state` name as the `key`, and the number of instances as the `value` associated with the key.

```cpp
  // container.h
  void Count_by_State(std::vector<Data> &data, std::map<std::string, int> &st_count);
```

You may use the following testing scenario in your main:
```cpp
  // TODO: Declare a map of strings(key) and integers(values) called: states            
  Count_by_State(information, states);  // load map data
  Display_by_State(states);             // display map data
```
I have provided a function `Display_by_States()` to display the your `map` after you have loaded the information. 

Sample output:
```bash
Alabama :: 1996
Alaska :: 2013
Arizona :: 1938
...
...
Wisconsin :: 2025
Wyoming :: 2030
A total of 100000 records for all states
```

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
$ cmake -DUNIT_TEST=ON ..
$ cmake --build .
```

### Validate Part 1
```bash
# Use the following tag to validate Part 1
$ ./bin/ca_test.exe -s [part1]
```

### Validate Part 2
```bash
# Use the following tag to validate Part 2
$ ./bin/ca_test.exe -s [part2]
```
### Validate Part 3
```bash
# Use the following tag to validate Part 3
$ ./bin/ca_test.exe -s [part3]
```

### Finally run ALL Test your code:
```bash
# To list all available tags
$ .\bin\ca_test.exe -t

# For summary information in compact mode
$ .\bin\ca_test.exe -s -r compact
```

---
### Publish your code
Before you push your code, you need to edit the `.travis.yml` file. This file is located in the [root](../.travis.yml)
directory of your project. Uncomment `TEST_DIR=TO5-1 line` by pressing `Ctrl+/` keys. 

```CMake
env: 
  - TEST_DIR=TO5-1     # Uncomment this when working on TO5-1
  # - TEST_DIR=CA5-1   # Uncomment this when working on CA5-1
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