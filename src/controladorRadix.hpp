#ifndef CONTROLADOR_RADIX_HPP
#define CONTROLADOR_RADIX_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "arquivo.hpp"
#include "radixSort.hpp"

using namespace std;

class ControladorRadix{
    public:
        ControladorRadix();
        ControladorRadix(vector<int> tamanhos);
        void setTamanhos(vector<int> tamanhos);
        vector<int> getTamanhos();
        float getSomaTempo();
        string getTabelaSaida();
        void calcularTabelaSaidaRadix();
    private:
        vector<int> tamanhos;
        float somaTempo;
        string tabelaSaida;
        string toLower(string str);
        bool estaOrdenado(vector<unsigned long long int> vetor);
};

#endif