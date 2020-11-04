// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>

// For std::isalpha and std::isupper
#include <cctype>

//Project headers
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "runCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  bool encryptRequested {false};
  bool decryptRequested {false};
  std::string key {"0"};

  if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested,
            inputFile, outputFile, encryptRequested, decryptRequested, key))
            {
              return 1;
            }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::cout << "Reading input file " << inputFile << std::endl;
    std::ifstream in_file {inputFile};
    bool ok_to_read = in_file.good();
    if(ok_to_read){
      //in_file >> inputChar;
      while(in_file >> inputChar)
      {
        inputText += transformChar(inputChar);
      }
    }
  }

  if (inputFile.empty()) {
  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
      // If the character isn't alphabetic or numeric, DONT add it.
      // Our ciphers can only operate on alphabetic characters.
    }
  }

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
    std::cout << "Writing output file " << outputFile << std::endl;
    std::ofstream out_file {outputFile};
    bool ok_to_write = out_file.good();
    if (ok_to_write){
      out_file << inputText;
    }
  }

  if (outputFile.empty()) {
    std::cout << "[warning] No output file specified " << std::endl;
    std::cout << inputText << std::endl;
  }

  //Handle encrypt/decrypt and run input file through ceasar cipher
  unsigned long Key = std::stoul (key,nullptr,10);
  if (encryptRequested){
    std::cout << "Ceasar Encryption Requested" << std::endl;
    std::cout << "CaesarCipher = " << runCaesarCipher (inputText, Key, encryptRequested, decryptRequested) << std::endl;
  }
  else if (decryptRequested){
    std::cout << "Ceasar Decryption Requested" << std::endl;
    std::cout << "CaesarCipher = " << runCaesarCipher (inputText, Key, encryptRequested, decryptRequested) << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions

  return 0;
}