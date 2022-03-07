#include <iostream>
#include "CaesarCipher.cpp"
#include "MonoAlphabeticCipher.cpp"
#include "PlayfairCipher.cpp"

int main() {
  PlayfairCipher cipher = PlayfairCipher("monarchy");
  std::string p = "johnnycreek";
  std::string c = cipher.encrypt(p);
  std::cout << c << std::endl;
  std::cout << cipher.decrypt(c) << std::endl;
  return 0;
}
