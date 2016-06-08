#pragma once

#include <Windows.h>
#include <fstream>
#include <cstdint>
#include <string>
#include <random>


std::string random_string(std::size_t size)
{
	std::random_device rnd;
	std::mt19937 gener(rnd());
	std::uniform_int_distribution<> d(0x41, 0x5a);
	std::string tmp = "";

	for (std::size_t i = 0; i < size; ++i)
		tmp += static_cast<char>(d(gener));

	return tmp;
}

bool trunc_file(const std::string& fname)
{
	std::ofstream f;
	f.open(fname, std::ios::trunc);
	if (!f.is_open())
		return false;

	f << "" << std::endl;

	f.close();

	return true;
}

bool random_file(const std::string& name, std::size_t size, std::string& outf)
{
	std::ofstream f;

	f.open(name, std::ios::trunc);

	if (!f.is_open())
		return false;

	
	f << (outf = random_string(size)) << std::endl;

	f.close();

	return true;
}

std::string load_file(const std::string& name)
{
	std::stringstream ss;
	std::ifstream fs;

	fs.open(name);
	if (!fs.is_open())
		return "";

	std::string tmp;

	fs >> tmp;

	return tmp;
}

class gLockFile {
public:
	gLockFile (const std::string& name) {
		auto hf = CreateFileA(name.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		hfile = hf;
		if (INVALID_HANDLE_VALUE == hf)
			throw std::runtime_error("[x] File open failed!");
	}
	~gLockFile() { CloseHandle(hfile); }
private:
	HANDLE hfile;
};