class Distance                    //English Distance class
{
   private:
      int feet;
      float inches;
   public:                        //constructor (no args)
      Distance() : feet(0), inches(0.0)
         {  }                     //constructor (two args)
      Distance(int ft, float in) : feet(ft), inches(in) 
         {  }
      void set_distance();              //get length from user
      void showdist() const;       //display distance

      Distance operator + ( Distance ) const;  //add 2 distances
      friend std::ostream &operator<<(std::ostream &os, const Distance &distance);
};