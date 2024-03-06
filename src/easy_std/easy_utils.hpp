<<<<<<< HEAD
// FIRST HEADER-ONLY FILE
=======
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
>>>>>>> refs/remotes/origin/main


#ifndef __EASY_UTILS_HPP__
#define __EASY_UTILS_HPP__


<<<<<<< HEAD
namespace easy_std {

    // 1ª Função
    inline std::string input(const std::string& msg) {
        std::cout << msg;
        std::string str;
        std::getline(std::cin, str);
        return str;
    }

    // 2ª Função
    template <typename T>
    inline std::string to_string(const T& t) {
        std::ostringstream ss;
        ss << t;
        return ss.str();
    }
    // 2ª Função OVERLOADING
    template <typename T>
    inline std::string to_string(const std::vector<T>& vec) {
        std::stringstream ss;
            for (int i = 0; i < vec.size();i += 1) {
                ss << vec[i];
            }
        return ss.str();
    }

}

#endif
=======
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
            std::cout << cont[i] << p.end;
        } 
        else {
            std::cout << cont[i] << p.sep;
        }
    }
}
>>>>>>> refs/remotes/origin/main
