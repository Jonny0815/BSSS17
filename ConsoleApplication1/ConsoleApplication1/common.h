#pragma once

#include <mutex>

extern std::mutex num_rdr_mtx;
extern int num_rdr;
extern std::mutex writing;