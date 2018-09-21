#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Date {
public:
  //TODO: Define one argument constructor here (year)
  Date(int y): year(y), month(1), day(1){}

  //TODO: Define two argument constructor here (year and month)
  Date(int y, int m): year(y), month(m), day(1){}

  Date(int y, int m, int d): year(y), month(m), day(d){}

  Date& addMonths(int n){
    year  += (month + n) / 12;
    month = (month + n) % 12;
    return *this;
  }

  Date& addDays(int n) {
    int d = daysToDate() + n;
    int y = year, m = 1;
    while(d > daysInMonth(y, m)){
      d -= daysInMonth(y, m);
      m++;
      if(m > 12){
        m = 1;
        y++;
      }
    }

    day = d;
    month = m;
    year = y;

    return *this;
  }

  static bool isLeapYear(int y) {
    return (y % 4 || (y % 100 == 0 && y % 400)) ? false : true;
  }

  std::string str() {
    // TODO: complete this function implementation here.

    //assigning the month keyword using the array and then appending
    // things to the string that will be returned to fit the assigned format
    std::string dateString = monthsarr[month-1];
    dateString.append(" ");
    dateString.append(std::to_string(day));
    dateString.append(", ");
    dateString.append(std::to_string(year));

    return dateString;
  }

  int daysToDate(){
    int days_in_month[]{31, isLeapYear(year) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for(int m = 0; m < month - 1; m++){
      days += days_in_month[m];
    }
    days += day;
    return days;
  }

  // TODO: Overload operator+ here
  Date& operator+(int n){
        return addDays(n);
      }

  // TODO: overload operator<< here
  friend std::ostream& operator<<(std::ostream& out, Date& d)
  {
      out << d.str();
      return out;
  }

  //Five holidays: indigenous peoples day, halloween, thanksgiving, christmas, and new years eve
  // TODO: define fiveHolidays function here
  static std::vector<Date*> fiveHolidays() {
      std::vector<Date*> h;
      h.push_back(new Date(2018,10,8));
      h.push_back(new Date(2018,10,31));
      h.push_back(new Date(2018,11,23));
      h.push_back(new Date(2018,12,25));
      h.push_back(new Date(2018,12,31));

      for(Date* i : h){
        std::cout << *i << std::endl;
      }

      return h;
  }

private:
    //created an array to assign the month when printing out the dates
    std::string monthsarr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  int year, month, day;

  static int daysInMonth(int y, int m){
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[m - 1];
  }
};

#endif

