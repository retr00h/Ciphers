#include <string>

class Cipher {
  public:
    inline virtual std::string encrypt(std::string plaintext) = 0;
    inline virtual std::string decrypt(std::string ciphertext) = 0;
};