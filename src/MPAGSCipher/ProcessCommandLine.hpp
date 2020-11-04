#ifndef MPAGSCIPHER_PROCESSCOMMANDLINES_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINES_HPP


// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

//bool processCommandLine (const char in);
bool processCommandLine (
                          const std::vector<std::string>& cmdLineArgs,
                          bool& helpRequested,
                          bool& versionRequested,
                          std::string& inputFile,
                          std::string& outputFile,
                          bool& encryptRequested,
                          bool& decryptRequested,
                          std::string& key);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINES_HPP