#include <stdexcept>
#include "Cipher.cpp"

class CaesarCipher : public Cipher {
  private:
    int key;
  public:
    inline CaesarCipher(int key);
    inline std::string encrypt(std::string plaintext) override;
    inline std::string decrypt(std::string ciphertext) override;
};

CaesarCipher::CaesarCipher(int key) {
  if (key <= 0 or key >= 26) throw std::invalid_argument("Caesar cipher requires 0 < key < 26.");
  this->key = key;
}

std::string CaesarCipher::encrypt(std::string plaintext) {
  std::string ciphertext = "";
  for (char c : plaintext) {
    ciphertext += (c + this->key);
  }
  return ciphertext;
}

std::string CaesarCipher::decrypt(std::string ciphertext) {
  std::string plaintext = "";
  for (char c : ciphertext) {
    plaintext += (c - this->key);
  }
  return plaintext;
}