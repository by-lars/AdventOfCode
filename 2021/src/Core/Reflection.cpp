#include "Core/Reflection.h"
#include <iostream>
#include <fstream>
#include <string>

AOCReflector::AOCReflector(AOCLevel level) {
	AOCLevelStore::Instance().RegisterLevel(level);
}

void AOCLevelStore::RegisterLevel(const AOCLevel& level) {
	m_Levels.push_back(level);
}

std::vector<AOCLevel>& AOCLevelStore::GetLevels() {
	return m_Levels;
}

AOCLevelStore& AOCLevelStore::Instance() {
	static AOCLevelStore instance;
	return instance;
}