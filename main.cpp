#include <iostream>
#include "CaesarCipher.cpp"
#include "MonoAlphabeticCipher.cpp"
#include "PlayfairCipher.cpp"
#include "VigenereCipher.cpp"

int main() {
  VigenereCipher cipher = VigenereCipher("ciao");
  std::string p = "ciao";
  std::string c = cipher.encrypt(p);
  std::cout << c << std::endl;
  std::cout << cipher.decrypt(c) << std::endl;
  return 0;
}
