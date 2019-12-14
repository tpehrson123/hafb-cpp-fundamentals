/**
 * @file nested_classes.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-09-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <string>
using namespace std; 

class A
{
public:
    class B
    {
    private:
        int num;
    public:
        void getdata(int n)
        {
            num = n;
        }
        void putdata()
        {
            cout << "The number is " << num;
        }
    };
};

class Person
{
    private:
        string name_;
    public:
        class Address           // nested class
        {
            private:
                string country_;
                string st_name_;
                int house_number_;
            public:
                Address(): country_("USA"), 
                    st_name_("Harrison"),
                    house_number_(123){};
                string country(){return country_;}
                string st_name(){return st_name_;}
                int house_number(){return house_number_;}
        };
    private:
        Address address_;
    public:
        Person(): name_("Waldo"){};
        void show_address()
        {
            cout << name_ << endl;
            cout << address_.country() << endl;
            cout << address_.st_name() << endl;
            cout << address_.house_number() << endl;
        }
}; // end of Person class



/**
 * @brief Main function
 * 
 * @return 0 No Error
 */
int main()
{
    cout << "Nested classes in C++" << endl;
    A ::B obj;
    obj.getdata(9);
    obj.putdata();

    Person student;
    student.show_address();
    return 0;
}