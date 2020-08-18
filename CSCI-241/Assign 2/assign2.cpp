/***********************************************************
CSCI 241 - Assignment 2 - Spring 2019

Progammer: Tristen Anderson
Z-ID: z1820036
Section: 1
Date Due: Feb 21, 2019

Purpose: This program accepts a text file of seller data and adds it to existing seller
objects defined by another text file. 
************************************************************/ 
#include "SellerList.h"

int main()
{

SellerList List("sellerData");		//create SellerList object using alternate constructor
List.print();				//call the print method
List.processSalesData("sales.txt");	//call the process.. method
List.print();				//use the print method on the processed data

return 0;
}
