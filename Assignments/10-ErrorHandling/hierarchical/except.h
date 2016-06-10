#pragma once
#include <stdexcept>

struct BadConfig :public std::runtime_error {
    BadConfig(const std::string& what) :std::runtime_error(what) {}
};

struct SettingNotFound :public std::runtime_error {
    SettingNotFound(const std::string& what) :std::runtime_error(what) {}
};

struct BadFile :public std::runtime_error {
    BadFile(const std::string& what) :std::runtime_error(what) {}
};
