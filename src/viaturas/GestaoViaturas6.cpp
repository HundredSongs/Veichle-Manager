/**
 * Programa para gestão de um catálogo/stand de viaturas. Este programa 
 * permitirá:
 *     - Listar o catálogo
 *     - Pesquisar por alguns campos 
 *     - Eliminar um registo do catálogo
 *     - Guardar o catálogo em ficheiro
 *
* v4: 1) Construtor alternativo
 *    2) Construtor com nome e conversor para esse formato: from_csv e to_csv
 *    3) Métodos estáticos
*/

// matricula (str), marca, modelo, data
// 10-XY-20|Opel|Corsa XL|2019-10-15
// 20-PQ-15|Mercedes|300SL|2017-05-31

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <optional>
#include <map>
#include <cstdlib>

#include <fstream>
#include <fmt/format.h>

using namespace std;
using namespace fmt;

#include <boost/multiprecision/cpp_dec_float.hpp>

using money = boost::multiprecision::cpp_dec_float_50;

#include "Utils.hpp"

// Funcao para limpar o ecra. Cross_platform
void clear_scr(){
    #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}

const std::string CSV_DELIM = "|";

// Files /////////////////////////////////////////////
std::ifstream input_file("viaturas.csv");
std::ofstream output_file("output.csv");


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
            throw AttrViaturaInvalido(format("from_csv: Numero de atributos inválido"));
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
            //print("{}\n", string(10, '#'));
        }
    }

    // Additions ////////////////////////////////////

    void search_by_matricula(std::string matricula) {
        for (const auto& viat : this->viaturas) {
            if (viat.get_matricula() == matricula) {
                return viat.mostra();
            }
        }
        std::cout << "Not Found!\n";
    }

    void search_by_marca(std::string marca) {
        for (const auto& viat : this->viaturas) {
            if (viat.get_marca() == marca) {
                viat.mostra();
            }
        }
    }

    void search_by_modelo(std::string modelo) {
        for (const auto& viat : this->viaturas) {
            if (viat.get_modelo() == modelo) {
                viat.mostra();
            }
        }
    }

    void search_by_data(std::string data) {
        for (const auto& viat : this->viaturas) {
            if (viat.get_data() == data) {
                viat.mostra();
            }
        }
    }

    void save_to_csv() {
        for (const auto& viat : this->viaturas) {
            output_file << viat.to_csv() << "\n";
        }
    }

    // End of Additions /////////////////////////////

    private:

        vector<Viatura> viaturas;

};


////////////////////////////////////////////////////////////////////////////////
//
//       Added Functions
//
////////////////////////////////////////////////////////////////////////////////

    VoituresCollection viaturas;    // Global //////////////////////////////////

    void listagem_viat() {

        clear_scr();
        std::cout << "*** Listagem ***\n\n";

        viaturas._dump();

        std::cout << "\nCarregue em qualquer tecla para continuar.";
        std::cin.get();
    }

    void pesquisa_viat() {

        clear_scr();

        std::cout << "*** Pesquisa *** \n\n";
        std::cout << "1: Matricula" << std::endl;
        std::cout << "2: Marca" << std::endl;
        std::cout << "3: Modelo" << std::endl;
        std::cout << "4: Data" << std::endl;
        std::cout << "0: Sair" << std::endl;
        std::cout << "> ";

        std::string option_search;
        std::getline(std::cin, option_search);

        if(option_search == "1"){
            clear_scr();
            std::string matricula = "";
            std::cout << "Insira matricula: ";
            std::getline(cin, matricula);
            viaturas.search_by_matricula(matricula);
            std::cout << "Press Enter...";
            std::cin.get();
        }
        else if(option_search == "2"){
            clear_scr();
            std::string marca = "";
            std::cout << "Insira marca: ";
            std::getline(cin, marca);
            viaturas.search_by_marca(marca);
            std::cout << "Press Enter...";
            std::cin.get();
        }
        else if(option_search == "3"){
            clear_scr();
            std::string modelo = "";
            std::cout << "Insira modelo: ";
            std::getline(cin, modelo);
            viaturas.search_by_modelo(modelo);
            std::cout << "Press Enter...";
            std::cin.get();
        }
        else if(option_search == "4"){
            clear_scr();
            std::string data = "";
            std::cout << "Insira data: ";
            std::getline(cin, data);
            viaturas.search_by_data(data);
            std::cout << "Press Enter...";
            std::cin.get();
        }
        else if(option_search == "0"){ 
            clear_scr();    
        }
        else{
            clear_scr();
            std::cout << "Opcao invalida.";
            std::cin.get();
            clear_scr();
        }
    }


////////////////////////////////////////////////////////////////////////////////
//
//       MAIN
//
////////////////////////////////////////////////////////////////////////////////

int main() {

    std::string line;

    while(std::getline(input_file, line)){
        if(line.find("//") == 0 || line.find("##") == 0 || line == "") {
            continue;
        }
        viaturas.add(Viatura::from_csv(line));
    }
  
    while (true) {

        clear_scr();  
        char enter;

        std::cout << "*** Gestao de Viaturas ***\n" << std::endl;
        std::cout << "1: Listagem" << std::endl;
        std::cout << "2: Pesquisar" << std::endl;
        std::cout << "3: Inserir viatura" << std::endl;
        std::cout << "4: Remover viatura" << std::endl;
        std::cout << "5: Guardar alteracoes" << std::endl;
        std::cout << "0: Sair" << std::endl;

        std::cout << "> ";
        std::string option; 
        std::getline(std::cin, option);
            
        if(option == "1") {
            listagem_viat();
        }
        else if(option == "2") {
            pesquisa_viat();
        }
        else if (option == "3") {

        }
        else if (option == "4") {

        }
        else if (option == "5") {

            clear_scr();

            viaturas.save_to_csv();

            std::cout << "\nFicheiro salvo. \nPressione qualquer tecla para continuar.";
            std::cin.get(enter);
            clear_scr();    

        }
        else if (option == "0") {
            clear_scr();  
            return 0;
        }
        else {
            clear_scr();  
            std::cout << "Opcao invalida.";
            std::cin.get(enter);
        }

    } //while

} // main