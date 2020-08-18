#pragma once

#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>

using std::ifstream;
using std::vector;
using std::cout; 

template <class T>
void buildList(vector<T>& set, const char* fileName);					//forward declaration of buildList function

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine);	//forward declaration of printList function

template <class T>
bool lessThan(const T& item1, const T& item2);							//forward declaration of lessThan

template <class T>
bool greaterThan(const T& item1, const T& item2);						//forward declaration of greaterThan

/***************************************************************
buildList
Use: Fills a vector with input from a file
Parameters: 1. filename: a pointer to a character that is constant 
            2. set: A vector of a template type
Returns: nothing
***************************************************************/ 
template <class T>
void buildList(vector<T>& set, const char* fileName)					//function definition buildList
{
	T item;
	ifstream inFile;
	inFile.open(fileName);												//Open inFile for input using fileName as the name of the file to open

	//Check that the file has been successfully opened
	if (!inFile)
	{
		std::cout << "Input File Did Not Open";							//if file is not opened print error and exit
		exit(-1);
	}

	//Read item from input file
	while (inFile)
	{
		inFile >> item;						//read item from file
		set.push_back(item);				//add vector to end of vector 
	}

	//Close the input file
	inFile.close();	
}

/***************************************************************
printList
Use: prints the elements of a vector to a specified number per line and spacing
Parameters: 1. set: a reference to a constant vector of template type that is constant
            2. an integer that specifies the width interval
	    3. numPerLine: an integer specificying the number of elems to print per line
Returns: nothing
***************************************************************/ 
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int count = 0;
	for (int i = 0; i < (int)set.size(); i++) {
		cout << std::setw(itemWidth) << set[i] << ' ';
		count++;
		if (count == numPerLine) {
			cout << std::endl;
			count = 0;
		}
	}
	cout << std::endl;
}

/***************************************************************
lessThan
Use: return true is item1 is lessthan item2
the selection sort algorithm
Parameters: 1. A reference to a template that is constant
	    2. A reference to a template that is constant
Returns: boolean true false
***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
	return (item1 < item2);
}

/***************************************************************
greaterThan
Use: returns true if item1 is greaterthan item2
Parameters: 1. item1: a reference to a template that is constant
            2. item2: a reference to a template that is constant
Returns: boolean true false
***************************************************************/ 
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	return (item1 > item2);
}

#endif /*SORTS_H*/
