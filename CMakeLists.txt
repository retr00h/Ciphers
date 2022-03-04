cmake_minimum_required(VERSION 3.16)
project(Ciphers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ciphers main.cpp Cipher.cpp CaesarCipher.cpp MonoAlphabeticCipher.cpp PlayfairCipher.cpp)
