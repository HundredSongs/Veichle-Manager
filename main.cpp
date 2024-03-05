#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>

#include "easy_utils.hpp"

int main(){

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
}