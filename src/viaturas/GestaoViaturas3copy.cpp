#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <fmt/format.h>

using namespace std;
using namespace fmt;

#include <boost/multiprecision/cpp_dec_float.hpp>

using money = boost::multiprecision::cpp_dec_float_50;

#include "Utils.hpp"

class InvalidProdAttr : public invalid_argument {
    using invalid_argument::invalid_argument;
};

class Viatura {
public:
    Viatura(
        const string& matricula,
        const string& marca,
        const string& modelo,
        const string& data
    ) {
        if (!this->valida_data(data)) {
            throw InvalidProdAttr(format("Data inválida: {}", data));
        }

        this->matricula = matricula;
        this->marca = marca;
        this->modelo = modelo;
        this->data = data;
    }

    Viatura() : Viatura("", "", "", "") {}

    void mostra() const {
        print("Matricula -> {} | Marca/Modelo -> {}/{}\n", 
            this->matricula, this->marca, this->modelo);
    }

    bool valida_data(const string& data) const {
        auto date_parts = utils::split(data, "-");
        if (date_parts.size()!= 3) {
            return false;
        }
        auto year = date_parts[0];
        auto month = date_parts[1];
        auto day = date_parts[2];

        return    year.size() == 4 && utils::is_digit(year)
               && month.size() == 2 && utils::is_digit(month)
               && day.size() == 2 && utils::is_digit(day);
    }

    void listar_catalogo(const vector<Viatura>& catalogo) const {
        for (const auto& viatura : catalogo) {
            viatura.mostra();
        }
    }

    void pesquisar_por_marca(const vector<Viatura>& catalogo, const string& marca) const {
        for (const auto& viatura : catalogo) {
            if (viatura.marca == marca) {
                viatura.mostra();
            }
        }
    }

    void pesquisar_por_modelo(const vector<Viatura>& catalogo, const string& modelo) const {
        for (const auto& viatura : catalogo) {
            if (viatura.modelo == modelo) {
                viatura.mostra();
            }
        }
    }

    void remover_viatura(vector<Viatura>& catalogo, const string& matricula) {
        catalogo.erase(remove_if(catalogo.begin(), catalogo.end(),
            [&](const Viatura& viatura) { return viatura.matricula == matricula; }),
            catalogo.end());
    }

    string matricula;
    string marca;
    string modelo;
    string data;
};

void guardar_catalogo(const vector<Viatura>& catalogo, const string& nome_arquivo) {
    ofstream arquivo(nome_arquivo);
    if (arquivo.is_open()) {
        for (const auto& viatura : catalogo) {
            arquivo << viatura.matricula << "," << viatura.marca << "," << viatura.modelo << "," << viatura.data << endl;
        }
        arquivo.close();
        cout << "Catálogo salvo em '" << nome_arquivo << "'." << endl;
    } else {
        cout << "Não foi possível abrir o arquivo para salvar o catálogo." << endl;
    }
}

int main() {
    vector<Viatura> catalogo;

    catalogo.emplace_back("10-XY-20", "Opel", "Corsa XL", "2019-10-15");
    catalogo.emplace_back("20-PQ-15", "Mercedes", "300SL", "2017-05-31");

    Viatura viatura;
    viatura.listar_catalogo(catalogo);
    viatura.pesquisar_por_marca(catalogo, "Opel");
    viatura.pesquisar_por_modelo(catalogo, "300SL");
    viatura.remover_viatura(catalogo, "20-PQ-15");

    guardar_catalogo(catalogo, "catalogo.txt");

    return 0;
}