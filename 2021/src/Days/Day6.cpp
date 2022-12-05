#include "Core/Reflection.h"
#include "Core/Logging.h"
#include <iomanip>

AOC_DAY(6A) {
	int fishPerDay[7] = { 0 };
	int newFish[2] = { 0 };

	for (int i; file >> i;) {
		fishPerDay[i]++;

		if (file.peek() == ',')
			file.ignore();
	}

	int population = 0;


	for (int day = 0; day < 80; day++) {
		int index = day % 7;
		int newIndex = day % 2;

		int spawnToday = fishPerDay[index];
		fishPerDay[index] += newFish[newIndex];
		newFish[newIndex] = spawnToday;
	}

	for (auto x : fishPerDay) {
		//AOC_DEBUG(x);
		population += x;
	}

	for (auto x : newFish) {
	//	AOC_DEBUG(x);
		population += x;
	}


	return population;
}

AOC_DAY(6B) {
	uint64_t fishPerDay[7] = { 0 };
	uint64_t newFish[2] = { 0 };


	for (int i; file >> i;) {
		fishPerDay[i]++;

		if (file.peek() == ',')
			file.ignore();
	}

	uint64_t population = 0;


	for (int day = 0; day < 256; day++) {
		int index = day % 7;
		int newIndex = day % 2;
		uint64_t spawnToday = fishPerDay[index];
		fishPerDay[index] += newFish[newIndex];
		newFish[newIndex] = spawnToday;

	}

	for (auto x : fishPerDay) {
		//AOC_DEBUG(x);
		population += x;
	}

	for (auto x : newFish) {
	//	AOC_DEBUG(x);
		population += x;
	}



	return population;
}