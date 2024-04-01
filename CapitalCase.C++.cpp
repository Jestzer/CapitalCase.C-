#include <iostream>
#include <string>
#include <cctype>

void fixCapitalization(std::string& str) {
    bool newWord = true;

    // Loop through each character in the string.
    for (size_t i = 0; i < str.length(); i++) {
        // If the current character is a space, the next character is the start of a new word.
        if (str[i] == ' ') {
            newWord = true;
        }
        else if (newWord) { // Capitalize the first letter of the word.
            str[i] = toupper(str[i]);
            newWord = false;
        }
        else { // Make sure the rest of the word is lowercase.
            str[i] = tolower(str[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    // Check if there are less than 3 arguments. If so, you did something wrong.
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " -c \"text to change capitalization\"" << std::endl;
        return 1;
    }

    // Look for the "-c" option in the arguments.
    for (int i = 1; i < argc - 1; i++) {
        if (std::string(argv[i]) == "-c") {
            // Capitalize the next word/argument in the output.
            std::string text = argv[i + 1];
            fixCapitalization(text);
            std::cout << text << std::endl;
            return 0;
        }
    }

    std::cout << "The argument '-c' was not found. Usage: " << argv[0] << " -c \"text to change capitalization\"" << std::endl;
    return 1;
}