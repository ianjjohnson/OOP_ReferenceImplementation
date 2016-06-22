#include "uniqueList.h"
#include "word.h"
#include "anagramFinder.h"

#include <fstream>

int main(int argc, char* argv[]){
	
	//Command-line-arguments cursory syntax check
	if(argc != 3) {
		std::cout << "Usage: ./<Execuatable> inputFileName outputFileName" << std::endl;
		return 1;
	}

	//Build an AnagramFinder object
	AnagramFinder a;

	//Populate the AnagramFinder from the file, and issue diagnostic information to the user
	std::cout << ((a.processFileInput(argv[1]))? "Successfully read input file " :  "Could not open file ") << argv[1] << std::endl;

	//Output the results of the AnagramFinder to a file, and issue diagnostic information to the user
	std::cout << "Writing to output file... " << (a.writeToFile(argv[2])? "Success!" : "Failed!") << std::endl;

	return 0;
}