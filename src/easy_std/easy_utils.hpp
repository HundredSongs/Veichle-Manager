#include <iostream>
#include <string>

// 1ª Função ------------------------------------
std::string input(const std::string& msg = ""){
    
    std::string text;

    std::cout << msg;
    std::getline(std::cin, text);

    return text;
}

// 2ª Função ------------------------------------
template<typename T>
std::string to_string(const T& t){



}

// 4ª Função ------------------------------------
struct print_params {
    std::string sep{" "};
    std::string end{"\n"};
};

template<typename Container>
void print(const Container& cont, const print_params& p = print_params()){


    //auto size = sizeof(cont)/sizeof(Container);

    for(int i = 0; i < cont.size(); i++){

        if(i == cont.size() - 1){
            std::cout << cont[i] << p.end;
        } 
        else {
        std::cout << cont[i] << p.sep;
        }
    }
}


template<typename Container>
void print(const Container& cont, std::ostream& out, const print_params& p = print_params()){

    for(int i = 0; i < cont.size(); i++){

        if(i == cont.size() - 1){
            std::cout << cont[i] << print_params().end;
        } 
        else {
        std::cout << cont[i] << print_params().sep;
        }
    }
}