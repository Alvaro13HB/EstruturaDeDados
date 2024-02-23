#include <iostream>

using namespace std;

int main(){
    int vlMax, vlMotorista, multa;

    cout << "Digite a velocidade máxima permitida na avenida: ";
    cin >> vlMax;
    cout << "Digite a velocidade do motorista: ";
    cin >> vlMotorista;

    if(vlMotorista > vlMax){
        multa = 5 * (vlMotorista - vlMax);
    }
    else{
        multa = 0;
    }
    
    cout << "\nA multa é de R$" << multa << "." << endl;
    return 0;
}