#include <iostream>
#include "CaesarCipher.cpp"
#include "MonoAlphabeticCipher.cpp"
#include "PlayfairCipher.cpp"

int main() {
  PlayfairCipher cipher = PlayfairCipher("monarchy");
  std::string p = "balloon";
  std::string c = cipher.encrypt(p); // IB SU SU AV AV AW
  std::cout << c << std::endl;
  std::cout << cipher.decrypt(c) << std::endl;
  return 0;
}
