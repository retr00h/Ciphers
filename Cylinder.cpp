#ifndef CIPHERS_CYLINDER_H
#define CIPHERS_CYLINDER_H

#include <string>
#include <stdexcept>
#include "Cipher.cpp"

class Cylinder : Cipher {
  private:
    std::string originalKey;
    std::string currentKey;
    inline static bool isValid(const std::string &key);
    inline void rotate();
  public:
    inline Cylinder(const std::string &key);
    inline std::string encrypt(const std::string &plaintext) override;
    inline std::string decrypt(const std::string &ciphertext) override;
    inline void reset();
};

bool Cylinder::isValid(const std::string &key) {
  std::string lettersToFind = "abcdefghijklmnopqrstuvwxyz";
  for (char c : key) {
    int index = lettersToFind.find(tolower(c));
    if (index == std::string::npos) return false;
    else lettersToFind =
                 lettersToFind.substr(0, index) + lettersToFind.substr(index + 1);
  }
  return lettersToFind.length() == 0;
}

Cylinder::Cylinder(const std::string &key) {
  if (!Cylinder::isValid(key)) throw std::invalid_argument("Provided key must contain each letter of the alphabet one and only one time.");
  std::string lowerkey;
  for (char c : key) lowerkey += tolower(c);
  this->originalKey = this->currentKey = lowerkey;
}

void Cylinder::rotate() {
  std::string newKey;
  newKey = currentKey[currentKey.length()-1];
  newKey += currentKey.substr(0, currentKey.length()-1);
  this->currentKey = newKey;
}

std::string Cylinder::encrypt(const std::string &plaintext) {
  if (plaintext.length() != 1) throw std::invalid_argument("Cylinder can only encrypt one character at a time.");
  std::string ciphertext;
  ciphertext += currentKey[plaintext[0] - 'a'];
  rotate();
  return ciphertext;
}

std::string Cylinder::decrypt(const std::string &ciphertext) {
  if (ciphertext.length() != 1) throw std::invalid_argument("Cylinder can only decrypt one character at a time.");
  std::string plaintext;
  plaintext += ('a' + this->currentKey.find(ciphertext[0]));
  rotate();
  return plaintext;
}

void Cylinder::reset() {
  this->currentKey = this->originalKey;
}


#endif //CIPHERS_CYLINDER_H
