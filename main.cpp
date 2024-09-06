#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <argparse/argparse.hpp>

#include "spdlog/spdlog.h"
#include "include/wordhist.hpp"

#define DEBUG true

int main( int argc, char *argv[] ) {
    std::string filename = "lists/nouns.txt";

    std::vector<std::string> words;
    
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return 1;
    }
    
    // Read the file line by line and store each word in the vector
    std::string word;
    while (std::getline(file, word)) {
        words.push_back(word);
    }
    
    // Close the file
    file.close();
    
    // Set the environment variable PGEN_DEBUG to the value of DEBUG
    setenv("PGEN_DEBUG", DEBUG ? "1" : "0", 1);

    std::vector<int> wordLengths;
    createWordLengthVector(words, wordLengths);

    printWordHist(wordLengths);

    // Output the words to confirm loading
    // std::cout << "Words loaded from file: " << std::endl;
    // for (const auto &w : words) {
    //     std::cout << w << std::endl;
    // }
    
    return 0;
}