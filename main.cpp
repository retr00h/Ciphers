#include <iostream>
#include "CaesarCipher.cpp"

int main() {
  CaesarCipher cipher = CaesarCipher(1);
  std::string p = "ciaosonounaz";
  std::string c = cipher.encrypt(p);
  std::cout << c << std::endl;
  std::cout << cipher.decrypt(c) << std::endl;
  return 0;
}
