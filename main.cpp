#include <iostream>
#include "CaesarCipher.cpp"

int main() {
  CaesarCipher cipher = CaesarCipher(3);
  std::string p = "ciao";
  std::string c = cipher.encrypt(p);
  std::cout << c << std::endl;
  std::cout << cipher.decrypt(c) << std::endl;
  return 0;
}
