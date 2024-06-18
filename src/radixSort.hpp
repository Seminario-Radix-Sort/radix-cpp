#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RadixSort{
    public:
        RadixSort();
        RadixSort(vector<unsigned long long int> vetor, int tamanho, int base);
        void setVetor(vector<unsigned long long int> vetor);
        void setTamanho(int tamanho);
        void setBase(int base);
        vector<unsigned long long int> getVetor();
        int getTamanho();
        int getBase();
        void radixSort();
    private:
        vector<unsigned long long int> vetor;
        unsigned long long int getMaior();
        int tamanho;
        int base;
        void countingSort(int exp);
};

#endif