#pragma once
#include <unordered_map>
#include <string>

class Encryption
{
public:
    Encryption(const std::string& key);
    //Generate a random key
    Encryption();
    std::string encrypt(const std::string& clearText) const;
    std::string decrypt(const std::string& encodeText) const;
    bool setKey(const std::string& key);
    std::string getKey() const;
    std::string generateKey();

private:
    enum class KeyType{ EncryptKey, DecryptKey };
    std::string encode(const std::string& data, KeyType);

    std::unordered_map<char, char> encrypt_key_;
    std::unordered_map<char, char> decrypt_key_;
};