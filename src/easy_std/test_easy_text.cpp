#include <iostream>
#include <string>

#include "easy_text.hpp"

using namespace std;
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
    std::cout << ast + "TRIM_LEFT" + ast << "\n\n";

    std::string str;
    std::cout << "Insira uma palavra: ";
    getline(std::cin, str);

    std::cout << trim_left(str) << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "TRIM" + ast << "\n\n";

    std::string str2;
    std::cout << "Insira uma palavra: ";
    getline(std::cin, str2);

    std::cout << '>' << trim(str2) << '<' << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "REVERSE" + ast << "\n\n";
    std::string str3;
    std::cout << "Insira uma frase: ";
    getline(std::cin, str3);
    std::cout << reverse(str3) << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "REVERSED" + ast << "\n\n";
    std::string str4;
    std::cout << "Insira uma frase: ";
    getline(std::cin, str4);
    std::cout << reversed(str4) << "<" << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "REPLACE" + ast << "\n\n";

    std::cout << replace("ana avelar"s, 'a', 'A') <<  std::endl;                //"AnA AvelAr"
    std::cout << replace("ana avelar"s, 'a', 'A', 4) <<  std::endl;             //"ana AvelAr"
    std::cout << replace("ana avelar"s, 'a', 'A', 0, 2) <<  std::endl;          //"AnA avelar"
    std::cout << replace("ana avelar alves"s, 'a', 'A', 4, 9) <<  std::endl;    //"ana AvelAr alves"
    std::cout << replace("ana avelar"s, 'b', 'A') <<  std::endl;                //"ana avelar"


} //<= Main
