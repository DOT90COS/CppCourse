#pragma once

#include <Windows.h>
#include <vector>
#include <string>
#include <cstdint>

std::string get_proc_name(uint32_t pid);
uint32_t get_pidlist(std::vector<uint32_t>& buf);