#include <vector>
#include <iostream>
#include <time.h>

#include "item.h"
#include "heap.h"

bool repetido (int contem[], int valor, int tamanho) { //função para não inserir numeros repetidos no heap
    for(int i = 0; i < tamanho; i++){
        if (contem[i] == valor)
            return false;
    }
    return true;
}

int main (int argc, char* argv[]) {

    Item* reg;
    std::vector<Item*> heap;
    Heap* heapsort;
    reg = new Item(0);
    heap.push_back(reg);
    std :: cout << "-- Heap ordenado em ordem crescente --" << std::endl << std::endl;

    for(int i = 10000; i <= 100000; i = i + 10000){
        reg = new Item(i);
        heap.push_back(reg);
        heapsort = new Heap(heap);
        heapsort->constroi();
        std :: cout << "i = " << i/10000 << std::endl << std::endl;
    }

    std :: cout  << std::endl;

    heap.clear();
    reg = new Item(0);
    heap.push_back(reg);
    int j = 1;
    std :: cout << "-- Heap ordenado em ordem decrescente --" << std::endl << std::endl;

    for(int i = 100000; i >= 10000; i = i - 10000){
        reg = new Item(i);
        heap.push_back(reg);
        heapsort = new Heap(heap);
        heapsort->constroi();
        std :: cout << "i = " << j << std::endl << std::endl;
        j++;
    }

    std :: cout  << std::endl;

    heap.clear();
    reg = new Item(0);
    heap.push_back(reg);

    srand((unsigned)time(0));
    int randon;
    int contem[10] = {0,0,0,0,0,0,0,0,0,0}; // vetor para ajudar a conferir se n tem vamor repetido
    int i = 1;
    std :: cout << "-- Heap ordenado em ordem aleatória --" << std::endl << std::endl;

    while(i <= 10){
        randon = ((rand()%10)+1)*10000;
        if (repetido(contem, randon, 10)){ //só vai inserir no heap se o valor for novo no vetor
            contem[i-1] = randon;
            reg = new Item(randon);
            heap.push_back(reg);
            heapsort = new Heap(heap);
            heapsort->constroi();
            std :: cout << "i = " << i << std::endl << std::endl;
            i++;
        }
    }
}
