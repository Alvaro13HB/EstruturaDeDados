#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int vet[30], i = 0, numero, tem = 0;

    srand(time(0));
    for(i = 0; i < 30; i++){
        vet[i] = (rand() % 100) + 1;
    }


    cout << "Digite um número inteiro: ";
    cin >> numero;
    for(i = 0; i < 30; i++){
        if(vet[i] == numero){
            cout << i+1 << "ª posição." << endl;
            tem = 1;
        }
    }
    if(tem == 0){
        cout << "Valor não encontrado" << endl;
    }


    for(i = 0; i < 29; i++){
        cout << vet[i] << ", ";
    }
    cout << vet[29] << endl;


    return 0;
}
