#include <iostream>
#include <vector>
#include "heap.h"
Heap::Heap (std::vector<Item*> h) 
    : v(h){ //o vetor da classe recebe o vetor do construtor
    n = v.size()-1; //o n recebe o size -1 para não sair do vetor durante o programa
}

Heap::~Heap () {

}

Item* Heap::max () {
    return this->v[1];
}

void Heap::refaz (int esq, int dir) {
    
    int j = esq*2; //começa no filho esquerdo do heap
    Item* x = this->v[esq];

    while(j <= dir) { //continua no for enquanto j estiver dentro do tamanho do heap
        std :: cout << "Inicio comparação." << std::endl;
        if((j < dir) && (this->v[j]->compara(this->v[j + 1]) < 0)) //se existir filho direito e o filho direito for maior que o esquerdo avança j para o filho direito
            j++;
        if (x->compara(this->v[j]) >= 0) //se o pai for maior que os filhos para a comparação
            break;
        this->v[esq] = this->v[j]; //a posição esquerda pega o maior valor
        esq = j; //esquerda se torna a posição do filho maior
        j = esq * 2; //j assume a posição do filho do novo esquerda
    }
    this->v[esq] = x; //quando sair do while o valor que sobrou que é o menor de todos fica nesse esquerda que esta no final do heap
}

void Heap::constroi () {
    int esq = (n/2) + 1;
    while (esq > 1) { //chama o refaz para ordenar o heap com o tamanh0o esquerdo indo de n/2 ate 1
        esq--;
        this->refaz(esq, this->n);
    }
    //std::cout << "conteudo do heap:";
    //for(int i = 1; i <= n; i++)
    //    std::cout << " " << v[i]->getChave();
    //std::cout << std::endl;
}
