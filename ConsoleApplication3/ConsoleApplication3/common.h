#pragma once

#include <math.h>
#include <vector>

extern const int mem_wide = 16;
extern const int offset = 10; // keep lower than mem_wide !
extern const int offset_pow = pow(2, offset);
extern const int frames_count = 8192/offset_pow;


extern bool RAM[8192] = {};
extern std::vector <bool> HDD;