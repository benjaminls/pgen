#include <iostream>
#include <vector>
#include <string>

const int DEBUG = true;

void createWordLengthVector(const std::vector<std::string> &words, std::vector<int> &wordLengths){
    // Fill the wordLengths vector with the lengths of the words
    for (const auto &w : words) {
        wordLengths.push_back(w.length());
    }
}

void printWordHist(const std::vector<int> &wordLengths, int numStars = 50) {    
    // Create a histogram of word lengths printed to stdout using stars
    int maxLen = *std::max_element(wordLengths.begin(), wordLengths.end());

    if (DEBUG) {
        std::cout << "Max word length: " << maxLen << std::endl;
        std::cout << "Number of stars: " << numStars << std::endl;
    }

    for (int i = 1; i <= maxLen; i++) {
        std::cout << i << ": ";
        int count = std::count(wordLengths.begin(), wordLengths.end(), i);
        int numStarsToPrint = (int) (numStars * ((double) count / wordLengths.size()));
        for (int j = 0; j < numStarsToPrint; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}