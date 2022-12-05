#pragma once

#include <iostream>

#define AOC_CLR "\u001b[0m"
#define AOC_MGT "\u001b[35m"
#define AOC_CYN "\u001b[36;1m"
#define AOC_BLU "\u001b[34;1m"
#define AOC_GRN "\u001b[32;1m"
#define AOC_YLO "\u001b[33;1m"
#define AOC_RED "\u001b[31;1m"

#define AOC_LOG(msg, type, color) \
	std::cout << color << "[" << type << "] " << msg << AOC_CLR << std::endl;

#define AOC_DEBUG(msg) AOC_LOG(msg, "D", AOC_CYN)
#define AOC_INFO(msg) AOC_LOG(msg, "I", AOC_BLU)
#define AOC_SUCCESS(msg) AOC_LOG(msg, "S", AOC_GRN)
#define AOC_WARN(msg) AOC_LOG(msg, "W", AOC_YLO)
#define AOC_ERROR(msg) AOC_LOG(msg, "E", AOC_RED)