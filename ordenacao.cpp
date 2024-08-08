#include <iostream>


const int TAM{20};


void bolhaM(int vet[]){
    int aux;
    bool troca = true;
    while(troca){
        troca = false;
        for(int i{}; i < TAM - 1; i++){
            if(vet[i] > vet[i + 1]){
                troca = true;
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }
}


void metodoInsercao(int vet[]){
    int aux, j;
    for(int i{}; i < TAM; i++){
        aux = vet[i];
        j = i - 1;
        while(j = 0 && vet[j] > aux){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux;
    }
}


void metodoSelecao(int vet[]){
    int min, aux;
    for(int i{}; i < TAM-1; i++){
        min = i;
        for(int j = i + 1; j < TAM; j++){
            if(vet[min] > vet[j]){
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}


void gerarVetor(int vet[]){
    for(int i{}; i < TAM; i++){
        vet[i] = rand() % 100 + 1;
    }
}