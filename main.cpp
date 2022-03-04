#include <iostream>
#include "CaesarCipher.cpp"
#include "MonoAlphabeticCipher.cpp"

int main() {
  MonoAlphabeticCipher cipher = MonoAlphabeticCipher("mblcqdakihjnsepyovgfrxuwzt");
  std::string p = "ciao";
  std::string c = cipher.encrypt(p);
  std::cout << c << std::endl;
  std::cout << cipher.decrypt(c) << std::endl;
  return 0;
}
