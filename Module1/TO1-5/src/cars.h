/*
** cars.h for CS1410 (Workspace) in e:\CS1410-Inst\cs1410-module1\TO1-5\src
**
** Made by hvalle
** Login   <hvalle>
**
** Started on  Wed Aug 14 1:26:10 PM 2019 hvalle
** Last update Wed Aug 14 1:26:10 PM 2019 hvalle
*/

#ifndef CARS_H_
#define CARS_H_

// Open a namespace called Lamborghini
namespace lamborghini 
{
    // Define a function named 'HorsePower' inside the namespace LamborghiniCar
    int HorsePower();
}  // The namespace 'Lamborghini' is closed here

// Open a namespace called porshe
namespace porshe 
{
   // Define a function named 'HorsePower' inside the namespace porshe
    int HorsePower();
} // The namespace 'Lamborghini' is closed here


// Define a function named 'output' inside the anonymous namespace
int HorsePower();

#endif /* !CARS_H_ */
