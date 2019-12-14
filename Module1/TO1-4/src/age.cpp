#include "age.h"

/**
 * @brief Increments age by 5 years "locally"
 * 
 * @param age: input value
 */
void ByValueAgeIn5Years(int age) 
{
    age += 5;
}


/**
 * @brief Increments age by 5 years
 * 
 * @param age: input value
 */
void ByReferenceAgeIn5Years(int& age)
{
    age += 5;
}

/**
 * @brief Returns the current value of age
 * 
 * @param age input value
 * @return age
 */
int CurrentAge(int age) 
{
    return age;
}