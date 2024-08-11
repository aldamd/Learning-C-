#include <iostream>
#include <string>

const int SPACE = 32;
const int DIGITS[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
const int DIGITS_SIZE = sizeof(DIGITS)/sizeof(DIGITS[0]);

bool is_only_digits(std::string word) {
    //determines if an input word is made up of only ASCII digits
    char elem;
    bool only_digits = true;
    for (int i = 0; i < word.length(); i++) {
        if (only_digits) {
            elem = word[i];
            for (int j = 0; j < DIGITS_SIZE; j++) {
                if (elem == DIGITS[j])
                    break;
                if (j == DIGITS_SIZE - 1 && elem != DIGITS[j])
                    only_digits = false;
            }
        }
        else
            return only_digits;
    }

    return only_digits;
}

void replace_word(std::string& word) {
    //if the input word only contains ASCII digits, replace each digit with the character 'x'
    if (is_only_digits(word)) {
        for (int idx = 0; idx < word.length(); idx++) {
            word[idx] = 'x';
        }
    }
}

void censor(std::string input) {
    //iterates through a given string and censors words that are made up of only ASCII digits
    int str_size = input.length();
    int lbound = 0, rbound = 0;
    char elem;
    std::string word;
    for (int idx = 0; idx < str_size; idx++) {
        elem = input[idx];
        //if elem is a space or EOL
        if (elem == SPACE || idx == str_size - 1) {
            if (elem == SPACE)
                rbound = idx;
            else
                rbound = idx + 1;
            word = input.substr(lbound, rbound - lbound);
            replace_word(word);
            std::cout<<word<<" ";
            lbound = rbound + 1;
        }
    }
    std::cout<<std::endl;
}

int main() {
    std::string input;
    std::cout<<"Please enter a line of text: "<<std::endl;
    std::getline(std::cin, input);

    censor(input);

    return 0;
}
