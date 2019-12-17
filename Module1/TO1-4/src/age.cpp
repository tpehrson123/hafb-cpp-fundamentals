#include "age.h"

  void ByValueAgeIn5Years(int age) 
    {
        age += 5;
    }
    
    int CurrentAge(int age) 
    {
      return age;
    }

    void ByReferenceAgeIn5Years(int& age)
{
    age += 5;
}