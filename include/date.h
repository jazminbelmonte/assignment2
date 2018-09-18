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
    return "";
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

  Date& operator+(int n){
    return addDays(n);
  }

  // TODO: Overload operator+ here
  friend Date operator+(Date d, int n)
  {
      return d.addDays(n);
  }

  // TODO: overload operator<< here
  friend std::ostream& operator<<(std::ostream& out, Date& date)
  {
      out << date->str() << std::endl;
      return out;
  }

  // TODO: define fiveHolidays function here
  static fiveHolidays() {
      std::vector<Date*> h(5);
      h[0] = (2018, 9, 10);
      h[1] = (2018, 9, 10);
      h[2] = (2018, 9, 10);
      h[3] = (2018, 9, 10);
      h[4] = (2018, 9, 10);

      return h;

  }

private:
  int year, month, day;

  static int daysInMonth(int y, int m){
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[m - 1];
  }
};

#endif


/*
●Add a second constructor that takes only a single ​year​ argument and
 initializes both month​ and ​day​ to ​1​.

 ●Add a third constructor that takes two arguments for ​year​ and ​month​
 and initializes day​ to ​1​.

 ●Overload ​operator+​ such that given a date object ​d​, the expression ​
 d + n​ is the same as ​d.addDays(n)​ where ​n​ is the number of days to add.

 ●Complete the implementation of the ​str()​ function which returns a
 string representation of the date object in the format "Mon, day, year"
 For example, given a date object ​Date* d = new Date(2018, 9, 10)​, the
 call ​d->str()​ returns the string ​"Sep 10, 2018"​.

 ●Overload ​operator<<​ using a ​friend​ function, such that given a data
 object ​d​, a statement like ​c out << d;​ is valid and prints to the console
 the string representation returned by ​d.str()​.

 ●Add a ​static​ method named ​fiveHolidays()​ that returns a vector of five
 Date pointers (​std::vector<Date*>​) representing five holidays of your choosing.*/
