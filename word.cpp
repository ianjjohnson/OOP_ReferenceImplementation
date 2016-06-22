/*
C++ Implementation of Word class
Word is a wrapper for a c-string which keeps its own contents sorted by ASCII value

Author: Ian Johnson

Last Modified: June 22, 2016
*/

#include "word.h"
#include <cstring>

/*
Default constructor, makes the cstring payload an empty cstring (character 0 is null terminator)
*/
Word::Word(){
	data[0] = '\0';
}

/*
Constructor for the word class which copies the data from an existing cstring.
@postcondition: The characters in the cstring of this object are sorted alphabetically by ASCII value
*/
Word::Word(char* input){
	strcpy(data, input);
	sort();
}


/*
Sorting function which sorts the cstring payload of the word class.
Standard bubble sort implementation
*/
void Word::sort(){
	bool sorted = false;
	int len = strlen(data);
	while(!sorted){
		sorted = true;
		for(int i = 0; i < len - 1; i++){
			if(data[i+1] < data[i]){
				char tmp = data[i];
				data[i] = data[i+1];
				data[i+1] = tmp;
				sorted = false;
			}
		}
	}
}

/*
Friend function
Stream insertion operator, which inserts the cstring payload of the word into the file stream
@param os: The stream to which the Word will be written
@param w: The word to be written to the stream
@return: The os being written to
*/
std::ostream& operator<<(std::ostream& os, const Word& w){
	os << w.data;
	return os;
}

/*
Equality operator used for uniqueness
@param rhs: The right-hand-side of the operator, the Word to which thi one will be compared
@return: True if this word (the LHS of the operator) equals the RHS. Equality of two words is defined to be true if the cstring payloads of the two words are equal
*/
bool Word::operator==(const Word& rhs){
	return strcmp(rhs.data, data) == 0;
}

/*
Greater than operator for sorting
@param rhs: The right-hand-side of the operator, the Word to which this one will be compared
@return: True if this word (the LHS of the operator) is greater than the RHS
*/
bool Word::operator>(const Word& rhs){
	return strcmp(data, rhs.data) > 0;
}
