#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// For std::isalpha and std::isupper
#include <cctype>

std::string runCaesarCipher (const std::string& inputText,
                const int key, const bool encryptRequested, const bool decryptRequested);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP