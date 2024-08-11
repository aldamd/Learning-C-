#include <iostream>
#include <string>

bool isPalindrome(std::string str) {
    //determines if the input string is a palindrome, returns true if so
    int str_len = str.length();
    int xdi = str_len - 1;
    char cur_char;
    std::string reverse_str = str;
    for (int idx = 0; idx < str_len/2; idx++) {
        cur_char = reverse_str[idx];
        reverse_str[idx] = reverse_str[xdi];
        reverse_str[xdi] = cur_char;
        xdi--;
    }

    if (reverse_str == str) {
        std::cout<<str<<" is a palindrome"<<std::endl;
        return true;
    }
    else {
        std::cout<<str<<" is not a palindrome"<<std::endl;
        return false;
    }
}

int main() {
    std::string input_word;
    std::cout<<"Please input a word: "; std::cin>>input_word;

    bool is_palindrome = isPalindrome(input_word);

    return 0;
}
