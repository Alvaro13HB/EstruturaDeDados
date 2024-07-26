#include <iostream>

using namespace std;


float potencia(float b, float e){
    float resultado = 1;
    if(e == 0)
        return resultado;
    if(e < 0)
        b = 1 / b;
        e = -e;
    for(int i = 0; i < e; i++)
        resultado *= b;
    return resultado;
}


float log(float a, float b){
    int i = 0, potencia = 1;
    while(potencia < a){
        potencia *= b;
        i++;
    }
    if(potencia == a){
        return i;
    }
    return 0;
}


bool palindromo(string palavra){
    int aux = 0;
    string palavra_inversa = palavra;
    for(int i = 0; i < palavra.length(); i++){
        palavra_inversa[i] = palavra[palavra.length() - i - 1];
    }
    for(int j = 0; j < palavra.length(); j++){
        if(palavra[j] == palavra_inversa[j]){
            aux++;
        }
    }
    if(aux == palavra.length()){
        return true;
    }
    return false;
}


void printarMenu(){
    cout << "O que deseja?" << endl;
    cout << "1 - Potenciação;" << endl;
    cout << "2 - Logarítmo;" << endl;
    cout << "3 - Teste de palindromia." << endl;
    cout << endl;
}


int main(){
    char repetidor = 's';
    int escolha;
    do{

        printarMenu();
        cin >> escolha;
        switch(escolha){
            case(1):
                cout << "Defina os valores: ";
                int base, expoente;
                cin >> base >> expoente;
                cout << endl << potencia(base, expoente) << endl;
                break;

            case(2):
                cout << "Defina os valores: ";
                int a, b;
                cin >> a >> b;
                cout << endl << log(a, b) << endl;
                break;
            
            case(3):
                cout << "Digite a palavra: ";
                string palavra;
                cin >> palavra;
                if(palindromo(palavra)){
                    cout << "É palíndromo!" << endl;
                }
                else{
                    cout << "Não é palíndromo!" << endl;
                }
                break;
        }
        cout << endl << "Repetir?[S/n] ";
        cin >> repetidor;
        cout << endl;
    }while(repetidor == 's' || repetidor == 'S');
    return 0;
}