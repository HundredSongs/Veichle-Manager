/**
 * Módulo com utilitários gerais que integram a biblioteca EASY_STD.
 * 
 * Desenvolvido por João Roque e Licínio Feliciano
*/

#include <iostream>
#include <string>
#include <vector>

#ifndef __EASY_RANDOM_HPP__
#define __EASY_RANDOM_HPP__

namespace easy_std {

    // Variável global (interna) que representa o 
    // gerador de números aleatórios global:
    // static std::mt19937 rand_gen

    /**
     * Devolve um inteiro entre a e b inclusive, 
     * de acordo com uma distribuição uniforme
    */
    int randint(int a, int b) {

    }

    /**
     * Devolve um número double aleatório entre a e b. 
     * Por omissão, a = 0.0 e b = 1.0.
    */
    double random(double a = 0.0, double = 1.0) {

    }

    /**
     * Fornece um novo valor semente para o gerador de 
     * número aleatório rand_gen.
    */
    void seed(int value) {

    }

    /**
     * Escolhe aleatoriamente um elemento da sequência seq.
    */
    template<typename Seq>
    auto choice(const Seq& seq) {

    }

    /**
     * "Baralha" aleatoriamente os elementos da sequência seq.
     *  NOTA: Não utilize a função std::shuffle da biblioteca 
     *  algorithm (#include <algorithm>)
    */
    template<typename Seq>
    void shuffle_(Seq& seq) {

    }

    /**
     * Selecciona uma amostra de n valores da sequência seq. 
     * Os resultados são devolvidos num vector do tipo
     * da variável de retorno ou do tipo de chamamento
    */
    template<typename T, typename Seq>
    std::vector<T> sample(const Seq& seq, int n) {

    }










} //<= namespace

#endif