/*
C++ Implementation of AnagramFinder class
AnagramFinder is a master class which uses a UniqueList to count unique anagrams in a file

Author: Ian Johnson

Last Modified: June 22, 2016
*/

#include "anagramFinder.h"
#include <fstream>

/*
Populates the UniqueList from a file called fileName and sorts the list by ASCII value
@param fileName: The name of the file to read from, as a c-string
@return: True if the file is found, false if the file does not exist
*/
bool AnagramFinder::processFileInput(char* fileName){

	//Open the file stream
	std::ifstream in(fileName);
	if(!in.is_open()) return false;

	//Temp stack-allocated array to store the data from the file
	char tmp[26];

	//Skip over the first line of the file, since it's a number
	in >> tmp;

	/* Iterate through every cstring in the file,
	build a Word object from it, and add the Word to the list*/
	while(!in.eof()){
		in >> tmp;
		list.add(Word(tmp));
	}

	//Sort the unique list by ASCII value
	list.sort();

	//Close the input file stream
	in.close();

	//Return true to indicate successful file read
	return true;

}


/*
Write the results of the anagram finder to a file whose name is fileName
@param fileName: The name of the file to write to, as a c-string
@return: True if the file was written to successfully, false if an error occurred opening the file stream
*/
bool AnagramFinder::writeToFile(char* fileName){

	//Open the file stream
	std::ofstream f(fileName);
	if(!f.is_open()) return false;

	//Write the unique list to the file stream
	f << list;

	//Close the output file stream
	f.close();

	//Return true to indicate successful file write
	return true;

}