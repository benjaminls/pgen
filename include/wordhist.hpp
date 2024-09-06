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


/* Add a blank prefix to a number to make the output string all have length maxLen */
std::string addBlankPrefixToNumber(const int &num, int maxNumberLen) {
    std::string numStr = std::to_string(num);
    int numLen = numStr.length();
    int numBlanks = maxNumberLen - numLen;
    std::string blankPrefix(numBlanks, ' ');
    return blankPrefix + numStr;
}

void validateStarChar(const char &starChar) {
    if (starChar == ' ') {
        std::cerr << "Error: Star character cannot be a space." << std::endl;
        return;
    }

    if (starChar == '\n') {
        std::cerr << "Error: Star character cannot be a newline." << std::endl;
        return;
    }

    if (starChar == '\t') {
        std::cerr << "Error: Star character cannot be a tab." << std::endl;
        return;
    }

    if (starChar == '\r') {
        std::cerr << "Error: Star character cannot be a carriage return." << std::endl;
        return;
    }

    if (starChar == '\0') {
        std::cerr << "Error: Star character cannot be a null character." << std::endl;
        return;
    }

    if (starChar == '\v') {
        std::cerr << "Error: Star character cannot be a vertical tab." << std::endl;
        return;
    }
}

void validateNumStars(const int &numStars) {
    if (numStars <= 0) {
        std::cerr << "Error: Number of stars must be positive." << std::endl;
        return;
    }
}

void validateWordLengths(const std::vector<int> &wordLengths) {
    if (wordLengths.size() == 0) {
        std::cerr << "Error: No words to print." << std::endl;
        return;
    }
}

/* Print histogram of word lengths */
void printWordHist(const std::vector<int> &wordLengths, int numStars = 50, char starChar = '*') {    
    // Validate inputs
    validateNumStars(numStars);
    validateWordLengths(wordLengths);
    validateStarChar(starChar);

    int maxLen = *std::max_element(wordLengths.begin(), wordLengths.end());

    int maxNumberLen = std::to_string(maxLen).length(); // Number of digits in the max length

    if (DEBUG) {
        std::cout << "Max word length: " << maxLen << std::endl;
        std::cout << "Number of stars: " << numStars << std::endl;
        std::cout << "Star character: " << starChar << std::endl;
        std::cout << "Max length of axes numbers: " << maxNumberLen<< std::endl;
    }

    for (int i = 1; i <= maxLen; i++) {
        
        std::cout << addBlankPrefixToNumber(i, maxNumberLen) << ": ";
        int count = std::count(wordLengths.begin(), wordLengths.end(), i);
        int numStarsToPrint = (int) (numStars * ((double) count / wordLengths.size()));
        for (int j = 0; j < numStarsToPrint; j++) {
            std::cout << starChar;
        }
        std::cout << std::endl;
    }
}