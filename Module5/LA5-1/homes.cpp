#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inches;
};

struct Room
{
    Distance length;
    Distance width;
};

struct Home
{
    Room master;
    Room kitchen;
};

// Prototype
void ShowHomeRoom(const Home &house);

int main()
{

    Home house;
    house.kitchen.length.feet = 20;
    house.kitchen.length.inches = 0;
    house.kitchen.width.feet = 30;
    house.kitchen.width.inches = 0;
    ShowHomeRoom(house);

    return 0;
}

void ShowHomeRoom(const Home &house)
{
    std::cout << "House Info:" << std::endl;
    std::cout << "Kitchen " << house.kitchen.length.feet << "\'" <<
     house.kitchen.length.inches << " " << house.kitchen.width.feet << "\'"
      << house.kitchen.width.inches << std::endl;
}