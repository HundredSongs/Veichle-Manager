#include <iostream>
#include <string>

#include "easy_text.hpp"
using namespace easy_text;

int main() {
    std::string ast(10, '*');
    std::string arrow_f("==> ");
    std::string arrow_b(" <==");
//    std::cout << ast + "IS_WHITE_SPACE" + ast << "\n\n";

//    char ch;
//    std::cout << "Insira um caractere: ";
//    std::cin >> ch;
    
//    if (is_white_space(ch)) {
//        std::cout << "E um caracter de espacamento";
//    }
//    else {
//        std::cout << "Nao e um caracter de espacamento";
//    }


    std::cout << ast + "IS_DIGIT" + ast << "\n\n";

    char ch;
    std::cout << "Insira um caractere: ";
    std::cin >> ch;
    
    if (is_digit(ch) == true) {
        std::cout << arrow_f + "True" + arrow_b << std::endl;
    }
    else {
        std::cout << arrow_f << "False" << arrow_b << std::endl;
    }

    std::cout << ast + "TO_LOWER" + ast << "\n";

    std::cout << "Insira um caractere: ";
    std::cin >> ch;

    std::cout << arrow_f << to_lower(ch) << arrow_b << std::endl;


    std::cout << ast + "TO_UPPER" + ast << "\n";

    std::cout << "Insira um caractere: ";
    std::cin >> ch;

    std::cout << arrow_f << to_upper(ch) << arrow_b << std::endl;


    //std::cout << ast + "TRIM_LEFT" + ast << "\n";
    //std::string str;
    //std::cout << "Insira uma palavra: ";
    //std::getline(std::cin, str);

    //std::cout << arrow_f << trim_left(str) << arrow_b << std::endl;


    //std::cout << ast + "REVERSE" + ast << "\n";

    //std::cout << "Insira uma palavra: ";
    //std::getline(std::cin, str);

    //std::cout << arrow_f << reverse(str) << arrow_b << std::endl;


    //std::cout << ast + "REPLACE" + ast << "\n";
    //std::string str;

    //std::cout << "Insira uma palavra: ";
    //std::getline(std::cin, str);

    //std::cout << arrow_f << replace(str) << arrow_b << std::endl;


} //<= Main
