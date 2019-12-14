# Try-It-Out Activity 5-1: Introduction to Data Analytics Part II

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

The sample simulated data is located in the `data/MOCK_DATA_CARS.csv` file, and it has the following format:
```csv
vin,car_make,car_year,car_color,value,state
5NPEB4AC0EH377888,Dodge,1998,Fuscia,53698.98,California
TRURD38J591607972,GMC,1996,Khaki,30556.77,California
...
...
```
The file contains 4,000 records for you to analyzed.


To read the data, create a function that will take 2 parameters. The first one will be a `vector of Car structures` (see `structure Car` below), and the second parameters will be the location of the csv file in the form of a string. Both parameters will be passed as references for efficiency.  
```cpp
// containers.h
// Structure for data from file
struct Car
{
    std::string vin;
    std::string make;
    int year;
    std::string color;
    double value;
    std::string state;
};

void Load_Data(std::vector<Car> &cars, const std::string &in_file);

// containers.cpp
void Load_Data(std::vector<Car> &cars, const std::string &in_file)
{
  // TODO: Load data from file

  // TODO: Create a Car structure with the column information

  // TODO: Add Car objects to the vector

  return;
}
```
You can use the following testing scenario in your main:
```cpp
// TODO: Define an empty vector of Car Structures called: cars
std::string input = "../data/MOCK_DATA_CARS.csv";     // DO NOT MODIFY THIS LINE

Load_Data(cars, input); // Load Data

cout <<"Cars size: " << cars.size() << endl;
```
Sample Output:
```bash
Cars size: 4000
```

# Part 2
Your next task to create a function that will  return the `Car record object` based on the operation being performed. 
Your function should take two parameters. The first parameters is once again a `reference` to a `vector of Car objects` from `part 1`, and the second parameter is an `integer` that represents an operation to be performed. 

```cpp
Car Car_Value_Analytics(std::vector<Car> &cars, int operation);
```
The types of operations are defined in your `containers.h` in the form of constants:
```cpp
// Operation for analytics
#define MAX 1
#define MIN 2
```

If the `operation == MAX`, then you should return the `Car` element from the vector with the maximum `value`. 

If the `operation == MIN`, then you should return the `Car` element from the vector with the minimum `value`. 

***Hint:*** You may use the `min()`, `max()`, or `minmax_element()` functions in conjunction with a `lambda function` to help you select the correct record based on the `operation` input parameter. 





You may use the following statements to test your code in main:
```cpp
  // Part II
  Car car = Car_Value_Analytics(cars, MAX);
  cout << "Car MAX value: " << car.value << endl;
  car = Car_Value_Analytics(cars, MIN);
  cout << "Car MIN value: " << car.value << endl;
```

Sample Output:
```bash
Car MAX value: 79990.3
Car MIN value: 20010.6
```

# Part 3
Finally, you need to create another function that will select the records based on the input year. Your function will take two parameters. The first parameters is once again a `reference` to a `vector of Car objects` from `part 1`, and the second in an `integer` that represents the `decade` the car was built. 
```cpp
  // container.h
  std::vector<Car> Cars_from_decade(std::vector<Car> &cars, int decade);
```
Your function should return a new `vector of Car objects` with only those records matching the decade input parameter. 

For example, if you user enters: `1987` for the decade parameter, your function should filter all the records from `1980 to 1989`. Or if the user enters `2000`, then, you will filter those records from `2000 to 2009`.

You may use the following testing scenario in your main:
```cpp
  // Part III
  int decade = 2009;
  std::vector<Car> new_cars = Cars_from_decade(cars, decade);
  for (const Car &car : new_cars)
  {
    std::cout << "New cars for " << decade << " " << car.year << " "
              << car.value << std::endl;
  }
  cout << new_cars.size() << endl;
```

Sample output:
```bash
...
...
New cars for 2009 2005 79833.5
New cars for 2009 2008 79846.3
New cars for 2009 2000 79979.2
1517
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
$ cmake -D UNIT_TEST=ON ..
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
directory of your project. Uncomment `TEST_DIR=CA5-1 line` by pressing `Ctrl+/` keys. 

```CMake
env: 
  - TEST_DIR=TO5-1     # Uncomment this when working on TO5-1
  - TEST_DIR=CA5-1   # Uncomment this when working on CA5-1
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