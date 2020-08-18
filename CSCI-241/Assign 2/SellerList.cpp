/***********************************************************
CSCI 241 - Assignment 2 - Spring 2019

Progammer: Tristen Anderson
Z-ID: z1820036
Section: 1
Date Due: Feb 22, 2019

Purpose: This program accepts a list of seller objects from a text file
and sorts them while keeping a running total of sales. SellerList.cpp contains
the class implemetation of SellerList.h.
************************************************************/ 
#include "SellerList.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>

using std::iostream;
using std::fstream;
using std::string;

/***************************************************************
SellerList
Use: Default Constructor, sets numSellers to 0 and empty seller names array
Parameters: none
Returns: nothing
***************************************************************/
SellerList::SellerList()
{
  numSellers = 0;
}

/***************************************************************
SellerList(alternate)
Use: Creates an array of Seller objects from an input file into a sellerList object
the selection sort algorithm
Parameters: 1. const string& filename: contains the name of an input file
Returns: nothing
*****************************************************************/
SellerList::SellerList(const string& fileName)
{
  ifstream fs;
  fs.open(fileName);
  if (fs.fail())
  {
	cout << "input file did not open" << endl;
	exit(-1);
  }

        fs.read((char*) this, sizeof(SellerList));
        fs.close();
	numSellers = 23;
	sortSellers();
}

/***************************************************************
print()
Use: prints an array of seller of objects using the print method of Seller.h
Parameters: none
Returns: nothing
*******************************************************************/
void SellerList::print() const
{
  int i = 0;
  cout << "Seller Listing" << endl;
  cout << "\nName" << setw(30) << "Sales"  << endl << endl;
  for (; i < numSellers; i++)
  {
   names[i].print();
  }
  cout << endl;
}

/***************************************************************
sortSellers()
Use: Sorts an array of Seller objects in ascending order using
the insertion sort algorithm.
Parameters:none
Returns: nothing
***************************************************************/
void SellerList::sortSellers()
{
   int i, j;
   Seller bucket;

   for (i = 1; i < numSellers; i++)
      {
      bucket = names[i];

      for (j = i; (j > 0) && (strcmp(names[j-1].getName(), bucket.getName()) > 0); j--)
         names[j] = names[j-1];

      names[j] = bucket;
      }
}

/***************************************************************
searchForSeller
Use: Uses a binary search to locate a name from the array of sorted seller objects.
Parameters: 1. a C string that contains the names to search for
Returns: -1 when search fails to find index and the index when name is found.
***************************************************************/
 int SellerList::searchForSeller(const char* searchName) const
 {
   int low = 0;
   int high = numSellers - 1;
   int mid;

   while (low <= high)
      {
      mid = (low + high) / 2;

      if (strcmp(searchName, names[mid].getName()) == 0)
         return mid;

      if (strcmp(searchName, names[mid].getName()) < 0)
         high = mid - 1;
      else
         low = mid + 1;
      }

   return -1;
}

/***************************************************************
processSellerData
Use: Reads a series of sales records containg names and sales amounts.
It searches for each seller name and adds to their sales total, when found it prints their
record.
Parameters: 1. const string& filename: a C++ string that contains the name of the sales data 
Returns: nothing
***************************************************************/
void SellerList::processSalesData(const string& fileName)
{
   ifstream inFile;
   char lastName[21];
   char firstName[11];
   double salesAmount;
   char name[31];

  // Open inFile using the file name passed in as a parameter
  inFile.open(fileName);

  // check for successful open
  if(inFile.fail())
  {
    cout << "Input File Did Not Open" << endl;
    exit(-1);
  }

  // Read lastName from inFile
   inFile >> lastName;
   cout << "Sales Transaction" << endl <<endl;

  while (!inFile.eof())
      {
     // Read firstName from inFile
     inFile >> firstName;
     // Read salesAmount from inFile
     inFile >> salesAmount;
     // Concatenate lastName, ", ", and firstName together to form name
       strcpy(name, lastName);
       strcat(name, ", ");
       strcat(name, firstName);
          	
      int index = searchForSeller(name);

      if (index == -1)
	cout << "Error: Seller Not Found" << endl;

      else
         { 	 
           // Print the seller's name and sales amount
	   cout << name << " sold " << salesAmount << endl;
           // Add the salesAmount to the salesTotal for the Seller object at element index of the array of Seller objects
         
	   names[index].setSalesTotal(salesAmount);
	 }

     // Read lastName from inFile
     inFile >> lastName;
      }
  cout << endl; 
  // Close input file
  inFile.close(); 
}
