/*
C++ Implementation of UniqueList class
UniqueList is an array of Word objects which contains no duplicate words

Author: Ian Johnson

Last Modified: June 22, 2016
*/


#include "uniqueList.h"
#include "word.h"

/*
Default constructor, sets the length of the list to 0
*/
UniqueList::UniqueList(){
	length = 0;
}

/*
Adds a word to this unique list. This function will see if newWord is already in the list,
and it will only add the new word to the list if it's unique (i.e. not in the list)
@param newWord: The new word to add to the list
@return: True if the new word was unique, false if it was already in the list
*/
bool UniqueList::add(Word newWord){
	for(int i = 0; i < length; i++){
		if(newWord == data[i]) return false;
	}
	data[length++] = newWord;
	return true;
}

/*
Friend function
Stream insertion operator, which inserts each word from the list into a stream
The number of unique words will be printed, and then each unique word will be printed on its own line
@param os: The stream to which the UniqueList will be written
@param list: The UniqueList to be written to the stream
@return: The os being written to
*/
std::ostream& operator<<(std::ostream& os, const UniqueList& list){
	os << "There are " << list.length << " unique character sets." << std::endl;
	for(int i = 0; i < list.length; i++)
		os << list.data[i] << std::endl;
	return os;
}


/*
Sorting function which sorts the Words in the list based on their c-string payloads' ASCII values
Standard bubble sort implementation
*/
void UniqueList::sort(){
	bool sorted = false;
	while(!sorted){
		sorted = true;
		for(int i = 0; i < length - 1; i++){
			if(data[i] > data[i+1]){
				sorted = false;
				Word tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
			}
		}
	}
}
