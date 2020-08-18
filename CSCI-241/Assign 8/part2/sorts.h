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

template <class T>
bool lessThan(const T& item1, const T& item2)
{
	return (item1 < item2);
}

template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	return (item1 > item2);
}

#endif /*SORTS_H*/
