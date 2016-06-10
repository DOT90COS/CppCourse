#include "config.h"
#include "except.h"
#include <sstream>
#include <iostream>
#include <string>
#include "helpers.h"

void Config::readConfig() {
    std::string line;
    auto lineCount = 1;
    std::stringstream ss_error;
    while (std::getline(inFile_, line)) {
        try {
            processLine(line);
        }
        catch (const BadConfig& e) {
            ss_error << "Config Line: " << lineCount << " " << e.what() << "\n";
        }
        lineCount++;
    }
    if (ss_error.str().size() > 0)
        throw BadConfig(ss_error.str());
}

void Config::processLine(const std::string& line) {
    if (line.size() == 0 || line.front() == '#') return;
    auto pos = line.find(':');
    if (pos == std::string::npos)
        throw BadConfig("Config Not Conforming!");
    auto key = trim(line.substr(0, pos));
    auto value = trim(line.substr(pos+1, line.size() - pos));
    settings_[key] = value;
}

Config::Config(const std::string& filename) :inFile_(filename) {
    if (!inFile_) throw BadFile(filename + " Could not open");
}

const std::string Config::operator[](const std::string& key) const {
    if (settings_.count(key)) return settings_.at(key);
    throw SettingNotFound(key + " Not Found!");
}

std::size_t Config::size() const
{
    return settings_.size();
}

std::string Config::operator[](const std::string& key) {
    if (settings_.count(key)) return settings_[key];
    throw SettingNotFound(key + " Not Found!");
}

Config::iterator Config::begin() {
    return settings_.begin();
}

Config::iterator Config::end() {
    return settings_.end();
}