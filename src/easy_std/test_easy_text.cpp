#include <iostream>

#include "easy_text.hpp"

using namespace std;
using namespace easy_std;

int main() {
    /////////////////////////////////////////////////
    std::string ast(10, '*');
    std::cout << ast + "IS_WHITE_SPACE" + ast << "\n\n";

    std::string text;
    std::cout << "Insira um caractere: ";
    getline(std::cin, text);

    if (is_white_space(text) == true) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }
    /////////////////////////////////////////////////
    std::cout << ast + "IS_DIGIT" + ast << "\n\n";

    std::cout << "Insira um caractere alfanumérico: ";
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

    std::cout << ">" << trim_left(str) << std::endl;

    /////////////////////////////////////////////////
    std::cout << ast + "TRIM_RIGHT" + ast << "\n\n";

    std::string str2;
    std::cout << "Insira uma palavra: ";
    getline(std::cin, str2);

    std::cout << trim_right(str2) << "<" << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "TRIM" + ast << "\n\n";

    std::string str3;
    std::cout << "Insira uma palavra: ";
    getline(std::cin, str3);

    std::cout << '>' << trim(str3) << '<' << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "REVERSE" + ast << "\n\n";
    std::string str4;
    std::cout << "Insira uma frase: ";
    getline(std::cin, str4);
    std::cout << reverse(str4) << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "REVERSED" + ast << "\n\n";
    std::string str5 = "test";
    std::cout << "Insira uma frase: ";
    getline(std::cin, str5);
    std::cout << reversed(str5) << "<" << std::endl;

    ///////////////////////////////////////////////////
    std::cout << ast + "REPLACE" + ast << "\n\n";

    std::string text17 = "ana avelar";
    std::string text17b = "ana avelar alves";

    std::cout << replace(text17, 'a', 'A') << std::endl;
    text17 = "ana avelar";               
    //"AnA AvelAr"
    std::cout << replace(text17, 'a', 'A', 4) <<  std::endl;
    text17 = "ana avelar";             
    //"ana AvelAr"
    std::cout << replace(text17, 'a', 'A', 0, 2) <<  std::endl;
    text17 = "ana avelar";         
    //"AnA avelar"
    std::cout << replace(text17b, 'a', 'A', 4, 9) <<  std::endl; 
    //"ana AvelAr alves"
    std::cout << replace(text17, 'b', 'A') <<  std::endl;                
    //"ana avelar"

    ///////////////////////////////////////////////////
    std::cout << ast + "REPLACE STR" + ast << "\n\n";

    std::string text18 = "ana mariana";
    std::string text18b = "diana mariana";

    std::cout << replace(text18, "ana", "ANA") << std::endl;            //"ANA mariANA"
    text18 = "ana mariana";
    std::cout << replace(text18, "ana", "anabela") << std::endl;        //"anabela marianabela"
    std::cout << replace(text18b, "ana", "") << std::endl;              //"di mari"


    ///////////////////////////////////////////////////
    std::cout << ast + "SPLIT" + ast << "\n\n";


    std::string text19 = "ABC.DEF.GHI";
    std::vector<std::string> vec19 = split(text19, ".");   //{"ABC", "DEF", "GHI"}
    for(int i = 0; i < vec19.size(); i++){
        std::cout << vec19[i] << " ";
    }
    std::cout << "\n";

    text19 = "ABC.DEF.GHI";
    vec19 = split(text19, "+");   //{"ABC.DEF.GHI"}
    for(int i = 0; i < vec19.size(); i++){
        std::cout << vec19[i] << " ";
    }
    std::cout << "\n";

    text19 = "ABC.DEF...GHI";
    vec19 = split(text19, ".");   //{"ABC", "DEF", "", "", "GHI"}
     for(int i = 0; i < vec19.size(); i++){
        std::cout << vec19[i] << " ";
    }
    std::cout << "\n";

    text19 = ".ABC.DEF.GHI.";
    vec19 = split(text19, ".");   //{"", "ABC", "DEF", "GHI", ""}
     for(int i = 0; i < vec19.size(); i++){
        std::cout << vec19[i] << " ";
    }
    std::cout << "\n";

    text19 = "ABC--DEF--GHI";
    vec19 = split(text19, "--");   //{"ABC", "DEF", "GHI"}
     for(int i = 0; i < vec19.size(); i++){
        std::cout << vec19[i] << " ";
    }
    std::cout << "\n";

    text19 = "-ABC---DEF--GHI-";
    vec19 = split(text19, "--");   //{"-ABC", "-DEF", "GHI-"}
     for(int i = 0; i < vec19.size(); i++){
        std::cout << vec19[i] << " ";
    }
    std::cout << "\n";

    text19 = "ABCDEF";
    vec19 = split(text19, "");   //{"A", "B", "C", "D", "E", "F"}
     for(int i = 0; i < vec19.size(); i++){
        std::cout << vec19[i] << " ";
    }
    std::cout << "\n";


    ///////////////////////////////////////////////////
    std::cout << ast + "JOIN" + ast << "\n\n";

    std::cout << join({"ABC", "DEF", "GHI"}, "+") << std::endl;        //"ABC+DEF+GHI"
    std::cout << join({"ABC"}, ".") << std::endl;        //"ABC"
    std::cout << join({"ABC", "DEF"}, ".") << std::endl;        //"ABC.DEF"
    std::cout << join(split("ABC.DEF.GHI", "."), "+") << std::endl;        //"ABC+DEF+GHI"

} //<= Main
