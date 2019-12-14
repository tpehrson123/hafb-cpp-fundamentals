#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers {3, 6, 1, 88, 2, 3, 55};

    std::sort(numbers.begin(), numbers.end());
    std::cout << "Values: ";
    std::for_each(numbers.begin(), numbers.end(), [](int value){std::cout << value << " ";});
    std::cout << std::endl;

    return 0;
}