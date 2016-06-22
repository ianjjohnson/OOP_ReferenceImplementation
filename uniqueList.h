#ifndef UNIQUE_H
#define UNIQUE_H

#include "word.h"

class UniqueList{

private:

	Word data[1000];
	int length;

public:

	UniqueList();

	bool add(Word w);
	void sort();
	
	friend std::ostream& operator<<(std::ostream& os, const UniqueList& u);
};

#endif