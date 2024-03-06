#ifndef __EASY_UTILS_HPP__
#define __EASY_UTILS_HPP__

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

    // 4ª Função ------------------------------------
    struct print_params {
        std::string sep{" "};
        std::string end{"\n"};
    };

    template<typename Container>
    inline void print(const Container& cont, const print_params& p = print_params()){

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
    inline void print(const Container& cont, std::ostream& out, const print_params& p = print_params()){

        for(int i = 0; i < cont.size(); i++){

            if(i == cont.size() - 1){
                out << cont[i] << p.end;
            } 
            else {
                out << cont[i] << p.sep;
            }
        }
    }

    // 5ª Função
    template<typename Container, typename Item>
    int find_index(const Container& cont, const Item& item, int start = 0){

        for(int i = start; i < cont.size(); i++){
            if(cont[i] == item) return i;
        }
        return -1;
    }

} // <- namespace
#endif