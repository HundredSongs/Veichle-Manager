/**
 * Módulo com utilitários gerais que integram a biblioteca EASY_STD.
 * 
 * Desenvolvido por João Roque e Licínio Feliciano
*/

#include <iostream>
#include <string>
#include <vector>

#ifndef __EASY_TEXT_HPP__
#define __EASY_TEXT_HPP__


namespace easy_std {

    /**
     * Devolve true se o caractere ch for um caractere de espaçamento, ou seja, 
     * se for um dos seguintes: ' ', '\n', '\t' ou '\r').
    */
    bool is_white_space(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
    }

    // Devolve true se todos os caractere da string str forem de espaçamento. 
    // Deve utilizar a versão para um caractere.
    // Exemplo:
    // is_white_space(" \n\t ") => true
    // is_white_space(" \n\t3 ") => false
    bool is_white_space(const std::string& str) { 
        for (char ch : str) {
            if (!(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')) {
                return false;
            }
        }
        return true;
    }

    /**
     * Devolve true se o caractere ch for um dígito decimal.
    */
    bool is_digit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    // Devolve true se todos os caractere da string str forem dígitos. 
    // Deve utilizar a versão para um caractere.
    bool is_digit(const std::string& str) {
        for (char ch : str) {
            if (!(ch >= '0' && ch <= '9')) {
                return false;
            }
        }
        return true;
    }

    /**
     * Converte uma letra maiúscula para minúscula; 
     * implemente a versão complementar to_upper.
    */
    char to_lower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + ('a' - 'A');
        }
    }

    char to_upper(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch - ('a' - 'A');
        }
    }

    /**
     * Converte uma letra maiúscula para minúscula; implemente a 
     * versão complementar to_upper. Esta função modifca a string recebida, 
     * mas também devolve-a para que possa ser utilizada em expressões 
     * do tipo string
    */
    // std::string& to_lower(std::string& str) {
    //     std::string convert;
    //     for (char& ch : str) {
    //         if (ch >= 'A' && ch <= 'Z') {
    //             ch += ('a' - 'A');
    //         }
    //             convert += ch;
    //     }
    //     return convert;
    // }


    /**
     * Apara a string str à esquerda e devolve-a; implemente a 
     * versão complementar trim_right. "Aparar" uma string à esquerda consiste 
     * em remover os caracteres de espaçamento à esquerda, que estão entre o 
     * início da string e o primeiro caractere que não é de espaçamento. 
     * Esta função modifca a string recebida, mas também devolve-a para 
     * que possa ser utilizada em expressões do tipo string. 
     * Se a string não possuir caracteres de espaçamento à esquerda, 
     * então é simplesmente devolvida.
    */
    // std::string& trim_left(std::string& str) {
        
    // }

    /**
     * Apara a string str à esquerda e à direita devolvendo essa string.
    */
    // std::string& trim(std::string& str) {

    // }

    /**
     * Inverte a string str e devolve-a. Tal como com as funções trim, 
     * a string str é modifcada mas também é devolvida. 
     * Desenvolva o algoritmo de raiz, sem recorrer a quaisquer funções 
     * de algorithm (como, por exemplo, std::reverse ...) ou de qualquer 
     * outra biblioteca.
    */
    // std::string& reverse(std::string& str) {

    // }

    /**
     * Devolve uma cópia invertida da string str com os caracteres 
     * por ordem inversa. Pode utilizar funções já feitas.
    */
    // string reversed(const string& str) {

    // }

    /**
     * Substitui todas as ocorrências do caractere ch1 pelo caractere ch2; 
     * devolve a string str. Começa na posição dada por start e substitui 
     * até à posição dada por end. O valor -1 indica que end deve ser a 
     * posição do último caractere.
     * 
     * Exemplos:
     *    replace("ana avelar", 'a', 'A') => "AnA AvelAr"
     *    replace("ana avelar", 'a', 'A', 4) => "ana AvelAr"
     *    replace("ana avelar", 'a', 'A', 0, 2) => "AnA avelar"
     *    replace("ana avelar alves", 'a', 'A', 4, 9) => "ana AvelAr alves"
     *    replace("ana avelar", 'b', 'A') => "ana avelar"
    */
    // std::string& replace(std::string& str, char ch1, char ch2, 
    //                      int start = 0, int end = -1) {

    // }

    /**
     * Substitui em str todas as ocorrências da substring substr1 por substr2; 
     * devolve a string str. Em baixo não indicamos exemplos com os parâmetros 
     * start e end porque o comportamento da função pode ser inferido a partir 
     * da versão anterior.
    */

    /**
     * EXTRA: implemente o algoritmo de raiz, sem recorrer a quaisquer funções 
     * que implementem total ou parcialmente esta funcionalidade ou 
     * funcionalidade similar (como std::string::replace, std::replace). 
     * Pode, no entanto, utilizar std::find, std::string::find e as 
     * funções membro de std::string que permitem modifcar a string, 
     * como std::string::insert, std::string::erase e std::string::clear.
     *
     * Exemplos:
     *    replace("ana mariana", "ana", "ANA") => "ANA mariANA"
     *    replace("ana mariana", "ana", "anabela") => "anabela marianabela"
     *    replace("diana mariana", "ana", "") => "di mari"
    */
    // std::string& replace(std::string& str, const std::string& substr1, 
    //                      const std::string& substr2, int start = 0, 
    //                      int end = -1) {

    // }

    /**
     * "Parte" uma string em pedaços delimitados por delim. 
     * Dada a string str com "ABC DEF GHI", e delim igual a " " , 
     * a função split devolve um vector com {"ABC", "DEF", "GHI"}.
     *
     * Outros exemplos:
     *    split("ABC.DEF.GHI", ".") => {"ABC", "DEF", "GHI"}
     *    split("ABC.DEF.GHI", "+") => {"ABC.DEF.GHI"}
     *    split("ABC.DEF...GHI", ".") => {"ABC", "DEF", "", "", "GHI"}
     *    split(".ABC.DEF.GHI.", ".") => {"", "ABC", "DEF", "GHI", ""}
     *    split("ABC--DEF--GHI", "--") => {"ABC", "DEF", "GHI"}
     *    split("-ABC---DEF--GHI-", "--") => {"-ABC", "-DEF", "GHI-"}
     *    split("ABCDEF", "") => {"A", "B", "C", "D", "E", "F"}
    */
    // std::vector<std::string> split(const std::string& str, 
    //                                const std::string& delim) {

    // }

    /**
     * O oposto de split. "Une" as várias strings no vector parts com o 
     * delimitador delim e junta-as todas numa só string. Dado o vector 
     * parts com {"ABC", "DEF", "GHI"} e delim igual a "+" , a 
     * função join devolve a string "ABC+DEF+GHI".
     *
     * Outros exemplos:
     *    NOTA: nos exemplos seguintes, utilizamos a notação 
     *          {"ABC", "DEF", etc.} como notação abreviada para 
     *          vector<string>{"ABC", "DEF", etc.}
     * 
     *    join({"ABC", "DEF", "GHI"}, "+") => "ABC+DEF+GHI"
     *    join({"ABC"}, ".") => "ABC"
     *    join({"ABC", "DEF"}, ".") => "ABC.DEF"
     *    join(split("ABC.DEF.GHI", "."), "+")) => "ABC+DEF+GHI"
    */
    // std::string join(const std::vector<std::string>& parts, 
    //                   const std::string& delim) {
        
    // }

} //<= namespace

#endif