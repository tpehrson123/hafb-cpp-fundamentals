#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    // copy_if()
    std::vector<std::string> words = {"Hello", "C++", "C++ Fundamentals", "Class", "Learning"};
    std::vector<std::string> long_words;
    // Only copy those words with > 3 letters
    std::copy_if(words.begin(), words.end(), std::back_inserter(long_words), 
        [] (const std::string & s) { return s.length() > 3;});
    std::cout << "Number of words > 3 letters: " << long_words.size() << std::endl;

    // transform()
    std::vector<int> lengths;
    std::transform(long_words.begin(), long_words.end(), std::back_inserter(lengths),
        [](const std::string &s){return s.length();});
    std::cout << "Lengths: ";
    std::for_each(lengths.begin(), lengths.end(), [](int length){ std::cout << length << " ";});
    std::cout << std::endl;

    // remove_if()
    auto new_last = std::remove_if(lengths.begin(), lengths.end(), [](int length){ return length < 7;});
    std::cout << "No elements remove yet: " << lengths.size() << std::endl;
    
    // erase(): erase all elements between two iterators
    lengths.erase(new_last, lengths.end());
    std::cout << "Elements are removed now. Content: ";
    std::for_each(lengths.begin(), lengths.end(), [](int length){ std::cout << length << " ";});
    std::cout << std::endl;
    


    return 0;
}
