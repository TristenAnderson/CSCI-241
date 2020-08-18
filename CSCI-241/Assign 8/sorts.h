#pragma once

#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::vector;

template <class T>
void buildList(vector<T>& set, const char* fileName);					//forward declaration of function

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine);	//forward declaration of print function


template <class T>
void buildList(vector<T>& set, const char* fileName)					//function definition
{
	T item;
	ifstream inFile;
	inFile.open(fileName);												//Open inFile for input using fileName as the name of the file to open

	//Check that the file has been successfully opened
	if (!inFile)
	{
		std::cout << "Input File Did Not Open";
		exit(-1);
	}

	//Read item from input file
	while (inFile)
	{
		inFile >> item;
		set.push_back(item); 
		//Read item from input file
	}

	//Close the input file
	inFile.close();
}

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int count = 0;
	for (int i = 0; i < (int)set.size(); i++){
		cout << std::setw(itemWidth) <<  set[i] << ' ';
		count++;
		if (count == numPerLine){
			cout << std::endl;
			count = 0;
			}
		}

	cout << std::endl;
}

#endif /*SORTS_H*/
