#ifndef SELLER_H
#define SELLER_H

/**
 *
 * Seller.h
 *
 * Author:    Tristen Anderson
 * z-ID:      z1820036
 * Date:      Feb 21, 2019
 * 
 * Contains the declaration for the Seller class.
 */

class Seller
   {
   private:
   char name[31]{};	//initialize name to an empty string
   double total = 0;	//initialize total to a double
   // Data members for the Seller class go here
   
   public:
   
   // Method prototypes for the Seller class

   Seller();
   Seller(const char*, double);

   const char* getName() const;
   double getSalesTotal() const;
   void setSalesTotal(double);
   void print() const;
   };

#endif
