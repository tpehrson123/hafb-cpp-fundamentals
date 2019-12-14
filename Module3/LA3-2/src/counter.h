// increment counter variable with ++ operator
// uses unnamed temporary object

class Counter
{
   private:
      unsigned int count;        //count
   public:
      Counter() : count(0)       //constructor  no args
         {  }
      Counter(int c) : count(c)  //constructor, one arg
         {  }
      int get_count();            //return count
      Counter operator ++ ();     // Prefix: increment count
      Counter operator ++ (int);  // Postfix: increment count
};