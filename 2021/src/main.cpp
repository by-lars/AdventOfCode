#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include <fcntl.h>
#include <io.h>
#include <filesystem>

#include "Core/Reflection.h"
#include "Core/Logging.h"

void main() {

	AOC_DEBUG("Registered " << AOCLevelStore::Instance().GetLevels().size() << " AOC Levels");
	std::ifstream infile;

	auto& levels = AOCLevelStore::Instance().GetLevels();
	
	for (auto& level : levels) {
		AOC_INFO("---------- Level " << level.Name << " ----------");
		
		//First Run Test Case
		std::ifstream testFile("input/" + level.Name + "_TEST.txt");
		if (testFile.is_open()) {
			std::string expectedStr;
			std::getline(testFile, expectedStr);
			expectedStr.erase(0, 2);

			if (expectedStr.length() < 1) {
				AOC_ERROR("Error in Test Case File Syntax");
				return;
			}

			int expectedResult = std::stoi(expectedStr);
			uint64_t result = level.Ptr(testFile);
			if (result != expectedResult) {
				AOC_ERROR("Level failed Test Case");
				AOC_ERROR("Expected: " << expectedResult << " Got: " << result);
				return;
			}
			else {
				AOC_INFO("Passed Test Case");
			}
		}
		else {
			AOC_WARN("No Test Case File found!");
		}

		//Run Acctual Ibput
		std::ifstream infile("input/" + level.Name.substr(0, 1) + ".txt");
		if (infile.is_open() == false) {
			AOC_ERROR("Fatal Error: could not open file for level " << level.Name);
			return;
		}

		uint64_t answer = level.Ptr(infile);
		AOC_SUCCESS("Answer: " << answer);
		std::cout << std::endl;
	}	
}
