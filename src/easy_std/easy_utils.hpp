#ifndef __EASY_UTILS_HPP__
#define __EASY_UTILS_HPP__

namespace easy_std {

    // 1ª Função -----------------------------------------------
    inline std::string input(const std::string& msg) {
        std::cout << msg;
        std::string str;
        std::getline(std::cin, str);
        return str;
    }

    // 2ª Função -----------------------------------------------
    template <typename T>
    inline std::string to_string(const T& t) {
        std::ostringstream ss;
        ss << t;
        return ss.str();
    }

    template <typename T>
    inline std::string to_string(const std::vector<T>& vec) {

        std::ostringstream ss;
        ss << "{ ";
        for (int i = 0; i < vec.size();i += 1) {
            ss << vec[i];
            if(i != vec.size() - 1){
                ss << ", ";
            }
        }
        ss << " }";
        return ss.str();
    }

    template <typename T>
    inline std::string to_string(const std::list<T>& lis) {
        
        std::ostringstream ss;
        auto it = lis.begin();

        ss << "{ ";
        for (int i = 0; i < lis.size(); i++, it++) {
            ss << *it;
            if(i != lis.size() - 1){
                ss << ", ";
            }
        }
        ss << " }";

        return ss.str();
    }

    template <typename T, typename N>
    inline std::string to_string(const std::map<T, N>& mapa) {
        
        std::ostringstream ss;
        auto it = mapa.begin();

        ss << "{ ";

        if(mapa.size() > 0){

            ss << (*it).first << " => " << (*it).second;
            for (++it; it != mapa.end(); ++it) {
                ss << ", " << (*it).first << " => " << (*it).second;
            }
        }

        ss << " }";
        
        return ss.str();
    }

    template <typename T, typename N>
    inline std::string to_string(const std::unordered_map<T, N>& mapa) {
        
        return to_string(std::map( mapa.begin(), mapa.end() ) );
    }

    // 3ª Função --------------------------------------------------------------------
    template <typename T>
    T convert(const std::string& str){
        std::istringstream ss(str);
        T item;
        if(!(ss >> item)){
            throw std::invalid_argument("ERROR: Failed to Convert " + str);
        }
        return item;
    }

    // 4ª Função ---------------------- ----------------------------------------------
    struct print_params {
        std::string sep{" "};
        std::string end{"\n"};
    }; 

    template<typename Container>
    inline void print(const Container& cont, const print_params& p = print_params()){
        
        if(cont.size() > 0){

            auto iter = cont.begin();
            std::cout << *iter;
            for(++iter; iter != cont.end(); ++iter){
                std::cout << p.sep << *iter;
            }
        }
        std::cout << p.end;
    }

    template<typename Container>
    inline void print(const Container& cont, std::ostream& out, const print_params& p = print_params()){

        if(cont.size() > 0){

            auto iter = cont.begin();
            out << *iter;
            for(++iter; iter != cont.end(); ++iter){
                out << p.sep << *iter;
            }
        }
        out << p.end;
    }

    // 5ª Função ----------------------------------------------------------------
    template<typename Container, typename Item>
    int find_index(const Container& cont, const Item& item, int start = 0){

        for(int i = start; i < cont.size(); i++){
            if(cont[i] == item) return i;
        }
        return -1;
    }


} // <- namespace
#endif