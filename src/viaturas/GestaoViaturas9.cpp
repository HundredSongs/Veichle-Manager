/**
 * Programa para gestão de um catálogo/stand de viaturas. Este programa 
 * permitirá:
 *     - Listar o catálogo
 *     - Pesquisar por alguns campos 
 *     - Eliminar um registo do catálogo
 *     - Guardar o catálogo em ficheiro
 *
 * v7: 1) Ler catálogo viaturas a partir de ficheiro CSV
 *     2) Tornar VehicleCollection iterável (métodos begin e end)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <optional>
#include <unordered_map>
#include <fmt/format.h>

using namespace std;
using namespace fmt;

#include <boost/multiprecision/cpp_dec_float.hpp>

using money = boost::multiprecision::cpp_dec_float_50;

#include "Utils.hpp"

const string CSV_DELIM = "|";

////////////////////////////////////////////////////////////////////////////////
//
//       VIATURA
//
////////////////////////////////////////////////////////////////////////////////

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

    Viatura(
            const string& matricula,
            const string& marca,
            const string& modelo
    ) : Viatura(matricula, marca, modelo, "2020-01-01")
    {
    }

    static Viatura from_csv(const string& viat_csv) {
        auto attrs = utils::split(viat_csv, CSV_DELIM);
        if (attrs.size() != 4) {
            throw AttrViaturaInvalido("from_csv: Número de atributos inválidos");
        }
        return Viatura(
            attrs[0],       // matricula
            attrs[1],       // marca
            attrs[2],       // modelo
            attrs[3]        // data
        );
    }

    string to_csv() {
        return utils::join(
            {
                this->matricula,
                this->marca,
                this->modelo,
                this->data
            },
            CSV_DELIM
        );
    }

    void mostra() const {
        print("Matricula -> {} | Marca/Modelo -> {}/{} | Ano -> {}\n", 
              this->matricula, this->marca, this->modelo, this->data);
    }

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

        return    year.size() == 4  && utils::is_digit(year)
               && month.size() == 2 && utils::is_digit(month)
               && day.size() == 2   && utils::is_digit(day)
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
        return !marca.empty();
    }

    static bool valida_modelo(const string& modelo) {
        return valida_marca(modelo);
    }

    string get_matricula() const {
        return this->matricula;
    }

    void set_matricula(const string& nova_matricula) {
        if (!valida_matricula(nova_matricula)) {
            throw AttrViaturaInvalido(format("Matricula inválida: {}", nova_matricula));
        }
    }

    string get_marca() const {
        return this->marca;
    }

    string get_modelo() const {
        return this->modelo;
    }

    string get_data() const {
        return this->data;
    }

    void set_data(const string& nova_data) {
        if (!this->valida_data(nova_data)) {
            throw AttrViaturaInvalido(format("Data inválida: {}", nova_data));
        }
    }

    int get_ano() const {
        auto ano_str = utils::split(this->data, "-")[0];
        return utils::convert<int>(ano_str);
    }

private:
    string matricula;
    string marca;
    string modelo;
    string data;
};

////////////////////////////////////////////////////////////////////////////////
//
//       CATÁLOGO DE VIATURAS (VEHICLE COLLECTION)
//
////////////////////////////////////////////////////////////////////////////////

class DuplicateValue : public invalid_argument {
    using invalid_argument::invalid_argument;
};

class VehicleCollection {
public:
    static VehicleCollection from_csv(const string& path) {
        ifstream csv_file(path);

        VehicleCollection vehicles;
        string line;
        while (getline(csv_file, line)) {
            if (utils::trim(line).empty()) {
                continue;
            }
            if (line.starts_with("##") or line.starts_with("//")) {
                continue;
            }

            vehicles.add(Viatura::from_csv(line));
        }
        return vehicles;
    }

    void add(const Viatura& viat) {
        auto viatura = this->search_by_id(viat.get_matricula());
        if (viatura) {
            auto msg = format("Já existe viatura com matricula {}", viat.get_matricula());
            throw DuplicateValue(msg);
        }
        this->viaturas.insert_or_assign(viat.get_matricula(), viat);
    }

    optional<Viatura> search_by_id(const string& matricula) {
        if (this->viaturas.contains(matricula)) {
            return this->viaturas.at(matricula);
        }
        return {};
    }

    bool search_by_matricula(const string& matricula) {
        if (this->viaturas.contains(matricula)) {
            this->viaturas.at(matricula).mostra();
            return true;
        }
        return false;
    }

    template<typename F>
    VehicleCollection search(F funcao_criterio ) {
        VehicleCollection encontrados;
        for (const auto& [matricula, viat] : this->viaturas) {
            if ( funcao_criterio(viat)  ) {
                encontrados.add(matricula, viat);
            }
        }
        return encontrados;
    }

    void remove_entry(std::string matricula){

        auto i = this->viaturas.begin();

        for(const auto& viat : this->viaturas){

            if(viat.first == matricula){
                this->viaturas.erase(i);
                return;
            }
            i++;
        }
        auto msg = "[-] A viatura nao esta registada...\n";
        println("{}{}", string(3, ' '), msg);
        return;
    }

    void save_to_csv() {
        std::ofstream output_file("viaturas.csv");
        for (const auto& viat : this->viaturas) {
            auto all = viat.second;
            output_file << all.to_csv() << "\n";
        }
    }

    void _dump() {
        for (const auto& [matricula, viat] : this->viaturas) {
            viat.mostra();
            println("{}", string(20, '-'));
        }
    }

    unordered_map<string, Viatura>::iterator begin() {
        return this->viaturas.begin();
    }

    unordered_map<string, Viatura>::iterator end() {
        return this->viaturas.end();
    }

private:
    unordered_map<string, Viatura> viaturas;
};

////////////////////////////////////////////////////////////////////////////////
//
//       MAIN
//
////////////////////////////////////////////////////////////////////////////////


const int DEFAULT_INDENTATION = 3;

// Variável global com o catálogo de produtos gerido pelo programa
VehicleCollection viaturas;

void show_msg(const string& msg, int indent = DEFAULT_INDENTATION) {
    println("{}{}", string(indent, ' '), msg);
}

string ask(const string& msg, int indent = DEFAULT_INDENTATION) {
    print("{}{}", string(indent, ' '), msg);
    string answer;
    getline(cin, answer);
    return answer;
}

void clear_screen() {
#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

void pause_(int indent = 3) {
#if defined(__linux__) || defined(__FreeBDS__)  || defined (__APPLE__) 
    show_msg("Pressione qualquer tecla para continuar...");
    string nao_interessa;
    getline(cin, nao_interessa);
    // system("read -s -n 1");
#elif _WIN32
    show_msg("Pressione qualquer tecla para continuar...");
    system("pause>nul")     // NOTA: confirmar se comando está correcto em Windows
#else
    show_msg("Pressione ENTER para continuar...");
    string nao_interessa;
    getline(cin, nao_interessa);
#endif
}

void show_table_with_viat(VehicleCollection viaturas) {
    auto header = format(
        "{:^14}|{:^20}|{:^14}|{:^12}",
        "Matricula", "Marca", "Modelo", "Data"
    );
    auto sep = format(
        "{}+{}+{}+{}",
        string(14, '-'), string(20, '-'), string(14, '-'), string(12, '-')
    );

    show_msg(header);
    show_msg(sep);

    for (const auto& viat : viaturas) {
        auto data_line = format(
            "{:^14}|{:^20}|{:^14}|{:^12}",
            viat.first, 
            viat.second.get_marca(),
            viat.second.get_modelo(),
            viat.second.get_data()
        );
        show_msg(data_line);
        // show_msg(sep);
    }
}

// Listar catálogo  //////////////////////////////
void exec_list_viat() {

    clear_screen();
    println("");

    show_table_with_viat(viaturas);

    println("");
    pause_();
}
// Pesquisar por MATRICULA ///////////////////////
void exec_search_by_matricula() {

    clear_screen();
    println("");

    show_msg("PESQUISA POR MRICULA\n");
    auto matricula = ask("Indique o MATRICULA do produto a pesquisar: ");
    auto viat_encontrado = viaturas.search_by_id(matricula);
    println("");
    
    if (viat_encontrado) {
        VehicleCollection encontrados;
        encontrados.add(viat_encontrado.value());
        show_table_with_viat(encontrados);
    }
    else {
        show_msg(format("Não foram encontrados produtos com ID {}", matricula));
    }

    println("");
    pause_();
}
// Acrescentar viatura ///////////////////////////
void exec_add_viat() {

    clear_screen();
    println("");

    std::string matricula = ask("Insira a matricula: ");
    std::string marca = ask("Insira a marca: ");
    std::string modelo = ask("Insira a modelo: ");
    std::string data = ask("Insira a data: ");

    viaturas.add(
        Viatura(
            matricula,
            marca,
            modelo,
            data
    ));

    viaturas.save_to_csv();

    println("");
    pause_();
}
// Apagar viatura ////////////////////////////////
void exec_del_viat() {

    clear_screen();
    println("");
    
    std::string matricula = ask("Insira a matricula: ");
    auto viat_encontrado = viaturas.search_by_id(matricula);
    
    if(viat_encontrado){

        VehicleCollection encontrados;
        encontrados.add(viat_encontrado.value());
        show_table_with_viat(encontrados);

        std::string confirmation = ask("Deseja remover a viatura [s/n]? ");
        println("");
        
        if(confirmation == "s" || confirmation == "S"){
            viaturas.remove_entry(matricula);
            show_msg("[+] A actualizar catálogo ...");
            viaturas.save_to_csv();
            show_msg("[+] ... catálogo actualizado!");
            show_msg("[-] A viatura foi removida.");
        }
        else{
            show_msg("[-] A viatura não foi removida.");
        }
    }
    else {
        show_msg("[-] A viatura não foi encontrada.");
    }

    println("");
    pause_();
}
// SAVE //////////////////////////////////////////
void exec_save() {
    println("");

    show_msg("[+] A actualizar catálogo ...");
    viaturas.save_to_csv();
    show_msg("[+] ... catálogo actualizado!");

    println("");
    pause_();
}
// Save & EXIT ///////////////////////////////////
void exec_end() {
    println("");

    show_msg("[+] A actualizar catálogo ...");
    viaturas.save_to_csv();
    show_msg("[+] ... catálogo actualizado!");
    show_msg("[+] O programa vai terminar.");

    show_msg("");
    exit(0);
}
// MENU //////////////////////////////////////////
void exec_menu() {
    while (true) {
        clear_screen();
        println("");
        show_msg("#################################################");
        show_msg("#                                               #");
        show_msg("#  L  - Listar catálogo                         #");
        show_msg("#  P  - Pesquisar por matricula                 #");
        show_msg("#  PT - Pesquisar por tipo                      #");
        show_msg("#  A  - Acrescentar produto                     #");
        show_msg("#  E  - Eliminar produto                        #");
        show_msg("#  G  - Guardar catálogo em ficheiro            #");
        show_msg("#                                               #");
        show_msg("#  T  - Terminar o programa                     #");
        show_msg("#                                               #");
        show_msg("#################################################");
        println("");

        string opcao = ask("OPÇÃO> ");

        auto OPCAO = utils::to_upper_copy(opcao);
        if (OPCAO == "L" || OPCAO == "LISTAR") {
            exec_list_viat();
        }
        else if (OPCAO == "P" || OPCAO == "PESQUISAR") {
            exec_search_by_matricula();
        }
        else if (OPCAO == "A" || OPCAO == "ACRESCENTAR") {
            exec_add_viat();
        }
        else if (OPCAO == "E" || OPCAO == "ELIMINAR") {
            exec_del_viat();
        }
        else if (OPCAO == "G" || OPCAO == "GUARDAR") {
            exec_save();
        }
        else if (OPCAO == "T" || OPCAO == "TERMINAR") {
            exec_end();
        }
        else {
            println("");
            show_msg(format("ATENÇÃO: Opção {} inválida", opcao));
            pause_();
        }
    }
}

int main() {
    viaturas = VehicleCollection::from_csv("viaturas.csv");
    exec_menu();
}