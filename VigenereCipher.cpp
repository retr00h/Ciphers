#ifndef CIPHERS_VIGENERECIPHER_H
#define CIPHERS_VIGENERECIPHER_H

#include <vector>
#include "Cipher.cpp"
#include "CaesarCipher.cpp"

class VigenereCipher : Cipher {
  private:
    std::string key;
    std::vector<CaesarCipher> monoalphabeticCiphers = std::vector<CaesarCipher>();
  public:
    inline VigenereCipher(const std::string &key);
    inline std::string encrypt(const std::string &plaintext) override;
    inline std::string decrypt(const std::string &ciphertext) override;
};

VigenereCipher::VigenereCipher(const std::string &key) {
  std::string lowercaseKey;
  for (char c : key) lowercaseKey += tolower(c);
  this->key = lowercaseKey;
  for (int i = 0; i < 26; i++) {
    monoalphabeticCiphers.emplace_back(CaesarCipher(i));
  }
}

std::string VigenereCipher::encrypt(const std::string &plaintext) {
  std::string ciphertext;
  for (int i = 0; i < plaintext.length(); i++) {
    int whichCipher = (this->key[i % key.length()] - 'a');
    std::string c;
    c += tolower(plaintext[i]);
    std::string encryptedChar = monoalphabeticCiphers[whichCipher].encrypt(c);
    ciphertext += encryptedChar;
  }
  return ciphertext;
}

std::string VigenereCipher::decrypt(const std::string &ciphertext) {
  std::string plaintext;
  for (int i = 0; i < ciphertext.length(); i++) {
    int whichCipher = (this->key[i % key.length()] - 'a') % 26;
    std::string c;
    c += tolower(ciphertext[i]);
    std::string decryptedChar = monoalphabeticCiphers[whichCipher].decrypt(c);
    plaintext += decryptedChar;
  }
  return plaintext;
}

#endif //CIPHERS_VIGENERECIPHER_H