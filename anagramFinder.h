#ifndef ANA_H
#define ANA_H

#include "uniqueList.h"

class AnagramFinder{

private:

	UniqueList list;

public:

	bool processFileInput(char* fileName);
	bool writeToFile(char* fileName);

};



#endif