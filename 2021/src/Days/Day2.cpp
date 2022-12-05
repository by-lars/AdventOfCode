#pragma once
#include <fstream>
#include <string>
#include <iostream>

#include "Core/Reflection.h"
#include "Core/Logging.h"

AOC_DAY(2A) {
	std::string command;
	int delta;
	int horizontal = 0;
	int depth = 0;
	while (file >> command >> delta) {
		switch (command[0]) {
		case 'f':
			horizontal += delta;
			break;
		case 'd':
			depth += delta;
			break;
		case 'u':
			depth -= delta;
			break;
		}
	}

	return horizontal * depth;
}

AOC_DAY(2B) {
	std::string command;
	int delta;
	int horizontal = 0;
	int depth = 0;
	int aim = 0;

	while (file >> command >> delta) {
		switch (command[0]) {
		case 'f':
			horizontal += delta;
			depth += aim * delta;
			break;
		case 'd':
			aim += delta;
			break;
		case 'u':
			aim -= delta;
			break;
		}
	}

	return horizontal * depth;
}