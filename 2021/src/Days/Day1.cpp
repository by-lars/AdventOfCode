#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "Core/Reflection.h"
#include "Core/Logging.h"

AOC_DAY(1A) {
	std::string line;

	int prevDepth = 0;
	int increments = -1;
	while (std::getline(file, line)) {
		int depth = std::stoi(line);

		if (depth > prevDepth) {
			increments++;
		}

		prevDepth = depth;
	}

	return increments;
}

AOC_DAY(1B) {
	std::string line;

	int m1 = 0;
	int m2 = 0;
	int m3 = 0;
	int m4 = 0;

	int counter = 0;

	int increments = -1;
	while (std::getline(file, line)) {
		int depth = std::stoi(line);

		m1 = m2;
		m2 = m3;
		m3 = m4;
		m4 = depth;

		if (counter > 2) {
			if (m1 + m2 + m3 < m2 + m3 + m4) {
				increments++;
			}
		}


		counter++;
	}


	if (m1 + m2 + m3 < m2 + m3 + m4) {
		increments++;
	}


	return increments;
}