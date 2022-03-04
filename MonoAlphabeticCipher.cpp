#ifndef CIPHERS_MONOALPHABETICCIPHER_H
#define CIPHERS_MONOALPHABETICCIPHER_H

#include <stdexcept>
#include "Cipher.cpp"

class MonoAlphabeticCipher : public Cipher {
  private:
    std::string key;
    inline static bool isValid(const std::string &key);
  public:
    inline MonoAlphabeticCipher(const std::string &key);
    inline std::string encrypt(const std::string &plaintext) override;
    inline std::string decrypt(const std::string &ciphertext) override;
};

bool MonoAlphabeticCipher::isValid(const std::string &key) {
  std::string lettersToFind = "abcdefghijklmnopqrstuvwxyz";
  for (char c : key) {
    int index = lettersToFind.find(tolower(c));
    if (index == std::string::npos) return false;
    else lettersToFind =
            lettersToFind.substr(0, index) + lettersToFind.substr(index + 1);
  }
  return lettersToFind.length() == 0;
}

MonoAlphabeticCipher::MonoAlphabeticCipher(const std::string &key) {
  if (!MonoAlphabeticCipher::isValid(key)) throw std::invalid_argument("Provided key must contain each letter of the alphabet one and only one time.");
  std::string newKey;
  for (char c : key) newKey += tolower(c);
  this->key = newKey;
}

std::string MonoAlphabeticCipher::encrypt(const std::string &plaintext) {
  std::string ciphertext;
  for (char c : plaintext) {
    ciphertext += this->key[-('a' - tolower(c))];
  }
  return ciphertext;
}

std::string MonoAlphabeticCipher::decrypt(const std::string &ciphertext) {
  std::string plaintext;
  for (char c : ciphertext) {
    int index = this->key.find(c);
    plaintext += ('a' + index);
  }
  return plaintext;
}

#endif //CIPHERS_MONOALPHABETICCIPHER_H