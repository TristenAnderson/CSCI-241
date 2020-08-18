#ifndef MERGESORT_H
#define MERGESORT_H

using std::vector;

template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

template <class T>
void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&));


/***************************************************************
mergesort
Use: calls the mergesort function
Parameters: 1. set: a reference to a vector of template type
            2. a pointer to a comparison function
Returns: nothing
***************************************************************/ 
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size()-1, compare);
}

/*************************************************************
mergesort
Use: makes calls to itself to divide the dataset and combines the
division with a call to the merge function
Parameters: 1. set: a reference to a vector of template type
            2. start: an integer that holds the index of the first element
	    3. end: an integer that holds the index of the last element
	    4. a pointer to acomparison function
Returns: nothing
***************************************************************/
template <class T>
void mergeSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
 int mid;

   if (start < end)
      {
      mid = (start + end) / 2;

      // Divide and conquer
      mergeSort(set, start, mid, compare);
      mergeSort(set, mid+1, end, compare);

      // Combine
      merge(set, start, mid, end, compare);
      }
}

/***************************************************************
merge
Use: combines the divided data set comparing terms
Parameters: 1. set: the same thing 
            2. start: an integer holding the index of the start
	    3. end: an integer holding the index of the end
	    4. a pointer to a comparison function
Returns: nothing
***************************************************************/ 
template <class T>
void merge(vector<T>& set, int start, int mid, int end, bool (*compare)(const T&, const T&))
{
// Create temporary vector to hold merged subvectors
   vector<T> temp(end - start + 1);

   int i = start;    // Subscript for start of left sorted subvector
   int j = mid + 1;  // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= end)
      {
      if (compare(set[i], set[j]))
         {
         //Copy element i of set into element k of temp
	 temp[k] = set[i];
         //Add one to i
	 i++;
         //Add one to k
	 k++;
         }
      else
         {
         //Copy element j of set into element k of temp
	 temp[k] = set[j];
         //Add one to j
	 j++;
         //Add one to k
	 k++;
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {
      //Copy element i of set into element k of temp
      temp[k] = set[i];
      //Add one to i
      i++;
      //Add one to k
      k++;
      }

   // Copy over any remaining elements of right subvector
   while (j <= end)
      {
      //Copy element j of set into element k of temp
      temp[k] = set[i];
      //Add one to j
      j++;
      //Add one to k
      k++;
      }

   // Copy merged elements back into original vector
   for (i = 0, j = start; j <= end; ++i, ++j){
	set[j] = temp[i];}
      //Copy element i of temp into element j of set
}

#endif /*MERGESORT_H*/
