#include "controladorRadix.hpp"

ControladorRadix::ControladorRadix() {
    tamanhos = { 10000, 100000, 500000, 1000000 };
    somaTempo = 0;
    tabelaSaida = "";
}

ControladorRadix::ControladorRadix(vector<int> tamanhos) {
    this->tamanhos = tamanhos;
    somaTempo = 0;
    tabelaSaida = "";
}

void ControladorRadix::setTamanhos(vector<int> tamanhos) {
    this->tamanhos = tamanhos;
}

vector<int> ControladorRadix::getTamanhos() {
    return tamanhos;
}

float ControladorRadix::getSomaTempo() {
    return somaTempo;
}

string ControladorRadix::getTabelaSaida() {
    return tabelaSaida;
}

void ControladorRadix::calcularTabelaSaidaRadix() {
    Arquivo arquivo;
    vector<string> ordens = { "Aleatorio", "Crescente", "Decrescente" };
    vector<string> tipos = { "", "-RangeMenor", "-RangeMaior", "-CEP", "-Iguais", "-Extremo" };
    tabelaSaida = "Tamanho/Tipo,Aleatorio,Aleatorio-RangeMenor,Aleatorio-RangeMaior,Aleatorio-CEP,Aleatorio-Iguais,Aleatorio-Extremo,Crescente,Crescente-RangeMenor,Crescente-RangeMaior,Crescente-CEP,Crescente-Iguais,Crescente-Extremo,Decrescente,Decrescente-RangeMenor,Decrescente-RangeMaior,Decrescente-CEP,Decrescente-Iguais,Decrescente-Extremo\n";
    
    for(auto t : tamanhos){
        tabelaSaida += to_string(t) + ",";
        for(auto o : ordens){
            string nomeArquivo = "datasets/";
            string dirOrdem;

            dirOrdem = toLower(o) + "s/";

            nomeArquivo += dirOrdem + to_string(t) + o;

            for(auto tp : tipos){
                nomeArquivo += tp + ".txt";
                arquivo.setNomeArquivo(nomeArquivo);
                vector<unsigned long long int> vetor = arquivo.leituraArquivo();
                RadixSort radixSort = RadixSort();
                float tempo = 0;
                radixSort.setTamanho(t);
                radixSort.setBase(10);

                for(int j = 0; j < 10; j++){
                    radixSort.setVetor(vetor);
                    auto inicio = chrono::high_resolution_clock::now();
                    radixSort.radixSort();
                    auto fim = chrono::high_resolution_clock::now();
                    chrono::duration<double, milli> duracao = (fim - inicio);
                    tempo += duracao.count();
                    somaTempo += (duracao.count() / 1000);
                    //cout << "Sorted: " << is_sorted(radixSort.getVetor().begin(), radixSort.getVetor().end()) << "\n";
                }
                
                if(!estaOrdenado(radixSort.getVetor())) {
                    // printa vetor em arquivo

                    cout << "Desordenado\n";
                    ofstream arquivo;
                    arquivo.open("datasets/" + dirOrdem + to_string(t) + o + tp + "-RadixSortDesordenado.txt");
                    if(arquivo.is_open()){
                        for(int i = 0; i < radixSort.getTamanho(); i++){
                            arquivo << radixSort.getVetor()[i] << " ";
                        }
                        arquivo.close();
                    }else{
                        cout << "Erro ao abrir arquivo\n";
                    }
                }
                tabelaSaida += to_string((tempo / 10) / 1000) + ",";
                nomeArquivo = "datasets/" + dirOrdem + to_string(t) + o;
            }
        }
        tabelaSaida += "\n"; 
    }
    
    tabelaSaida += "Tempo Total," + to_string(somaTempo) + "\n";
    tabelaSaida += "Tempo Medio Total," + to_string(somaTempo / 720) + "\n";
}

string ControladorRadix::toLower(string str){
    for(long unsigned int i = 0; i < str.size(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

bool ControladorRadix::estaOrdenado(vector<unsigned long long int> vetor){
    for(long unsigned int i = 0; i < vetor.size() - 2; i++){
        if(vetor[i] > vetor[i + 1]){
            cout << "Erro na posicao " << i << endl;
            cout << vetor[i] << " > " << vetor[i + 1] << endl;
            return false;
        }
    }
    return true;
}