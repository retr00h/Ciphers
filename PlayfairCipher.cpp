#ifndef CIPHERS_PLAYFAIRCIPHER_H
#define CIPHERS_PLAYFAIRCIPHER_H

#include <stdexcept>
#include <vector>
#include "Cipher.cpp"

class PlayfairCipher : public Cipher {
  private:
    std::string key;
    inline void reorderKey();
    inline std::vector<std::string> findPairs(const std::string &str);
  public:
    inline PlayfairCipher(const std::string &key);
    inline std::string encrypt(const std::string &plaintext) override;
    inline std::string decrypt(const std::string &ciphertext) override;
};

void PlayfairCipher::reorderKey() {
  std::string foundChars;
  bool ij = false;
  for (char c : this->key) {
    if (!ij and (c == 'i' or c == 'j')) ij = true;
    if (foundChars.find(c) == std::string::npos) foundChars += c;
  }
  for (char c : "abcdefghijklmnopqrstuvwxyz") {
    // gestire corner case i/j
    if (c == 'i' or c == 'j') {
      if (!ij) {
        ij = true;
        foundChars += c;
      }
    } else if (foundChars.find(c) == std::string::npos) foundChars += c;
  }
  this->key = foundChars;
}

PlayfairCipher::PlayfairCipher(const std::string &key) {
  if (key.length() == 0) throw std::invalid_argument("Key must not be empty.");
  std::string newKey;
  for (char c : key) {
    newKey += tolower(c);
  }
  this->key = key;
  reorderKey();
}

std::vector<std::string> PlayfairCipher::findPairs(const std::string &str) {
  if (str.length() % 2 != 0) throw std::invalid_argument("Text length must be multiple of 2.");
  std::vector<std::string> pairs = std::vector<std::string>();
  std::string pair;
  for (int i = 0; i <= str.length(); i++) {
    if (i % 2 == 0) {
      if (!pair.empty()) {
        if (pair[0] != 'x' and pair[0] == pair[1]) {
          std::string pairToAdd;
          pairToAdd += pair[0];
          pairToAdd += 'x';
          pairs.emplace_back(pairToAdd);
          pairs.emplace_back(pairToAdd);
        } else pairs.emplace_back(pair);
      }
      pair = tolower(str[i]);
    }
    else pair += tolower(str[i]);
  }
  return pairs;
}

std::string PlayfairCipher::encrypt(const std::string &plaintext) {
  std::string textToEncrypt = plaintext;
  if (textToEncrypt.length() % 2 != 0) textToEncrypt += 'x';
  std::string ciphertext;
  std::vector<std::string> pairs = findPairs(textToEncrypt);

  for (std::string pair : pairs) {
    int index1 = key.find(pair[0]);
    int x1 = index1 / 5;
    int y1 = index1 % 5;
    int index2 = key.find(pair[1]);
    int x2 = index2 / 5;
    int y2 = index2 % 5;

    if (x1 == x2) {
      y1 = (y1 + 1) % 5;
      y2 = (y2 + 1) % 5;
    } else if (y1 == y2) {
      x1 = (x1 + 1) % 5;
      x2 = (x2 + 1) % 5;
    } else {
      int tmp = y2;
      y2 = y1;
      y1 = tmp;
    }

    ciphertext += key[5 * x1 + y1];
    ciphertext += key[5 * x2 + y2];
  }

  return ciphertext;
}

std::string PlayfairCipher::decrypt(const std::string &ciphertext) {
  std::string plaintext;
  std::vector<std::string> pairs = findPairs(ciphertext);

  for (std::string pair : pairs) {
    int index1 = key.find(pair[0]);
    int x1 = index1 / 5;
    int y1 = index1 % 5;
    int index2 = key.find(pair[1]);
    int x2 = index2 / 5;
    int y2 = index2 % 5;

    if (x1 == x2) {
      y1 -= 1;
      y2 -= 1;
      if (y1 < 0) y1 = 4;
      if (y2 < 0) y2 = 4;
    } else if (y1 == y2) {
      x1 -= 1;
      x2 -= 1;
      if (x1 < 0) x1 = 4;
      if (x2 < 0) x2 = 4;
    } else {
      int tmp = y2;
      y2 = y1;
      y1 = tmp;
    }

    plaintext += key[5 * x1 + y1];
    plaintext += key[5 * x2 + y2];
  }
  return plaintext;
}

#endif //CIPHERS_PLAYFAIRCIPHER_H