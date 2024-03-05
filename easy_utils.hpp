#include <iostream>

std::string input(const std::string& msg = ""){
    
    std::string text;

    std::cout << msg;
    std::getline(std::cin, text);
    return text;
}