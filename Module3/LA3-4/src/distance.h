class Distance                    //English Distance class
{
   private:
      static int total_points;
      int feet_;
      float inches_;
   public:                        //constructor (no args)
      Distance() : feet_(0), inches_(0.0)
         {  
            total_points++;
         }                     //constructor (two args)
      Distance(int ft, float in) : feet_(ft), inches_(in) 
         {  
            total_points++;
         }

      Distance(const Distance &d1)  // copy constructor
      {
         feet_ = d1.feet_;
         inches_ = d1.inches_;
         total_points++;
         std::cout<<"Copy constructor invoked"<< std::endl;
      }
      void set_distance();              //get length from user
      void showdist() const;       //display distance
      static void showtotal();

      Distance operator + ( Distance d2) const;  //add 2 distances
      friend std::ostream &operator<<(std::ostream &os, const Distance &distance);

      bool operator < (Distance d2) const;  // compare distances
      bool operator == (Distance d2) const;  // compare distances
      
      friend Distance operator - ( Distance d1, Distance d2);  //add 2 distances
      
      Distance operator = (Distance& d2);  // compare distances
};