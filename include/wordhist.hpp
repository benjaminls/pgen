#include <iostream>
#include <vector>
#include <string>

// #define DEBUG true

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
void printWordHist(const std::vector<int> &wordLengths, int numStars = 200, char starChar = '*') {    
    // Validate inputs
    validateNumStars(numStars);
    validateWordLengths(wordLengths);
    validateStarChar(starChar);

    int maxWordLen = *std::max_element(wordLengths.begin(), wordLengths.end()); // Length of the longest word
    int maxNumberLen = std::to_string(maxWordLen).length(); // Number of digits in the max length
    std::vector<std::string> bars; // Vector to store the bars
    std::vector<int> barLengths; // Vector to store the lengths of the bars
    std::vector<std::string> linesOut(maxWordLen); // Vector to store the printed lines out

    #ifdef DEBUG
    std::cout << "Max word length: " << maxWordLen << std::endl;
    std::cout << "Number of stars: " << numStars << std::endl;
    std::cout << "Star character: " << starChar << std::endl;
    std::cout << "Max length of axes numbers: " << maxNumberLen<< std::endl;
    #endif

    // Fill bars vector with starChars
    for (int i = 1; i <= maxWordLen; i++) {
        int count = std::count(wordLengths.begin(), wordLengths.end(), i); // Count number of words of length i
        int numStarsToPrint = (int) (numStars * ((double) count / wordLengths.size())); // Number of stars to print
        barLengths.push_back(numStarsToPrint);
    }

    // Find the maximum bar length
    int maxBarLen = *std::max_element(barLengths.begin(), barLengths.end());

    const std::string leftAxis = ": "; // Axes string ": "
    const std::string rightAxis = "| "; // Right border "| "
    const int rightPadding = 2; // Right padding between bars and number of words

    #ifdef DEBUG
    std::cout << "Number of bars: " << barLengths.size() << std::endl;
    std::cout << "Max bar length: " << maxBarLen << std::endl;
    #endif 

    // Fill the bars vector with the bars
    for (int i = 0; i < maxWordLen; i++) {
        std::string bar = "";
        for (int j = 0; j < barLengths[i]; j++) {
            bar += starChar;
        }
        bars.push_back(bar);
    }

    // Build the lines out to print
    for (int i = 1; i <= maxWordLen; i++) {
        linesOut[i - 1] = addBlankPrefixToNumber(i, maxNumberLen) + leftAxis.c_str() + bars[i - 1];
        for (int j = 0; j < maxBarLen - barLengths[i - 1]; j++) {
            linesOut[i - 1] += " ";
        }
        for (int j = 0; j < rightPadding; j++) {
            linesOut[i - 1] += " ";
        }
        linesOut[i - 1] += rightAxis + std::to_string(std::count(wordLengths.begin(), wordLengths.end(), i));
    }

    // Print the histogram
    for (std::string line : linesOut) {
        std::cout << line << std::endl;
    }
}