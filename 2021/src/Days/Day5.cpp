
#include "Core/Reflection.h"
#include "Core/Logging.h"
#include <string>
#include <sstream>
#include <unordered_map>
#include <array>
#include <math.h>

struct Line {
	int x1, y1;
	int x2, y2;
};

#define INDEX(x,y) (y * 1000) + x

void ParseFile(std::ifstream& file, std::vector<std::array<int, 4>>& lines) {
	
	std::string line;
	std::array<int, 4> tmpLine;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		int index = 0;
		for (int i; ss >> i;) {
			tmpLine[index] = i;
			index++;
			bool skip = true;
			while (skip) {
				switch (ss.peek()) {
				case ',':
				case '-':
				case '>':
				case ' ':
					ss.ignore();
					break;
				default:
					skip = false;
					break;
				}
			}
		}

		lines.push_back(tmpLine);
	}
}

AOC_DAY(5A) {

	int* map = new int[1000 * 1000];
	for (int i = 0; i < 1000 * 1000; i++) {
		map[i] = 0;
	}
	
	std::vector<std::array<int, 4>> lines;
	ParseFile(file, lines);

	for (auto& x : lines) {
		Line* line = (Line*)&x;

		if (line->x1 == line->x2) {
			int y1 = std::min(line->y1, line->y2);
			int y2 = std::max(line->y1, line->y2);
			for (int i = y1; i <= y2; i++) {
				map[INDEX(line->x1, i)] += 1;
			}
		}
		else if (line->y1 == line->y2) {
			int x1 = std::min(line->x1, line->x2);
			int x2 = std::max(line->x1, line->x2);
			for (int i = x1; i <= x2; i++) {
				map[INDEX(i, line->y1)] += 1;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < 1000*1000; i++) {
		if (map[i] > 1) {
			sum += 1;
		}
	}
	

	delete[] map;
	return sum;
}

AOC_DAY(5B) {

	int* map = new int[1000 * 1000];
	for (int i = 0; i < 1000 * 1000; i++) {
		map[i] = 0;
	}

	std::vector<std::array<int, 4>> lines;
	ParseFile(file, lines);

	for (auto& x : lines) {
		Line* line = (Line*)&x;
			
		int xPos = line->x1;
		int yPos = line->y1;

		int xDir = line->x1 < line->x2 ? 1 : -1;
		xDir = line->x1 == line->x2 ? 0 : xDir;
			
		int yDir = line->y1 < line->y2 ? 1 : -1;
		yDir = line->y1 == line->y2 ? 0 : yDir;

		while (xPos != line->x2 || yPos != line->y2) {
			map[INDEX(xPos, yPos)] += 1;

			xPos += xDir;
			yPos += yDir;
		}
		map[INDEX(xPos, yPos)] += 1;	
	}

	int sum = 0;
	for (int i = 0; i < 1000 * 1000; i++) {
		if (map[i] > 1) {
			sum += 1;
		}
	}


	delete[] map;
	return sum;
}