#include <iostream>


const int TAM{30};


void bolhaM(int vet[], int *trocas, int *comps){
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
                (*trocas)++;
            }
        (*comps)++;
        }
    }
}


void metodoInsercao(int vet[], int *trocas, int *comps){
    int aux, j;
    for(int i{}; i < TAM; i++){
        aux = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > aux){
            vet[j+1] = vet[j];
            (*comps)++;
            (*trocas)++;
            j--;
        }
        (*trocas)++;
        vet[j+1] = aux;
    }
}


void metodoSelecao(int vet[], int *trocas, int *comps){
    int min, aux;
    for(int i{}; i < TAM-1; i++){
        min = i;
        for(int j = i + 1; j < TAM; j++){
            if(vet[min] > vet[j]){
                min = j;
            }
            (*comps)++;
        }
        (*trocas)++;
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}


void gerarVetor(int vet1[], int vet2[], int vet3[]){
    for(int i{}; i < TAM; i++){
        vet1[i] = rand() % 100 + 1;
        vet2[i] = vet1[i];
        vet3[i] = vet2[i];
    }
}


int main(){
    srand(time(NULL));
    int vetor1[TAM], vetor2[TAM], vetor3[TAM], trocas1 = 0, trocas2 = 0, trocas3 = 0,
        comparacoes1 = 0, comparacoes2 = 0, comparacoes3, trocas_aux1 = 0,
        trocas_aux2 = 0, trocas_aux3 = 0, comps_aux1 = 0, comps_aux2 = 0, comps_aux3 = 0;

    for(int i{1}; i <= 10; i++){
        gerarVetor(vetor1, vetor2, vetor3);

        bolhaM(vetor1, &trocas1, &comparacoes1);
        metodoInsercao(vetor2, &trocas2, &comparacoes2);
        metodoSelecao(vetor3, &trocas3, &comparacoes3);
        std::cout << i << "º Rodada: " << trocas1 << " " << comparacoes1 << " | "
                  <<  trocas2 << " " << comparacoes2 << " | "
                  <<  trocas3 << " " << comparacoes3 << std::endl;
        trocas_aux1 += trocas1;
        trocas_aux2 += trocas2;
        trocas_aux3 += trocas3;
        trocas1 = trocas2 = trocas3 = 0;
        comps_aux1 += comparacoes1;
        comps_aux2 += comparacoes2;
        comps_aux3 += comparacoes3;
        comparacoes1 = comparacoes2 = comparacoes3 = 0;
    }

    std::cout << std::endl << "Método Bolha Melhorado: " << std::endl;
    std::cout << trocas_aux1 / 10 << " " << comps_aux1 / 10 << std::endl;
    std::cout << "Método Inserção: " << std::endl;
    std::cout << trocas_aux2 / 10 << " " << comps_aux2 / 10 << std::endl;
    std::cout << "Método Seleção: " << std::endl;
    std::cout << trocas_aux3 / 10 << " " << comps_aux3 / 10 << std::endl;

    return 0;
}