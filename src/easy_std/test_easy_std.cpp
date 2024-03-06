/*

*/


# include <iostream>
# include <vector>
# include <string>
# include <sstream>

#include <docopt/docopt.h>

# include "easy_utils.hpp"

using namespace easy_std;


int main(int argc, char* argv[]) {

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







    return 0;
}
