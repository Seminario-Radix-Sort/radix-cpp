#include "arquivo.hpp"

Arquivo::Arquivo() {
    nomeArquivo = "";
}

Arquivo::Arquivo(string nomeArquivo) {
    this->nomeArquivo = nomeArquivo;
}

void Arquivo::setNomeArquivo(string nomeArquivo) {
    this->nomeArquivo = nomeArquivo;
}

string Arquivo::getNomeArquivo() {
    return nomeArquivo;
}

vector<unsigned long long int> Arquivo::leituraArquivo() {
    vector<unsigned long long int> vetor;
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    if (arquivo.is_open()) {
        string linha;
        // pular duas primeiras linhas
        getline(arquivo, linha);
        getline(arquivo, linha);
        // pegar os valores separados por virgula ate o final do arquivo
        // int i = 0;
        while (getline(arquivo, linha, ',')) {
            vetor.push_back(stoull(linha));
            /*cout << vetor[i] << endl;
            i++;*/
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    return vetor;
}

void Arquivo::escritaArquivo(string conteudoSaida) {
    ofstream arquivo;
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::stringstream buffer;
    buffer << std::put_time(&tm, "%d-%m-%Y-%H:%M:%S");
    std::string dateTime(buffer.str());

    nomeArquivo += "-" + dateTime + ".csv";
    arquivo.open(nomeArquivo);
    if (arquivo.is_open()) {
        arquivo << "Data e Hora de Execução: " << dateTime << endl;
        arquivo << "Tempos em segundos:" << endl;

        arquivo << conteudoSaida;
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
    }
}