#include <iostream>

class Distance                    //English Distance class
{
   private:
      int feet_;
      float inches_;
   public:                        //constructor (no args)
      Distance() : feet_(0), inches_(0.0)
         {  }                     //constructor (two args)
      Distance(int ft, float in) : feet_(ft), inches_(in) 
         {  }
      ~Distance() {  }
      int feet() const;
      float inches() const;

      void set_distance();              //get length from user
      void update_distance(int ft, float in);              //get length from user
      void showdist() const;       //display distance

      Distance operator + ( Distance ) const;  //add 2 distances
      Distance operator - ( Distance ) const;  //substract 2 distances
      friend std::ostream &operator<<(std::ostream &os, const Distance &distance);
};