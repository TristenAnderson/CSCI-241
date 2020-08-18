#pragma once

#ifndef QUICKSORT_H
#define QUICKSORT_H

using std::vector;

template <class T>
void quickSort(vector<T>& set, bool(*compare)(const T&, const T&));				//forward declarations for functions

template <class T>
void quickSort(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&));

template <class T>
int partition(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&));

/***************************************************************
quicksort
Use: calls the quicksort function 
Parameters: 1. set: a reference to a vector of template type
            2. a pointer to a comparison function
Returns: nothing
***************************************************************/ 
template <class T>
void quickSort(vector<T>& set, bool(*compare)(const T&, const T&))
{
	quickSort(set, 0, set.size() - 1, compare);
}

/***************************************************************
quicksort
Use: sorts the vector set by partitions 
Parameters: 1. set: a reference to a vector of type template
	    2. start: an integer representing the starting index
	    3. end: an integer to hold the value of the index of the vector end 
            4. a pointer to acomparison function
Returns: nothing
***************************************************************/ 
template <class T>
void quickSort(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&))
{
	int pivotPoint;

	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
	}
}

/***************************************************************
partition
Use: partitions to data set and compare elements and swaps values
Parameters: 1. ar: an array of integers to be sorted.
            2. start: an integer of the starting index
	    3. end: an integer holding the value of the end index
            4. a pointer to a comparison function
Returns: an integer 
***************************************************************/ 
template <class T>
int partition(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&))
{
	int pivotIndex, mid;
	T pivotValue;

	mid = (start + end) / 2;

	//Swap elements start and mid of the vector
	std::swap(set[start], set[mid]);	
	pivotIndex = start;
	pivotValue = set[start];

	for (int scan = start + 1; scan <= end; scan++)
	{
		if (compare(set[scan], pivotValue))
		{
			++pivotIndex;
			//Swap elements pivotIndex and scan of the vector
			std::swap(set[scan], set[pivotIndex]);
		}
	}

	//Swap elements start and pivotIndex of the vector
	std::swap(set[start], set[pivotIndex]);

	return pivotIndex;
}

#endif /*QUICKSORT_H*/
