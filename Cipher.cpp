#ifndef CIPHERS_CIPHER_H
#define CIPHERS_CIPHER_H
#include <string>

class Cipher {
public:
    inline virtual std::string encrypt(const std::string &plaintext) = 0;
    inline virtual std::string decrypt(const std::string &ciphertext) = 0;
};

#endif //CIPHERS_CIPHER_H
