#include "config.h"
#include "except.h"
#include <sstream>
#include <iostream>
#include <string>
#include "helpers.h"

void Config::readConfig() {

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

Config::Config(const std::string& filename) {

}

std::size_t Config::size() const {
    return settings_.size();
}

const std::string Config::operator[](const std::string& key) const {
    return std::string();
}

std::string Config::operator[](const std::string& key) {
    return std::string();
}

Config::iterator Config::begin() {
    return settings_.begin();
}

Config::iterator Config::end() {
    return settings_.end();
}