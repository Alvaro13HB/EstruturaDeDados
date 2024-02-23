#include <iostream>

using namespace std;

int main(){
    int timeA, timeB, palpiteA, palpiteB, pontos=0;

    cout << "Informe o placar do jogo: ";
    cin >> timeA >> timeB;
    cout << "Informe seu palpite: ";
    cin >> palpiteA >> palpiteB;

     if((timeA >= timeB && palpiteA >= palpiteB) || (timeA < timeB && palpiteA < palpiteB)){
        pontos += 10;
    }
    if (timeA == palpiteA){
        pontos += 5;
    }
    if (timeB == palpiteB){
        pontos += 5;
    }

    cout << "Você marcou " << pontos << " pontos." << endl;
    return 0;
}