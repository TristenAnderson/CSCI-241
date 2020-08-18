/**
 *
 * CSCI 241 Assignment 1
 *
 * Author:  Tristen Anderson
 * z-ID:    z1820036
 * Date:    2/11/2019  11:59 pm
 *
 * This program tests functions for manipulating C strings.
 */

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

//function prototypes here
char* copy(char* destination, const char* source, size_t num);
char* reverseCopy(char* destination, const char* source, size_t num);
char* caseChangeCopy(char* destination, const char* source, size_t num);
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);
void read(char* destination, int num);

int main()
   {
   const int WORDSIZE = 15;
   char words[][WORDSIZE] = {"sprightful", "reason to row", "New York", "Bolton", "Frida", ""};
   char word[WORDSIZE];

   // Test the copy function
   cout << "Copy \"sprightful\", should see \"sprightful\".\n";
   copy(word, words[0], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;

   // Test the replaceCopy function 
   cout << "Replace 'r' in \"reason to row\" with 's', should see \"season to sow\".\n";
   replaceCopy(word, words[1], 'r', 's', sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   // Test the caseChangeCopy function
   cout << "Case change \"New York\", should see \"nEW yORK\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;  
   
   // Test the reverseCopy function
   cout << "Reverse \"Bolton\", should see \"notloB\"\n";
   reverseCopy(word, words[3], sizeof(word) - 1);;
   cout << word << endl << endl;

   // Test the limit on the reverseCopy function
   cout << "Reverse \"cytogeneticists\", should see \"tsicitenegotyc\"\n";
   reverseCopy(word, "cytogeneticists", sizeof(word) - 1);;
   cout << word << endl << endl;

   cout << "Reverse \"Frida\", change case, and replace 'D' with 'Z', should see \"AZIRf\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'D', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;  

   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;  
   
   cout << "Reverse your name and change case.\n";
   cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;

   return 0;
   }
   
   /***************************************************************
copy
 
Use: Copys a C string to destination 

Parameters: 1. destination: char where source is to be copied to
            2. source: a const char passed into the function to be copied
            3. num: the sizeof source - 1
            
Returns: a char, destination, the same word passed into the function
***************************************************************/

   char* copy(char* destination, const char* source, size_t num)
   {
   	strncpy(destination, source, num);				//copy the source to destination and return it 
   	destination[num] = '\0';						//just here for precaution
   	return destination;
   }
   
   /***************************************************************
reverseCopy 

Use: Takes a word passed in though source and reverse copies it into destination 

Parameters: 1. destination: the char where source is to be reversed copied to
            2. source: a const char holding the word passed into the function
            3. num: the sizeof word (i.e. source) - 1 
            
Returns: a char, destination, containing the reverse of the word passed into the function 
***************************************************************/
   
   char* reverseCopy(char* destination, const char* source, size_t num)
   {
   	
   	int i = 0
	, limit = 0;
   	
   	if (num >= strlen(source))					//num = sizeof(source) - 1
   	{											//sizeof string is larger than the length of the string then limit the copy to exclude the null character
   		limit = strlen(source) - 1;
	   }
	   
   	else 										//else limit the copy to exclude the 's' in cytogeneticists revrerse
   	{
   		limit = num - 1;
	   }
	  
   	for (i; i < num ; i++)
   	{
   		destination[i] = source[limit];			//reverse array subscripts from source to destination 
   		limit--;
	   } 
	   
	destination[i] = '\0';				//wipe anything remaining in destination after the copy of the char array passed into the function
	return destination;
   }

 /***************************************************************
caseChangeCopy

Use: Takes a word passed in though source, reads the case of each character and switches it.
Also copies the new reverse case word into destination

Parameters: 1. destination: the char where source is to be reversed copied to
            2. source: a const char holding the word passed into the function
            3. num: the sizeof word (i.e. source) - 1 
            
Returns: a char, destination, containing the reverse case of the word passed into the function 
***************************************************************/

   char* caseChangeCopy(char* destination, const char* source, size_t num)
   {
   	int i = 0;

   	for (i; i < num ; i++)
   	{
   		if (isupper(source[i]))
   			{
   				destination[i] = tolower(source[i]);		//if destination is upper then make lower
			   }
		else if (islower(source[i]))
		{
			destination[i] = toupper(source[i]);		//if source is lower then make detsination upper
		}
		else
		{
			destination[i] = source[i];		//if not alpha then copy it
		}
	}

	destination[i] = '\0';					//add null character to wipe anything else out of the char array
	return destination;
   }

    /***************************************************************
replaceCopy

Use: Takes a word passed in though source and searches for a target character to replace.
Copies the replaced word into destination.

Parameters: 1. destination: the char where source is to be reversed copied to
            2. source: a const char holding the word passed into the function
            3. num: the sizeof word (i.e. source) - 1
            4. target: a character to found in source and replaced in destination
            5. replace: a character to replace target in destination

Returns: a char, destination, containing source with target swapped with replace in destination
***************************************************************/

   char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num)
   {
   	int i = 0;

   	for ( i; i < num; i++)
   	{
   		if (source[i] == target)				//if the source subscipt i is the target for replacement then set that subscript in destination to the replacement char
   		{
   			destination[i] = replace;
		}
		else 									//else just copy source
		{
			destination[i] = source[i];
		}
	}
	destination[i] = '\0';						//add null character to the end to wipe any residew from destination
	return destination;
   }

   /***************************************************************
read

Use: Takes in user input and puts it into destination

Parameters: 1. destination: the char where source is to be reversed copied to
            2. num: the sizeof word (i.e. source) - 1 

Returns: nothing
***************************************************************/

   void read(char* destination, int num)
   {
       cin.getline(destination, num);		//take in user input string of lenth num 
   }

