/**
 *
 * SellerList.h
 *
 * Author:    Tristen Anderson
 * z-ID:      z1820036
 * Date:      2-21-2019
 *
 * Contains the declaration for the SellerList class.
 */

#ifndef SELLERLIST_H
#define SELLERLIST_H

#include "Seller.h"
#include <string>

using namespace std;

class SellerList
{

  private:
   Seller names[31];
   int numSellers = 0;

  public:

   SellerList();
   SellerList(const string& fileName);
   void print() const;
   void sortSellers();
   int searchForSeller(const char* searchName) const;
   void processSalesData(const string& filename);

};

#endif
