#ifndef CIPHERS_CAESARCIPHER_H
#define CIPHERS_CAESARCIPHER_H

#include <stdexcept>
#include "Cipher.cpp"

class CaesarCipher : public Cipher {
  private:
    int key;
    static const char diff = 'z' - 'a' + 1;
  public:
    inline CaesarCipher(const int key);
    inline std::string encrypt(const std::string &plaintext) override;
    inline std::string decrypt(const std::string &ciphertext) override;
};

CaesarCipher::CaesarCipher(const int key) {
  if (key <= 0 or key >= 26) throw std::invalid_argument("Caesar cipher requires 0 < key < 26.");
  this->key = key;
}

std::string CaesarCipher::encrypt(const std::string &plaintext) {
  std::string ciphertext = "";
  char newC;
  for (char c : plaintext) {
    newC = tolower(c) + this->key;
    if (newC > 'z') newC -= CaesarCipher::diff;
    ciphertext += (newC);
  }
  return ciphertext;
}

std::string CaesarCipher::decrypt(const std::string &ciphertext) {
  std::string plaintext = "";
  char newC;
  for (char c : ciphertext) {
    newC = tolower(c) - this->key;
    if (newC < 'a') newC += CaesarCipher::diff;
    plaintext += newC;
  }
  return plaintext;
}

#endif //CIPHERS_CAESARCIPHER_H