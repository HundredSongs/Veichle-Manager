#include <iostream>
#include <string>

#include "easy_text.hpp"
using namespace easy_text;

int main() {
    std::string ast(10, '*');
    std::cout << ast + "IS_WHITE_SPACE" + ast << "\n\n";

    char ch;
    //std::cout << "Insira um caractere: ";
    //std::cin >> ch;
    //std::cout << is_white_space(ch);
    
    std::cout << ast + "IS_DIGIT" + ast << "\n\n";

    std::cout << "Insira um caractere: ";
    std::cin >> ch;
    
    if (is_digit(ch) == true) {
        std::cout << "True";
    }
    else {
        std::cout << "False";
    }


    std::cout << ast + "TO_LOWER" + ast << "\n\n";

    std::cout << "Insira um caractere: ";
    std::cin >> ch;

    std::cout << to_lower(ch);


    std::cout << ast + "TO_UPPER" + ast << "\n\n";

    std::cout << "Insira um caractere: ";
    std::cin >> ch;

    std::cout << to_upper(ch);


    std::cout << ast + "trim_left" + ast << "\n\n";
    std::string str;
    std::cout << "Insira uma palavra: ";
    std::cin >> str;

    std::cout << trim_left(str);


} //<= Main
