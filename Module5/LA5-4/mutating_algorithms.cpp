#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::random_device random_num_device; // seed with real random number generator, if available
    std::mt19937 random_number_engine(random_num_device()); // Engine 

    std::shuffle(numbers.begin(), numbers.end(), random_number_engine);
    std::cout << "Values: ";
    std::for_each(numbers.begin(), numbers.end(), [](int value){std::cout << value << " ";});
    std::cout << std::endl;

    return 0;
}
