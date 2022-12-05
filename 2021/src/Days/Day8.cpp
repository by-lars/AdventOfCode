#include "Core/Reflection.h"
#include "Core/Logging.h"

#include <sstream>

/** 
	 1: 2 !
	2: 5 
	3: 5 
	 4: 4 !
	5: 5 
	6: 6 
	 7: 3 !
	 8: 7 !
	9: 6 

*/


AOC_DAY(8A) {
	std::vector<int> nSegments;
	std::string line;
	std::string tmp;

	while (std::getline(file, line)) {
		int pipeIndex = line.find('|');
		line = line.substr(pipeIndex + 2, line.length());

		std::stringstream ss(line);
		while (ss >> tmp) {
			nSegments.push_back(tmp.length());
		}
		
	}

	int sum = 0;

	for (auto& n : nSegments) {
		if (n == 2 || n == 4 || n == 3 || n == 7)
			sum++;
	}


	return sum;
}