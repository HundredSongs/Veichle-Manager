// FIRST HEADER-ONLY FILE


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

}

#endif