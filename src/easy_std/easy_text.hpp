/**
 * Módulo com utilitários gerais que integram a biblioteca EASY_TEXT.
 * 
 * Desenvolvido por João Roque e Licínio Feliciano
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#ifndef __EASY_TEXT_HPP__
#define __EASY_TEXT_HPP__


namespace easy_text {


    /**
     * IS_WHITE_SPACE (char)
     * Devolve true se o caractere ch for um caractere de espaçamento, ou seja, 
     * se for um dos seguintes: ' ', '\n', '\t' ou '\r').
    */
    bool is_white_space(char ch){
        return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
    }


    /**
     * IS_WHITE_SPACE (string)
     * Devolve true se todos os caractere da string str forem de espaçamento. 
     * Deve utilizar a versão para um caractere.
    */
    bool is_white_space(const std::string& str){ 
        for(const char& ch : str){
            if(!is_white_space(ch)) return false;
        }
        return true;
    }
    

    /**
     * IS_DIGIT (char)
     * Devolve true se o caractere ch for um dígito decimal.
    */
    bool is_digit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    /**
     * IS_DIGIT (string)
     * Devolve true se todos os caractere da string str forem dígitos. 
     * Deve utilizar a versão para um caractere.
    */
    bool is_digit(const std::string& str){
        for(const char& ch : str){
            if(!is_digit(ch)) return false;
        }
        return true;
    }

    /**
     * TO_LOWER (char)
     * Converte uma letra maiúscula para minúscula; 
    */
    char to_lower(char ch) {
        return ch >= 'A' && ch <= 'Z'? ch + ('a' - 'A') : ch;
    }

    /**
     * TO_UPPER (char) 
     * Converte uma letra minúscula para maiúscula;
    */
    char to_upper(char ch) {
        return ch >= 'a' && ch <= 'z'? ch - ('a' - 'A') : ch;
    }
    
    /**
     * TO_LOWER (string)
     * Converte uma letra maiúscula para minúscula;Esta função modifica a string recebida, 
     * mas também devolve-a para que possa ser utilizada em expressões 
     * do tipo string
    */
    std::string& to_lower(std::string& str){
        for(char& ch : str){
            ch = to_lower(ch);
        }
        return str;
    }

    /**
     * TO_UPPER (string)
     * implemente a versão complementar to_upper. 
    */
    std::string& to_upper(std::string& str){
        for(char& ch : str){
            ch = to_upper(ch);
        }
        return str;
    }

    /**
     * TRIM_LEFT (str)
     * Apara a string str à esquerda e devolve-a; implemente a 
     * versão complementar trim_right. "Aparar" uma string à esquerda consiste 
     * em remover os caracteres de espaçamento à esquerda, que estão entre o 
     * início da string e o primeiro caractere que não é de espaçamento. 
     * Esta função modifica a string recebida, mas também devolve-a para 
     * que possa ser utilizada em expressões do tipo string. 
     * Se a string não possuir caracteres de espaçamento à esquerda, 
     * então é simplesmente devolvida.
    */
    std::string& trim_left(std::string& str) {

        std::size_t index;
        for(index = 0; index < str.size(); index++) {
            if(str[index] != ' ') {
                break;
            }
        }

        str.erase(0, index);
        return str;
    }

    /**
     * TRIM (string)
     * Apara a string str à esquerda e à direita devolvendo essa string.
    */
    std::string& trim(std::string& str) {

        for(int i = str.size() - 1; i >= 0; i--) {
            if(str[i] != ' ') {
                break;
            }
            str.pop_back();
        }
        trim_left(str);
        return str;
    }

    /**
     * REVERSE (string)
     * Inverte a string str e devolve-a. Tal como com as funções trim, 
     * a string str é modifcada mas também é devolvida. 
     * Desenvolva o algoritmo de raiz, sem recorrer a quaisquer funções 
     * de algorithm (como, por exemplo, std::reverse ...) ou de qualquer 
     * outra biblioteca.
    */
    std::string& reverse(std::string& str) {
        std::string cp(str);
        for (int i = 0; i < cp.size(); i++) {
            str[i] = cp[cp.size() - 1 - i];
        }
        return str;
    }

    /**
     * REVERSED (string)
     * Devolve uma cópia invertida da string str com os caracteres 
     * por ordem inversa. Pode utilizar funções já feitas.
    */
    std::string reversed(const std::string& str) {
        std::stringstream ss(str);
        std::string word, text;

        while (ss >> word) {
            reverse(word);
            text += word + " ";
        }
        text.pop_back();
        return text;
    }

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
    std::string& replace(std::string& str, char ch1, char ch2, int start = 0, int end = -1) {
        
        int _end = end == -1 ? str.size() - 1 : end ;

        for(int i = start; i <= _end; i++){
            str[i] = str[i] == ch1 ? str[i] = ch2 : str[i] ;
        }
        return str;
    }

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
    std::string& replace(std::string& str, const std::string& substr1, const std::string& substr2, int start = 0, int end = -1) {

        int _end = end == -1 ? str.size() - 1 : end ;

        std::string cp(str);
        str.clear();

        bool match = true;
        int pos = 0;

        for(int i = start; i <= _end; i++){

            match = true;
            pos = i;

            for(int j = 0; j < substr1.size(); j++){
                if(cp[pos + j] != substr1[j]){
                    match = false;
                    break;
                }
            }

            if(match == true){
                str += substr2;
                i += substr1.size() - 1;
            }
            else{
                str += cp[i];
            }

        }

        return str;
    }

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
    std::vector<std::string> split(const std::string& str, 
                                   const std::string& delim) {

        std::string temp;
        std::vector<std::string> splt;

        bool eql = true;

        for(int i = 0; i < str.size(); i++){

            eql = true;

            for(int j = 0; j < delim.size(); j++){
                if(str[i + j] != delim[j]){
                    eql = false;
                    break;
                }
            }

            if(delim.size() == 0){
                temp += str[i];
                splt.emplace_back(temp);
                temp = "";
            }
            else if(eql == true){
                splt.emplace_back(temp);
                i += delim.size() - 1;
                temp = "";
            }
            else if(i == str.size() - 1){
                temp += str[i];
                splt.emplace_back(temp);
            }
            else{
                temp += str[i];
            }
        }

        return splt;
    }

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
    std::string join(const std::vector<std::string>& parts, const std::string& delim) {
        
        std::string res = parts[0];

        for(int i = 1; i < parts.size(); i++){
            res += delim + parts[i];
        }

        return res;
    }

} //<= namespace

#endif
