/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <fstream>

#include <docopt/docopt.h>

#include "easy_utils.hpp"

using std::literals::operator""s;
using namespace easy_std;

int main(int argc, char* argv[]) {

    // 1ª Função
    std::string ast(10, '*');
    /////////////////////////////////////////////////////////////////////////
    std::cout << "\n" << ast << " INPUT " << ast << "\n";
    std::string name1 = input("Como se chama? ");
    std::cout << "Nome: " << name1 << std::endl; 

    /////////////////////////////////////////////////////////////////////////
    std::cout << "\n" << ast << " NUM_TO_STRING " << ast << "\n";

    int valor1 = 1597;
    std::cout << "valor1: " << valor1 << " => " << "to_string(valor1) => " << to_string(valor1) << std::endl;

    double valor2 = 72.89;
    std::cout << "valor2: " << valor2 << " => " << "to_string(valor2) => " << to_string(valor2) << std::endl;
    
    /////////////////////////////////////////////////////////////////////////
    std::cout << "\n" << ast << " VECTOR_TO_STRING " << ast << "\n";

    std::vector<int> vals1 {10, 72, -500};
    for (const auto& val : vals1) {
        std::cout << val << std::endl;
    }

    // 4ª Função
    std::vector<int> vals{10, 50, 23};
    print(vals);
    print(vals, {.sep = "//"});
    print(vals, {.end = "$$"});
    print(vals, {.sep = "--" , .end = "FIM\n"});
    
    print("Alberto"s);
    print("Alberto"s , {.sep = ""});
    std::ofstream file("dados.txt");
    print(vals, file, {.sep = ","});

    // 5ª Função

    std::vector<int> vals{-5, 10, 31, 55, 10, 44};
    find_index(vals, 10);
    find_index(vals, 10, 2);
    find_index(vals, -10);
    find_index("Alberto"s, 'b');

    return 0;
}