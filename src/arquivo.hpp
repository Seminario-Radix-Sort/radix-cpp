#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

class Arquivo{
    private:
        string nomeArquivo;

    public:
        Arquivo();
        Arquivo(string nomeArquivo);
        void setNomeArquivo(string nomeArquivo);
        string getNomeArquivo();
        vector<unsigned long long int> leituraArquivo();
        void escritaArquivo(string conteudoSaida);
};

#endif