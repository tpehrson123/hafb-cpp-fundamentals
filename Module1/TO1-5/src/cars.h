#ifndef CARS_H_
#define CARS_H_

int HorsePower();  // nameless namespace

namespace lamborghini
{
    int HorsePower();  // inside lamborghini namespace
    void cout();
}

namespace porsche
{
    int HorsePower();  // inside porsche namespace
}

#endif /* !CARS_H_ */
