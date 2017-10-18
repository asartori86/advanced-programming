#include <iostream>

enum class Month {
  Jan = 1,
  Feb,
  Mar,
  Apr,
  May,
  Jun,
  Jul,
  Aug,
  Sep,
  Oct,
  Nov,
  Dec
};

struct Invalid_Date {
  Invalid_Date(const unsigned int i, const Month m) : day{i}, month{m} {}
  const unsigned int day;
  const Month month;
};

class Date {
  unsigned int day;
  Month month;
  int year;
  // void check_day(const unsigned int d,
  // 		 const unsigned int threshold);
 public:
  void set_date(unsigned int d, Month m, int y);
  unsigned int get_day() const { return day; }
  Month get_month() const { return month; }
  int get_year() const { return year; }
};

// void Date::check_day(const unsigned int d, const unsigned int threshold)
//  {
//    if(d > threshold)
//      // throw Invalid_Day{d};
//  }

void Date::set_date(unsigned int d, Month m, int y) {
  if (d == 0) {
    std::cerr << "Invalid date!\n";
    return;
  }
  switch (m) {
    case Month::Jan:
    case Month::Mar:
    case Month::May:
    case Month::Jul:
    case Month::Aug:
    case Month::Oct:
    case Month::Dec:
      if (d > 31)
        throw Invalid_Date(d, m);
      break;
    case Month::Feb:
      if (d > 28)  // should check for leap years
        throw Invalid_Date(d, m);
      break;
    default:
      if (d > 30)
        throw Invalid_Date(d, m);

      day = d;
      month = m;
      year = y;
  }
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
  return os << d.get_day() << ", " << static_cast<int>(d.get_month()) << ", "
            << d.get_year() << std::endl;
}

int main() {
  try {
    Date d1;
    d1.set_date(29, Month::Feb, 1987);
    std::cout << d1;
    return 0;
  } catch (Invalid_Date d) {
    std::cerr << "Invalid date: " << d.day << ", " << static_cast<int>(d.month)
              << std::endl;
  }
}
