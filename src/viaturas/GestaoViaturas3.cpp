/**
 * Programa para gestÃ£o de um catÃ¡logo/stand de viaturas. Este programa 
 * permitirÃ¡:
 *     - Listar o catÃ¡logo
 *     - Pesquisar por alguns campos 
 *     - Eliminar um registo do catÃ¡logo
 *     - Guardar o catÃ¡logo em ficheiro
 */

// matricula (str), marca, modelo, data
// 10-XY-20,Opel,Corsa XL,2019-10-15
// 20-PQ-15,Mercedes,300SL,2017-05-31

#include <iostream>
#include <string>
#include <vector>
#include <fmt/format.h>

using namespace std;
using namespace fmt;

#include <boost/multiprecision/cpp_dec_float.hpp>

using money = boost::multiprecision::cpp_dec_float_50;

#include "Utils.hpp"

class InvalidProdAttr : public invalid_argument {  // class InvalidProdAttr extends IllegalArgumentExceptin
    using invalid_argument::invalid_argument;
};

class Viatura {
public:

    Viatura(
        const string& matricula,        // matricula: DD-LL-DD onde D: DÃ­gito L: Letra
        const string& marca,            // deve ter uma ou mais palavras (apenas letras ou dÃ­gitos)
        const string& modelo,           // mesmo que a marca
        const string& data              // deve vir no formato ISO: 'YYYY-MM-DD'
    ) {
        // 1. Validar parÃ¢metros

        if (!this->valida_matricula(matricula)) {
            throw InvalidProdAttr(format("Matricula invÃ¡lida: {}", matricula));
        }

        if (!this->valida_data(data)) {
            throw InvalidProdAttr(format("Data invÃ¡lida: {}", data));
        }

        // 2. Associar parÃ¢metros a atributos (ie, construir a representaÃ§ao
        //    interna do objecto)
        this->matricula = matricula;
        this->marca = marca;
        this->modelo = modelo;
        this->data = data;
    }

    void mostra() {
        print("Matricula -> {} | Marca/Modelo -> {}/{}\n", 
              this->matricula, this->marca, this->modelo);
    }

    bool valida_matricula(const string& matricula) {
        
        // DD-LL-DD
        auto parts = utils::split(matricula, "-");
        if (parts.size() != 3) {
            return false;
        }
        auto part1 = parts[0];
        auto part2 = parts[1];
        auto part3 = parts[2];

        return    part1.size() == 2 && utils::is_digit(part1)
               && part3.size() == 2 && utils::is_digit(part3)
               && part2.size() == 2 && utils::is_alpha(part2) && part2 == utils::to_upper_copy(part2) 
        ;
    }

    bool valida_data(const string& data) {
        auto date_parts = utils::split(data, "-");
        if (date_parts.size() != 3) {
            return false;
        }
        auto year = date_parts[0];
        auto month = date_parts[1];
        auto day = date_parts[2];

        return    year.size() == 4 && utils::is_digit(year)
               && month.size() == 2 && utils::is_digit(month)
               && day.size() == 2 && utils::is_digit(day)
        ;
    }

    string matricula;
    string marca;
    string modelo;
    string data;
};

int main() {
    Viatura viat1(
        "10-XY-20",
        "Opel",
        "Corsa XL",
        "2019-10-15"
    );
    viat1.mostra();

    Viatura viat2(
        "20-PQ-15",
        "Mercedes",
        "300SL",
        "2017-05-31"
    );
    viat2.mostra();

    try {
        Viatura(
            "20-PQ-15",
            "Mercedes",
            "300SL",
            "2017-05-31"
        );
    }
    catch (InvalidProdAttr& ex) {
        println("ERRO: {}", ex.what());
    }
}