#include <iostream>

enum class Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };


class Date{
  unsigned int day;
  Month month;
  int year;
  void check_day(const unsigned int d,
		 const unsigned int threshold) {if(d > threshold)}
public:
  void set_date(unsigned int d,
		Month m,
		int y);
};

void Date::set_date(unsigned int d, Month m, int y)
{
  if (d==0)
    {
      std::cerr << "Invalid date!\n";
    return;
    }
  switch (m){
  case Month::Jan :
  case Month::Mar :
  case Month::May :
  case Month::Jul :
  case Month::Aug :
  case Month::Oct :
  case Month::Dec :
    if (d>31)
    {
      std::cerr << "Invalid date!\n";
    return;
    }
    break;
  case Month::Feb :
    


  }
  if (d>0 && d<=31) // we should do better, check for the given month
}


int main()
{
  Date d1;
  d1.day = 5;
  d1.month = Month::Aug;
  d1.year = 1986;

  Date* ptd {&d1};

  ptd->day = 37;  // possible typo 
  ptd->year=2017;

  ++d1.day;
  std::cout << ptd->day << std::endl;
  
  
  return 0;
}
