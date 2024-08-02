#include <iostream>

using namespace std;

const int TAM = 20;


void gerarVetor(int vet1[], int vet2[]){
    for(int i = 0;i < TAM; i++){
        vet1[i] = rand() % 100 + 1;
        vet2[i] = vet1[i];
    }
}


void metodoBolha(int vet[], int *trocas, int *comps){
    int aux;
    for(int i = 0;i < TAM; i++){
        for(int j = 0; j < TAM-1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                (*trocas)++;
            }
            (*comps)++;
        }
    }
}


void metodoBolhaM(int vet[], int *trocas, int *comps){
    int aux, i = 0;
    bool troca = true;
    while(i < TAM && troca){
        troca = false;
        for(int j = 0; j < TAM-1; j++){
            if(vet[j] > vet[j+1]){
                troca = true;
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
                (*trocas)++;
            }
            (*comps)++;
        }
    }
}


int main(){
    srand(time(NULL));
    int vetor1[20], vetor2[20], trocas1 = 0, trocas2 = 0, comparacoes1 = 0, comparacoes2 = 0;

    for(int i = 0; i < 10; i++){
        gerarVetor(vetor1, vetor2);

        metodoBolha(vetor1, &trocas1, &comparacoes1);
        metodoBolhaM(vetor2, &trocas2, &comparacoes2);
    }

    cout << "Método Bolha: " << endl;
    cout << trocas1 / 10 << " " << comparacoes1 / 10 << endl;
    cout << endl << "Método Bolha Melhorado: " << endl;
    cout << trocas2 / 10 << " " << comparacoes2 / 10 << endl;
    return 0;
}