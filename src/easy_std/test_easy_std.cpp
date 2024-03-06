/*

*/


#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>

#include "easy_utils.hpp"


std::string input(const std::string& msg) {
    std::cout << msg;
    std::string str;
    getline(std::cin, str);
    return str;
}


int main() {

    // 1ª Função
    std::cout << "\n***** INPUT *****\n";
    std::string name1 = input("Como se chama? ");
    std::cout << "Nome: " << name1 << std::endl;


    std::vector<int> vals {10, 72, -500};
    for (const auto& val : vals) {
        std::cout << val << std::endl;
    }

    // 4ª Função
    std::vector<int> vals{10, 50, 23};
    print(vals);
    print(vals, {.sep = "//"});
    print(vals, {.end = "$$"});
    print(vals, {.sep = "--" , .end = "FIM\n"});
    std::string s ("Alberto");
    print(s);
    print(s , {.sep = ""});
    //ofstream file("dados.txt");
    //print(vals, file, {.sep = ","}); 

    return 0;
}