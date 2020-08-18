#pragma once

#ifndef QUICKSORT_H
#define QUICKSORT_H

using std::vector;

template <class T>
void quickSort(vector<T>& set, bool(*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&));

template <class T>
int partition(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&));


template <class T>
void quickSort(vector<T>& set, bool(*compare)(const T&, const T&))
{
	quickSort(set, 0, set.size() - 1, compare);
}

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
