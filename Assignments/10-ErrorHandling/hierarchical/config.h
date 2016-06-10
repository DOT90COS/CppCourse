#pragma once
#include <fstream>
#include <map>
#include <string>

class Config {
    std::ifstream inFile_;
    std::map<std::string, std::string> settings_;


    /*!
    * @brief Processes a line of a config file
    * @throw Can throw BadConfig if the line is malformed
    */
    void processLine(const std::string& line);
public:
    using iterator = std::map<std::string, std::string>::iterator;

    /*
    * @throws BadFile if can't open the file
    */
    Config(const std::string& filename);

    /*!
    * @brief Processes the config file
    *
    *  Should process every line possible. Lines that weren't able to 
    *  be processed should be put into a message and thrown in BadConfig
    * @throw BadConfig
    */
    void readConfig();

    /*!
    * @brief Gets a setting from the config.
    * @throw SettingNotFound if asked for something that isn't there.
    */
    std::string operator[](const std::string& key);

    /*!
    * @brief Const version of the setting getter
    * @throw SettingNotFound if asked for something that isn't there.
    */
    const std::string operator[](const std::string& key) const;

    /*!
    * @brief Returns the number of settings stored.
    */
    std::size_t size() const;
    iterator begin();
    iterator end();
};