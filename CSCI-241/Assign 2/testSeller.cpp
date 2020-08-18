/**
 *
 * testSeller.cpp
 *
 * Contains unit tests for the Seller class methods.
 */

#include <iostream>
#include "Seller.h"

using std::cout;
using std::endl;

int main()
   {
   // Test default constructor
   Seller seller1;

   // Test alternate constructor
   Seller seller2("Jones, Martin", 1234.56);

   // Test print() method and whether constructors
   // properly initialized objects
   cout << "Printing seller1\n\n";
   seller1.print();
   cout << endl << endl;

   cout << "Printing seller2\n\n";
   seller2.print();
   cout << endl << endl;

   // Test accessor methods
   cout << seller2.getName() << endl;
   cout << seller2.getSalesTotal() << endl;

   seller2.setSalesTotal(6543.21);
   seller2.print();

   return 0;
   }
