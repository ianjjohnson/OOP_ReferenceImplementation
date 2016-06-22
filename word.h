#ifndef WORD_H
#define WORD_H

#include <iostream>

class Word{

private:

	char data[26];
	
	void sort();

public:

	Word(char* input);
	Word();

	bool operator==(const Word& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Word& w);
	bool operator>(const Word& rhs);

};



#endif

