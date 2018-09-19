#include "date.h"
#include <iostream>

using namespace std;

int main(){
  //TODO: Test the Date class here

  Date* a = new Date(2016);
  cout << *a << endl;
  delete a;

  cout << endl;

  Date* b = new Date(1999, 5, 6);
  b->fiveHolidays();
  delete b;

  cout << endl;

  Date* c = new Date(2017, 2, 20);
  cout << c->addMonths(7);
  delete c;



  return 0;
}