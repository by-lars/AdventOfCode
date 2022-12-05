#pragma once

#include <vector>
#include <fstream>
#include "Core/Util.h"

using AOC_FUNCTION_PTR = uint64_t(*)(std::ifstream& file);


struct AOCLevel {
	AOC_FUNCTION_PTR Ptr;
	std::string Name;
};

class AOCLevelStore {
public:
	std::vector<AOCLevel>& GetLevels();
	void RegisterLevel(const AOCLevel& level);

	//Singleton
	static AOCLevelStore& Instance();
	AOCLevelStore(AOCLevelStore const&) = delete;
	void operator=(AOCLevelStore const&) = delete;
private: 
	AOCLevelStore() = default;
	std::vector<AOCLevel> m_Levels;
};


class AOCReflector {
public:
	AOCReflector(AOCLevel level);
};

#define AOC_DAY(name)																					\
	uint64_t AOC_DAY_##name(std::ifstream& file);															\
	AOCReflector AOC_DAY_REFLECTOR_##name({(AOC_FUNCTION_PTR)&AOC_DAY_##name, STR(name)});				\
	uint64_t AOC_DAY_##name(std::ifstream& file)																\

