#include <iostream>
#include <string>

#include "easy_text.hpp"
using namespace easy_text;

int main() {
    /////////////////////////////////////////////////
    std::string ast(10, '*');
    std::cout << ast + "IS_WHITE_SPACE" + ast << "\n\n";

    std::string text;
    
    std::cout << "Insira um caractere: ";
    getline(std::cin, text);
    std::cout << is_white_space(text) << std::endl;
    
    /////////////////////////////////////////////////
    std::cout << ast + "IS_DIGIT" + ast << "\n\n";


    std::cout << "Insira um caractere: ";
    getline(std::cin, text);
    
    if (is_digit(text) == true) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    /////////////////////////////////////////////////
    std::cout << ast + "TO_LOWER" + ast << "\n\n";

    std::cout << "Insira um caractere: ";
    getline(std::cin, text);

    std::cout << to_lower(text) << std::endl;

    /////////////////////////////////////////////////
    std::cout << ast + "TO_UPPER" + ast << "\n\n";

    std::cout << "Insira um caractere: ";
    getline(std::cin, text);

    std::cout << to_upper(text) << std::endl;

    /////////////////////////////////////////////////
    std::cout << ast + "trim_left" + ast << "\n\n";

    std::string str;
    std::cout << "Insira uma palavra: ";
    getline(std::cin, str);

    std::cout << trim_left(str) << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "trim" + ast << "\n\n";

    std::string str2;
    std::cout << "Insira uma palavra: ";
    getline(std::cin, str2);

    std::cout << trim(str2) << "//" << std::endl;


} //<= Main
