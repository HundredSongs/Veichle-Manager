/**
 * Programa para gestão de um catálogo/stand de viaturas. Este programa 
 * permitirá:
 *     - Listar o catálogo
 *     - Pesquisar por alguns campos 
 *     - Eliminar um registo do catálogo
 *     - Guardar o catálogo em ficheiro
 *
* v4: 1) Construtor alternativo
 *     2) Construtor com nome e conversor para esse formato: from_csv e to_csv
 *     3) Métodos estáticos
*/

// matricula (str), marca, modelo, data
// 10-XY-20|Opel|Corsa XL|2019-10-15
// 20-PQ-15|Mercedes|300SL|2017-05-31

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <fmt/format.h>

using namespace std;
using namespace fmt;

#include <boost/multiprecision/cpp_dec_float.hpp>

using money = boost::multiprecision::cpp_dec_float_50;

#include "Utils.hpp"

const std::string CSV_DELIM = "|";

// Files /////////////////////////////////////////////
std::ifstream file("viaturas.csv");
std::ofstream csv("output.csv");


class AttrViaturaInvalido : public invalid_argument {  // class AttrViaturaInvalido extends IllegalArgumentExceptin
    using invalid_argument::invalid_argument;   
};

class Viatura {

public:

    Viatura(
            const string& matricula,        // matricula: DD-LL-DD onde D: Dígito L: Letra
            const string& marca,            // deve ter uma ou mais palavras (apenas letras ou dígitos)
            const string& modelo,           // mesmo que a marca
            const string& data              // deve vir no formato ISO: 'YYYY-MM-DD'
    ) {
        // 1. Validar parâmetros

        if (!this->valida_matricula(matricula)) {
            throw AttrViaturaInvalido(format("Matricula inválida: {}", matricula));
        }

        if (!this->valida_marca(marca)) {
            throw AttrViaturaInvalido(format("Marca inválida: {}", marca));
        }

        if (!this->valida_modelo(modelo)) {
            throw AttrViaturaInvalido(format("Modelo inválido: {}", modelo));
        }

        if (!this->valida_data(data)) {
            throw AttrViaturaInvalido(format("Data inválida: {}", data));
        }

        // 2. Associar parâmetros a atributos (ie, construir a representaçao
        //    interna do objecto)
        this->matricula = matricula;
        this->marca = marca;
        this->modelo = modelo;
        this->data = data;
    }

    Viatura(const string& matricula, const string& marca, const string& modelo) : Viatura(matricula, marca, modelo, "2024-03-20") {}

    // Metodos //////////////////////////////////////////////////////////////

    static Viatura from_csv(const string& viat_csv) {
        auto attrs = utils::split(viat_csv, CSV_DELIM);
        if(attrs.size() != 4){
            throw AttrViaturaInvalido(format("from_csv: Numero de atrivbutos inválido"));
        }
        return Viatura(
            attrs[0],
            attrs[1],
            attrs[2],
            attrs[3]
        );
    }

    string to_csv() const {
        return utils::join(
            {
                this->matricula,     // Java: String.format("%s", this.id)
                this->marca,
                this->modelo,
                this->data
            },
            CSV_DELIM
        );
    }


    void mostra() const {
        print("Matricula -> {} | Marca/Modelo -> {}/{}\n", 
              this->matricula, this->marca, this->modelo);
    }

    // Validar Variaveis /////////////////////////////////////////

    static bool valida_matricula(const string& matricula) {
        return regex_match(matricula, regex("^[0-9]{2}-[A-Z]{2}-[0-9]{2}$"));
    }

    static bool valida_data(const string& data) {
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

    static bool valida_marca(const string& marca) {
        // uma ou mais palavras, cada palavra apenas deve conter digitos/letras
        auto palavras = utils::split(marca);
        for (const auto& palavra : palavras) {   // for (String/var palavra : palavras)
            if (!utils::is_alnum(palavra)) {
                return false;
            }
        }
        return palavras.size() > 0;
    }

    static bool valida_modelo(const string& modelo) {
        return valida_marca(modelo);
    }

    // Afectar / Mostrar Variaveis Privadas ////////////

    std::string get_matricula() const {
        return this->matricula;
    }

    void set_matricula(std::string nova_matricula) {
        this->matricula = nova_matricula;
    }


    std::string get_marca() const {
        return this->marca;
    }

    void set_marca(std::string nova_marca) {
        this->marca = nova_marca;
    }


    std::string get_modelo() const {
        return this->modelo;
    }

    void set_modelo(std::string nova_modelo) {
        this->modelo = nova_modelo;
    }


    std::string get_data() const {
        return this->data;
    }

    void set_data(std::string nova_data) {
        this->data = nova_data;
    }

    // Data Privada ////////////////////////////////////

private:

    string matricula;
    string marca;
    string modelo;
    string data;

};

////////////////////////////////////////////////////////////////////////////////
//
//       CATÁLOGO DE PRODUTOS (PRODUCT COLLECTION)
//
////////////////////////////////////////////////////////////////////////////////

class DuplicateValue : public invalid_argument {
    using invalid_argument::invalid_argument;
};

class VoituresCollection {

public:

    void add(const Viatura& viat) {
        auto new_viat_id = viat.get_matricula();
        if (this->search_by_id(new_viat_id)) {
            throw DuplicateValue(format("Já existe uma viatura com a matricula {}\n", new_viat_id));
        }
        this->viaturas.emplace_back(viat);
    }

    optional<Viatura> search_by_id(std::string matricula) {
        for (const auto& viat : this->viaturas) {
            if (viat.get_matricula() == matricula) {
                return viat;
            }
        }
        return {};    // OU return nullopt;
    }

    void _dump() {
        for (const auto& viat : this->viaturas) {
            viat.mostra();
            print("{}\n", string(10, '#'));
        }
    }

    void save() {
        for (const auto& viat : this->viaturas) {
            csv << viat.to_csv() << "\n";
        }
    }

private:

    vector<Viatura> viaturas;

};


////////////////////////////////////////////////////////////////////////////////
//
//       MAIN
//
////////////////////////////////////////////////////////////////////////////////

int main() {

    std::string line;

    VoituresCollection viaturas;

    while(std::getline(file, line)){
        if(line.find("//") == 0 || line.find("##") == 0 || line == "") {
            continue;
        }
        viaturas.add(Viatura::from_csv(line));
    }

    
    std::cout << "\n\n***Demonstracao terminada.*** \nDeseja utilizar as funcionalidades do programa? (y/n)";
    char option;

    while (true) {
        option = getchar();
        if (option == 'y') {
            while (true) {

                std::cout << "*** Gestao de Viaturas ***" << std::endl;
                std::cout << "1: Listagem" << std::endl;
                std::cout << "2: Pesquisar" << std::endl;
                std::cout << "3: Inserir viatura" << std::endl;
                std::cout << "4: Remover viatura" << std::endl;
                std::cout << "5: Guardar alteracoes" << std::endl;
                char option2;
                std::cin >> option2;
                
                switch(option2){
                    case '1': 
                        viaturas._dump();

                    case '2': ;
                    case '3': ;
                    case '4': ;

                    case '5': 
                        viaturas.save();
                        
                    default:
                        std::cout << "Opcao invalida.";
                        break;
                
                }

            } //while 2

        }
        else if (option == 'n') {
            return 0;
        }
        else {
            std::cout << "Opcao invalida.";
        }

    } // while 1

} // main