#include <stdio.h>
#include <string.h>

#include "arquivo.hpp"
#include "controladorRadix.hpp"

int main(void){
    ControladorRadix controladorRadix = ControladorRadix({ 10000, 100000, 500000, 1000000 });

    cout << "Calculando tabela de saida do Radix Sort..." << endl;
    controladorRadix.calcularTabelaSaidaRadix();
    Arquivo arquivoSaida = Arquivo("datasets/tempoExecucao-CPP");
    arquivoSaida.escritaArquivo(controladorRadix.getTabelaSaida());
    cout << "Tabela de saida do Radix Sort calculada com sucesso!" << endl;

    return 0;
}