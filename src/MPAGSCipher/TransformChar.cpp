// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

//Project headers
#include "TransformChar.hpp"

std::string transformChar (const char inputChar)
{
  std::string inputText {""};
  /* Takes input characters, converts lower case to upper and
     converts numbers to words,appends to a ciperh string. */
  // Uppercase alphabetic characters
  if (std::isalpha(inputChar)) {
      inputText += std::toupper(inputChar);
      return inputText;
    }

   // Transliterate digits to English words
  switch (inputChar) {
      case '0':
        inputText += "ZERO";
        break;
      case '1':
        inputText += "ONE";
        break;
      case '2':
        inputText += "TWO";
        break;
      case '3':
        inputText += "THREE";
        break;
      case '4':
        inputText += "FOUR";
        break;
      case '5':
        inputText += "FIVE";
        break;
      case '6':
        inputText += "SIX";
        break;
      case '7':
        inputText += "SEVEN";
        break;
      case '8':
        inputText += "EIGHT";
        break;
      case '9':
        inputText += "NINE";
        break;
    }
  return inputText;
}
