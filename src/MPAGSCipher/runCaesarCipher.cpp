// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// For std::isalpha and std::isupper
#include <cctype>

//Project headers
#include "runCaesarCipher.hpp"

std::string runCaesarCipher (const std::string& inputText,
                const int key, const bool encryptRequested, const bool decryptRequested){
    int shift {0};
    if (encryptRequested){shift = key;};
    if (decryptRequested){shift = -key;};
    std::string caesarCipher {""};
    char letters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(const char& c : inputText) {
      for(int i=1; i<=26; i++){
        if(c == letters[i-1]){
          if(shift + i > 25){int index = (shift+i)%25;
            //std::cout << "Shifted Letter = " << letters[index] << std::endl;
            caesarCipher += letters[index];
          }
          else if (shift + i < 25){int index = 25 - (shift+i)%25;
            //std::cout << "Shifted Letter = " << letters[index] << std::endl;
            caesarCipher += letters[index];
          }
          else {
            //std::cout << "Shifted Letter = " << letters[shift + i] << std::endl;
            caesarCipher += letters[shift + i];
          }
        }

      };

    }
    return caesarCipher;
  }