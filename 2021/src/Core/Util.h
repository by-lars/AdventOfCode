#pragma once
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define PASTER(x,y) x ## y
#define EVALUATOR(x,y) PASTER(x,y)