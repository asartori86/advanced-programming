#include <iostream>
#include "error.h"
#include <sstream>

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

class Date {
  unsigned int day;
  Month month;
  int year;

 public:
  Date(const unsigned int d, const Month m, const int y) { set_date(d, m, y); }
  void set_date(const unsigned int d, const Month m, const int y);
  unsigned int get_day() const noexcept { return day; }
  Month get_month() const noexcept { return month; }
  int get_year() const noexcept { return year; }
};

std::ostream& operator<<(std::ostream& os, const Month m) noexcept {
  switch (m) {
    case Month::Jan:
      os << "January";
      break;
    case Month::Feb:
      os << "February";
      break;
    case Month::Mar:
      os << "March";
      break;
    case Month::Apr:
      os << "April";
      break;
    case Month::May:
      os << "May";
      break;
    case Month::Jun:
      os << "June";
      break;
    case Month::Jul:
      os << "July";
      break;
    case Month::Aug:
      os << "August";
      break;
    case Month::Sep:
      os << "September";
      break;
    case Month::Oct:
      os << "October";
      break;
    case Month::Nov:
      os << "November";
      break;
    case Month::Dec:
      os << "December";
      break;
    default:
      os << "Unknown month";
      break;
  }
  return os;
}

std::string InvalidDate(const unsigned int day,
                        const Month month,
                        const int year) noexcept {
  std::ostringstream os;
  os << "Invalid date! day = " << day << ", month = " << month
     << ", year = " << year;
  return os.str();
}

void Date::set_date(const unsigned int d, const Month m, const int y) {
  Assert(d != 0, "Invalid date:", d, m, y);
  // Assert(d!=0, InvalidDate(d,m,y));

  switch (m) {
    case Month::Jan:
    case Month::Mar:
    case Month::May:
    case Month::Jul:
    case Month::Aug:
    case Month::Oct:
    case Month::Dec:
      Assert(d <= 31, InvalidDate(d, m, y));
      break;
    case Month::Feb:
      Assert(d <= 28, InvalidDate(d, m, y));
      break;
    default:
      Assert(d <= 30, InvalidDate(d, m, y));
      break;
  }
  day = d;
  month = m;
  year = y;
}

std::ostream& operator<<(std::ostream& os, const Date& d) noexcept {
  return os << d.get_day() << ", " << d.get_month() << ", " << d.get_year()
            << std::endl;
}

int main() {
  try {
    Date d1{29, Month::Feb, 1987};
    std::cout << d1;
    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
  }
}
