#include "date.h"
#include <iostream>

using namespace std;

int main(){
  //TODO: Test the Date class here

  //Testing the << overloaded operator, and the one parameter Date constructor while using 'new' and 'delete' keywords
  Date* a = new Date(2016);
  cout << *a << endl;
  delete a;

  //spacing
  cout << endl;

  //Testing full date constructor and fiveHolidays
  Date* b = new Date(1999, 5, 6);
  cout<< *b << endl;
  //spacing
  cout << endl;
  b->fiveHolidays();
  delete b;

  cout << endl;

  //testing add months
  Date* c = new Date(2017, 2, 20);
  cout << c->addMonths(7);
  delete c;

  return 0;
}