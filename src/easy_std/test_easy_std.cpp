/**
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

#include <sstream>
#include <fstream>

#include <stdexcept>

#include <docopt/docopt.h>

#include "easy_utils.hpp"

using std::literals::operator""s;
using namespace easy_std;

int main(int argc, char* argv[]) {

    // 1ª Função --------------------------------------------------------
    std::string ast(10, '*');
    /////////////////////////////////////////////////////////////////////////
    std::cout << "\n" << ast << " INPUT " << ast << "\n";
    std::string name1 = input("Como se chama? ");
    std::cout << "Nome: " << name1 << std::endl; 


    // 2ª Função - to_string~--------------------------------------------
    std::cout << "\n" << ast << " TO_STRING " << ast << "\n";

    int valor1 = 1597;
    std::cout << "valor1: " << valor1 << " => " << "to_string(valor1) => " << to_string(valor1) << std::endl;

    double valor2 = 72.89;
    std::cout << "valor2: " << valor2 << " => " << "to_string(valor2) => " << to_string(valor2) << std::endl;
    
    // Vector to_string
    //std::cout << "\n" << ast << " VECTOR_TO_STRING " << ast << "\n";

    std::vector<int> vals1 {10, 72, -500};
    for (const auto& val : vals1) {
        std::cout << val << std::endl;
    }
    // Listas to_string
    //std::cout << "\n" << ast << " LIST_TO_STRING " << ast << "\n";

    std::list<int> lis {10, 20, 30};
    std::cout << to_string(lis) << std::endl;

    // Map to_string
    //std::cout << "\n" << ast << " MAP_TO_STRING " << ast << "\n";

    std::map<std::string, int> idades { {"Alberto", 31}, {"Arnaldo", 40}, {"Armando", 60} };
    std::cout << to_string(idades) << std::endl;

    std::unordered_map<std::string, int> idades2 { {"Alberto", 31}, {"Arnaldo", 40}, {"Armando", 60} };
    std::cout << to_string(idades2) << std::endl;


    // 3ª Função --------------------------------------------------------
    std::cout << "\n" << ast << " CONVERT " << ast << "\n";

    auto x = convert<int>("289");
    std::cout << R"(convert<int>("289") => )" << x << std::endl;

    auto y = convert<double>("2.89");
    std::cout << R"(convert<double>("2.89") => )" << y << std::endl;

    try {
        convert<int>("armando");
    }
    catch (std::invalid_argument& ex){
        std::cout << "invalid_argument, tal como esperado " << ex.what() << std::endl;
    }

    auto age = convert<int>(input("How old are you? "));
    std::cout << "You are " << age << " year old." << std::endl;


    // 4ª Função ------------------------------------------------
    std::cout << "\n" << ast << " PRINT " << ast << "\n";

    std::vector<double> vec5{ 10, 2.5, 12,-300, -2.78, 0, 450 };
    std::cout << R"(print(vec5))" << std::endl;
    print(vec5);

    std::cout << R"(print(vec5, {.sep= "^^"}))" << std::endl;
    print(vec5, {.sep="^^"});

    std::cout << R"(print(vec5, {.end= "$\n"}))" << std::endl;
    print(vec5, {.end="&\n"});

    std::vector<int> vals{10, 50, 23};
    print(vals);
    print(vals, {.sep = "//"});
    print(vals, {.end = "$$"});
    print(vals, {.sep = "--" , .end = "FIM\n"});
    
    print("Alberto"s);
    print("Alberto"s , {.sep = ""});

    //std::ofstream file("dados.txt");
    //print(vals, file, {.sep = ","});

    print({"Armando", "Alberto", "Arnaldo"}, {.sep = ".", .end = "<=\n"});


    // 5ª Função -----------------------------------------------
    std::cout << "\n" << ast << " FIND_INDEX " << ast << "\n";
    std::vector<int> vals2{-5, 10, 31, 55, 10, 44};
    std::cout << find_index(vals2, 10) << "\n";
    std::cout << find_index(vals2, 10, 2) << "\n";
    std::cout << find_index(vals2, -10) << "\n";
    std::cout << find_index("Alberto"s, 'b') << "\n";

    std::cout << "\n" << ast << "***************" << ast << std::endl;
    std::cout << "FIM DOS TESTES DO MODULO EASY_UTILS" << "\n" ;
    std::cout << "\n" << ast << "***************" << ast << "\n" ;

    return 0;
}