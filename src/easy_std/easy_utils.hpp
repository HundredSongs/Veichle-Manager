/**
 * Módulo com utilitários gerais que integram a biblioteca EASY_STD.
 * 
 * Desenvolvido por João Roque e Licínio Feliciano
*/




// ARQUIVO CABEÇALHO => HEADER FILE
// CPP => C PreProcessor : ferramenta que processa intruções começadas
//        com #, como, por exemplo, #include, #define, #ifdef, #ifndef, etc...

#ifndef __EASY_UTILS_HPP__
#define __EASY_UTILS_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>

namespace easy_std {
    /**
    * Exibe uma mensagem a solicitar a introdução de uma linha de texto
    * através da entrada padrão. Envia a string introduzida para a
    * saída padrão.
    */
    inline std::string input(const std::string& msg) {
        std::cout << msg;
        std::string str;
        std::getline(std::cin, str);
        return str;
    }

    /**
     * Converte um objecto do tipo parametrizado T numa string.
     * Utiliza as facilidades definidas em sstream (#include <sstream>).
    */
    template<typename T>
    std::string to_string(const T& t) {
        std::ostringstream ss;
        ss << t;
        return ss.str();
    }

    /**
     * Especialização de to_string para 'std::vector'.
     * A string a devolver possui o formato "{ elem1, elem2, ...}", onde
     * cada elem é um elemento do vector.
    */
    template<typename T>
    std::string to_string(const std::vector<T>& vec) {
        std::ostringstream ss;
        ss << "{ ";
        if (vec.size() > 0) {
            ss << vec[0];
        }
        for (auto i = 1; i < vec.size(); i++) {
            ss << ", " << vec[i];
        }
        ss << " }";
        return ss.str();
    }

    /**
     * Especialização de to_string para 'std::list'. A string devolvida possui
     * o mesmo formato que a devolvida pelo template para vectores.
    */
    template<typename T>
    std::string to_string(const std::list<T>& lis) {
        std::ostringstream ss;
        ss << "{ ";
        if (lis.size() > 0) {
            auto iter = begin(lis);
            ss << *iter;
            for (++iter; iter != end(lis); ++iter) {
                ss << ", " << *iter;
            }
        }
        ss << " }";
        return ss.str();
    }

    // template<typename T>
    // std::string to_string(cons std::list<T>& lis) {
    //     return to_string(std::vector<T>(lis.begin(), lis.end()));
    // }

    /**
     * Especialização de to_string para std::map. A string devolvida possui 
     * o formato "{chave1 => valor1, chave2 => valor2, ...}"
    */

    template<typename T, typename V>
    std::string to_string(const std::map<T, V>& mp) {
        std::ostringstream ss;
        ss << "{ ";
        if (mp.size() > 0) {
            auto iter = begin(mp);
            ss << (*iter).first << " => " << (*iter).second;
            for (++iter; iter != end(mp); ++iter) {
            ss << ", " << (*iter).first << " => " << (*iter).second;
        }
    }
        ss << " }";
        return ss.str();
    }

    /**
     * Especialização de to_string para 'std::unordered_map'. A string devolvida
     * possui o formato "{chave1 => valor1, chave2 => valor2, ...}".
    */
    template<typename T, typename V>
    std::string to_string(const std::unordered_map<T, V>& mp) {
        return to_string(std::map(mp.begin(), mp.end()));
    }

    /**
     * Converte uma string para um objecto do tipo parametrizado T. 
     * É lançada uma excepção do tipo std::invalid_argument em caso de falha
     * na conversão.
     * Utilizar as Facilidades definidas em sstream (#include <sstream>).
    */
    template<typename T>
    T convert(const std::string& str) {
        std::istringstream iss(str);
        T item;
        if (!(iss >> item)) {
            throw std::invalid_argument("Error: failed to convert " + str);
        }
        return item;
    }

    /**
     * Estructura de formatação da função 'easy_sd::print',
     * 'sep' é um delimitador utilizado para separar os elementos da 
     * colecção a ser exibida pela função 'easy_std::print'.
    */
    struct print_params {
        std::string sep{" "};
        std::string end{"\n"};
    };

    /**
     * Escreve em 'out' os elementos de uma colecção. Separa os elementos
     * com a string 'print_params::sep' e termina com 'print_params::end'.
    */

    print_params p = {.sep = "/", .end = "$$"};

    template<typename Container>
    void print(const Container& cont, std::ostream& out, const print_params& p = print_params()) {
        if (cont.size() > 0) {
            auto iter = begin(cont);
            out << *iter;
                for (++iter; iter != end(cont); ++iter) {
                    out << p.sep << *iter;
                }

        }
        out << p.end; 
    }

    /**
     * Escreve em 'std::cout' os elementos de uma colecção. Separa os elementos
     * com a string 'print_params::sep' e termina com 'print_params::end'
    */

    template<typename Container>
    void print(const Container& cont, const print_params& p = print_params()) {
        print(cont, std::cout, p);
    }

    template<typename T>
    void print(const std::initializer_list<T>& il, std::ostream& out, const print_params& p = print_params()) {
        print(std::vector<T>(il), out, p);
    }

    template<typename T>
    void print(const std::initializer_list<T>& ilist, const print_params& p = print_params()) {
        print(ilist, std::cout, p);
    }

    /**
     * Escreve em 'std::out' os elementos de uma colecção. Separa os elementos
     * com a string 'print_params::sep' e termina com 'print_params::end'.
    */

    template<typename T, typename V>
    void print(const std::map<T, V>& map, std::ostream& out, const print_params& p = print_params()) {
        if (map.size() > 0) {
            auto iter = begin(map);
            out << (*iter).first << " => " << (*iter).second;
            for (++iter; iter != end(map); ++iter) {
                out << p.sep << (*iter).first << " => " << (*iter).second;
            }
        }
        out << p.end;
    }

    /**
     * Dado uma sequência do tipo S (que deverá ser um 'container'),
     * contendo items do tipo T, procura por 'item' e devolve a sua posição,
     * caso esta exista, -1 caso contrario. Procura a partir da posição start.
    */
    template<typename Sequence, typename T>
    int find_index(const Sequence& s, T item, int start = 0) {
        auto start_it = begin(s) + start;
        auto it = std::find(start_it, end(s), item);
        return it != end(s) ? it - start_it : -1;
    }

    /**
     * Devolve true se o item está presente na colecção 's'.
    */
    template<typename Container, typename T>
    bool in(const Container& s, T item) {
        return std::find(begin(s), end(s), item) != end(s);
    }

    /**
     * Devolve true se o item está presente na lista de inicialização 'ilist'.
    */
    template<typename T>
    bool in(const std::initializer_list <T>& ilist, T item) {
        return std::find(begin(ilist), end(ilist), item) != end(ilist);
    }

    /**
    * Devolve true se o item está presente no mapa 'map'. 
    */
    template<typename Key, typename Value>
    bool in(const std::map<Key, Value>& map, const Key& (item)) {
        return map.find(item) != end(map);
    }

    /**
    * Devolve true se o item está presente no mapa 'map'. 
    */
    template<typename Key, typename Value>
    bool in(const std::unordered_map<Key, Value>& map, const Key& (item)) {
        return map.find(item) != end(map);
    }

}

#endif