#include "Seller.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/***************************************************************
Seller 
Use:Default constructor, sets total to zero and creates empty name array
Parameters: none
Returns: nothing
***************************************************************/ 
Seller::Seller()
{
   name[0] = '\0';
   total = 0;
}

/***************************************************************
Seller()
Use: Alternate constructor, sets total to the values passed in and
copies the name passed in to the private variable
Parameters: 1. newName: a reference to a constant character array
            2. newSalesTotal: a double containing the value of the sellers sales total
Returns: nothing
***************************************************************/
Seller::Seller(const char* newName, double newSalesTotal)
{
   strcpy(name, newName);
   total = newSalesTotal;
}

/***************************************************************
getName
Use: pulls the name from the private array name
Parameters: none
Returns: name
***************************************************************/ 
const char* Seller::getName() const
{
   return name;
}

/***************************************************************
setSalesTotal
Use: sets the total to the total + the passed in sales
Parameters: 1. newSalesTotal: a double containing the new sales total
Returns: nothing
***************************************************************/
void Seller::setSalesTotal(double newSalesTotal)
{
   total += newSalesTotal;
}

/***************************************************************
getSalesTotal
Use: retrieves the value of the private variable total.
Parameters: none
Returns: total
***************************************************************/ 
double Seller::getSalesTotal() const
{
   return total;
}

/***************************************************************
print
Use: prints the name of the seller and their sales total
Parameters: none
Returns: nothing
***************************************************************/ 
void Seller::print() const
{
   cout << fixed << setprecision(2) << left << setw(30) << name << right << setw(9) << total << endl;
}


