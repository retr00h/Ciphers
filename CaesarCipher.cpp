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
  if (key < 0 or key > 25) throw std::invalid_argument("Caesar cipher requires 0 <= key <= 25.");
  this->key = key;
}

std::string CaesarCipher::encrypt(const std::string &plaintext) {
  std::string ciphertext;
  for (unsigned char c : plaintext) {
    c = tolower(c) + this->key;
    if (c > 'z') c -= CaesarCipher::diff;
    ciphertext += c;
  }
  return ciphertext;
}

std::string CaesarCipher::decrypt(const std::string &ciphertext) {
  std::string plaintext = "";
  for (char c : ciphertext) {
    c = tolower(c) - this->key;
    if (c < 'a') c += CaesarCipher::diff;
    plaintext += c;
  }
  return plaintext;
}

#endif //CIPHERS_CAESARCIPHER_H