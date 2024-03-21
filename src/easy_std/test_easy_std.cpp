#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include <docopt/docopt.h>

#include "easy_utils.hpp"

using namespace std;
using namespace easy_std;

int main() {
     cout << "\n*************** INPUT ***************\n\n";
     string name1 = input("Como se chama? ");
     cout << "name1 => " << name1 << endl;

     cout << "\n*************** TO_STRING ***************\n\n";
     int valor1 = 1597;
     cout << "valor1 " << valor1 << " => " << "to_string(valor1) " 
          << to_string(valor1) << endl;

     double valor2 = 72.89;
     cout << "valor2 " << valor2 << " => " << "to_string(valor2) " 
          << to_string(valor2) << endl;


     string valor3 = "TESTE";
     cout << "valor3 " << valor3 << " => " << "to_string(valor3) " 
          << to_string(valor3) << endl;

     cout << "\nVECTORES\n";

     vector<int> vec1A{10, 20, 30};
     cout << "vec1A: vector<int>{ 10, 20, 30 } | to_string(vec1A)  => " 
          << to_string(vec1A) << endl;

     vector<int> vec1B{10};
     cout << "vec1B: vector<int>{ 10 } | to_string(vec1B)  => " 
          << to_string(vec1B) << endl;

     vector<int> vec1C{};
     cout << "vec1C: vector<int>{  } | to_string(vec1C)  => " 
          << to_string(vec1C) << endl;

     vector<double> vec2{7.14};
     cout << "vec2: vector<double>{ 7.14 } | to_string(vec2)  => " 
          << to_string(vec2) << endl;

     vector<string> vec3{"abc", "def", "ghi"};
     cout << "vec3: vector<string>{ abc, def, ghi } | to_string(vec3)  => " 
          << to_string(vec3) << endl;


     cout << "\nLISTAS\n";

     list<int> lista1{10, 20, 30};
     cout << "lista1: list<int>{10, 20, 30} | to_string(lista1) => " 
          << to_string(lista1) << endl;

     cout << "\nMAPAS\n";

     map<string, int> idades1{
          {"Alberto", 31},
          {"Armando", 19},
          {"Arnaldo", 44}
     };
     cout << "idades1:map<string, int>{{Alberto, 31}, ...} =>\n    "
          << to_string(idades1) << endl;

     unordered_map<string, int> idades2{
          {"Alberto", 31},
          {"Armando", 19},
          {"Arnaldo", 44}
     };
     cout << "idades2:map<string, int>{{Alberto, 31}, ...} =>\n    "
          << to_string(idades2) << endl;

     cout << "\n*************** CONVERT ***************\n\n";

     auto x = convert<int>("289");
     cout << R"(convert<int>("289") => )" << x << endl;

     auto y = convert<double>("2.89");
     cout << R"(convert<double>("2.89") => )" << x << endl;

     try {
          convert<int>("armando");
     }
     catch (invalid_argument& ex) {
          cout << "Excepção em convert, tal como esperado => " << ex.what() << endl;
     }

     // auto age = convert<int>(input("How old are you? "));
     // cout << "You are " << age << " years old." << endl;

     cout << "\n*************** PRINT ***************\n\n";
     vector<double> vec5{10, 2.5, 12, -300. -2.78, 0, 450};
     cout << "prints(vec5))\n    ";
     print(vec5);

     cout << "prints(vec5, {.sep = \"/\"})\n    ";
     print(vec5, {.sep = "/"});

     cout << "prints(vec5, {.end = \"$\"})\n    ";
     print(vec5, {.end = "$\n"});

     // ofstream file("dados.txt");
     // print(vec5, file, {.sep = ","});

     print({"alberto", "armando", "arnaldo"}, {.sep = ",", .end = "<=\n"});


     cout << "\n*************** FIND ***************\n\n";
     vector<int> vals{-5, 10, 31, 55, 10, 44};
     cout << "vals: "; print(vals);
     cout << "    find_index(vals, 10)    => " << find_index(vals, 10) << endl;
     cout << "    find_index(vals, 10, 2) => " << find_index(vals, 10, 2) << endl;
     cout << "    find_index(vals, -10)   => " << find_index(vals, -10) << endl;
     cout << endl;

     cout << R"(find_index(Alberto"s, 'b') => )" 
          << find_index("Alberto"s, 'b') << endl;


     cout << "\n*************** IN ***************\n\n" << std::boolalpha;

     cout << "vals: "; print(vals);
     cout << "    in(vals, 10)    => " << in(vals, 10) << endl;
     cout << "    in(vals, 55) => " << in(vals, 55) << endl;
     cout << "    in(vals, -10)   => " << in(vals, -10) << endl;
     cout << endl;

     cout << R"(in(Alberto"s, 'b') => )" << in("Alberto"s, 'b') << endl;
     cout << R"(in{}"ana", "bruno", "ze"}, "bruno") =>)" 
          << in({"ana", "bruno", "ze"}, "bruno") << endl;
     cout << endl;

     map<string, int> portos = {{"http"s, 80}, {"ftp"s, 21}, {"telnet"s, 25}};
     cout << "portos: "; print(portos);
     cout << R"(    in(portos, "ftp"s)  => )" << in(portos, "ftp"s) << endl;
     cout << R"(    in(portos, "smtp"s) => )" << in(portos, "smtp"s) << endl;

     cout << "\n***************************************\n";
     cout << "FIM DOS TESTES DO MÓDULO EASY_UTILS";
     cout << "\n***************************************\n";
}
