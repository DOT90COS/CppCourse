#pragma once
#include <map>
#include <string>
#include <vector>

enum class KeyType { encrypt, decrypt };

std::map<char, char> readKey(const std::string& filename, KeyType type = KeyType::encrypt);

std::vector<std::string> encode(const std::vector<std::string>& data, std::map<char, char> key);

void writeData(const std::vector<std::string> data, const std::string& filename);

std::vector<std::string> readFile(const std::string& filename);
