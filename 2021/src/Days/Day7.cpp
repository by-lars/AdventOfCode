#include "Core/Reflection.h"
#include "Core/Logging.h"

AOC_DAY(7A) {
	std::vector<int> positions;
	for (int i; file >> i;) {
		positions.push_back(i);
		if (file.peek() == ',') {
			file.ignore();
		}
	}

	int furthestPos = 0;
	for (auto& pos : positions) {
		furthestPos = std::max(pos, furthestPos);
	}

	int minFuelNeeded = INT_MAX;
	for (int pos = 0; pos < furthestPos; pos++) {
		int fuelNeeded = 0;
		for (auto & crabPos : positions) {
			fuelNeeded += std::abs(crabPos - pos);
		}

		minFuelNeeded = std::min(minFuelNeeded, fuelNeeded);
	}

	return minFuelNeeded;
}

AOC_DAY(7B) {
	std::vector<int> positions;
	for (int i; file >> i;) {
		positions.push_back(i);
		if (file.peek() == ',') {
			file.ignore();
		}
	}

	int furthestPos = 0;
	for (auto& pos : positions) {
		furthestPos = std::max(pos, furthestPos);
	}

	int minFuelNeeded = INT_MAX;
	for (int pos = 0; pos < furthestPos; pos++) {
		int fuelNeeded = 0;
		for (auto& crabPos : positions) {

			int steps = std::abs(crabPos - pos);
			fuelNeeded += (steps * (steps + 1)) / 2;
		
		}

		minFuelNeeded = std::min(minFuelNeeded, fuelNeeded);
	}

	return minFuelNeeded;
}