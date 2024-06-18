#include "radixSort.hpp"

RadixSort::RadixSort() {
    tamanho = 10000;
    base = 10;
}

RadixSort::RadixSort(vector<unsigned long long int> vetor, int tamanho, int base) {
    this->vetor = vetor;
    this->tamanho = tamanho;
    this->base = base;
}

void RadixSort::setVetor(vector<unsigned long long int> vetor) {
    this->vetor = vetor;
}

void RadixSort::setTamanho(int tamanho) {
    this->tamanho = tamanho;
}

void RadixSort::setBase(int base) {
    this->base = base;
}

vector<unsigned long long int> RadixSort::getVetor() {
    return vetor;
}

int RadixSort::getTamanho() {
    return tamanho;
}

unsigned long long int RadixSort::getMaior() {
    unsigned long long int maior = this->vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (this->vetor[i] > maior) {
            maior = this->vetor[i];
        }
    }
    return maior;
}

int RadixSort::getBase() {
    return base;
}

void RadixSort::radixSort() {
    unsigned long long int maior = getMaior();
    unsigned long long int exp = 1;

    while (maior / exp > 0) {        
        countingSort(exp);
        exp *= 10;
    }
}

void RadixSort::countingSort(int exp) {
    unsigned long long int saida[tamanho];
    int i, contagem[this->base] = {0};

    for (i = 0; i < tamanho; i++) {
        contagem[(vetor[i] / exp) % this->base]++;
    }

    for (i = 1; i < this->base; i++) {
        contagem[i] += contagem[i - 1];
    }

    for (i = tamanho - 1; i >= 0; i--) {
        saida[contagem[(vetor[i] / exp) % this->base] - 1] = vetor[i];
        contagem[(vetor[i] / exp) % this->base]--;
    }

    for (i = 0; i < tamanho; i++) {
        vetor[i] = saida[i];
    }
}