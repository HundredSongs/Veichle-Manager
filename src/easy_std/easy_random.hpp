/**
 * Módulo com utilitários gerais que integram a biblioteca EASY_STD.
 * 
 * Desenvolvido por João Roque e Licínio Feliciano
*/

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

#ifndef __EASY_RANDOM_HPP__
#define __EASY_RANDOM_HPP__

namespace easy_std {

    // Variável global (interna) que representa o 
    // gerador de números aleatórios global:
    static std::mt19937 rand_gen(std::random_device{}());

    /**
     * Devolve um inteiro entre a e b inclusive, 
     * de acordo com uma distribuição uniforme
    */
    int randint(int a, int b) {
        std::uniform_int_distribution<> dis(a, b);
        return dis(rand_gen);
    }

    /**
     * Devolve um número double aleatório entre a e b. 
     * Por omissão, a = 0.0 e b = 1.0.
    */
    double random(double a = 0.0, double b= 1.0) {
        std::uniform_real_distribution<> dis(a, b);
        return dis(rand_gen);
    }

    /**
     * Fornece um novo valor semente para o gerador de 
     * número aleatório rand_gen.
    */
    void seed(int value) {
        rand_gen.seed(value);
    }

    /**
     * Escolhe aleatoriamente um elemento da sequência seq.
    */
    template<typename Seq>
    auto choice(const Seq& seq) {
        int size = seq.size() - 1;
        int res = randint(0, size);
        return seq[res];
    }

    /**
     * "Baralha" aleatoriamente os elementos da sequência seq.
     *  NOTA: Não utilize a função std::shuffle da biblioteca 
     *  algorithm (#include <algorithm>)
    */
    template<typename Seq>
    void shuffle_(Seq& seq) {

        std::vector<int> nums;
        Seq cp = (seq);
        seq.clear();

        for(int i = 0; i < cp.size(); i++){

            bool in = false;
            int roll = randint(0, cp.size() - 1);
            
            for(const int& n : nums){
                if(n == roll){
                    in = true;
                }
            }
            if(in == true){
                i--;
            }
            else if(in == false){
                nums.emplace_back(roll);
            }
        }

        for(int i = 0; i < cp.size(); i++){
            seq.emplace_back(cp[nums[i]]);
        }
    }

    /**
     * Selecciona uma amostra de n valores da sequência seq. 
     * Os resultados são devolvidos num vector do tipo
     * da variável de retorno ou do tipo de chamamento
    */
    template<typename Seq>
    Seq sample(const Seq& seq, int n) {

        Seq copy = seq;
        std::vector<int> nums;
        Seq result;

        n = n > seq.size() ? seq.size() : n ;

        for(int i = 0; i < n; i++){

            bool in = false;
            int roll = randint(0, copy.size() - 1);

            for(const int& num : nums){
                if(num == roll){
                    in = true;
                }
            }
            if(in == true){
                i--;
            }
            else if(in == false){
                nums.emplace_back(roll);
            }
        }

        for(int i = 0; i < n; i++){
            result.emplace_back(copy[nums[i]]);
        }

        return result;
    }


} //<= namespace

#endif