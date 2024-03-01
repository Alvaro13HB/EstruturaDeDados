#include <iostream>
using namespace std;

int main(){
    srand(time(NULL));
    char cores[4] = {'v', 'a', 'b', 'p'};
    char senha[4], palpite[4], replay;
    int jogadas = 0, acertos = 0, i, j=0;

    do{
        for(i=0; i<4; i++){
            senha[i] = cores[rand() % 4];
            if(i > 0){
                j = 0;
                do{
                    if(senha[j] == senha[i]){
                        senha[i] = cores[rand() % 4];
                        j = 0;
                    }
                    else{
                        j++;
                    }
                }while(j < i);
            }
        } 

        jogadas = 0, acertos = 0;
        while((jogadas < 10) && (acertos < 4)){
            cout << "Jogada: " << jogadas+1 << endl;
            cout << "informe seu palpite\n";
            cout << "v - vermelho | a - azul | p - preto | b - branco\n";
            for(i=0; i < 4; i++){
                cin >> palpite[i];
            }
            cout << "\n";
            acertos = 0;
            for(i=0; i < 4; i++){
                if(palpite[i] == senha[i]){
                    acertos++;
                }
            }
            cout << "Você acertou " << acertos << " cores\n";
            jogadas++;
        }


        if(acertos == 4){
            cout << "Parabéns, você venceu!!!\n";
        }
        else{
            cout << "Que pena você perdeu! a senha gerada foi: ";
            for(i=0; i<4; i++){
                cout << senha[i] <<" ";
            }
            cout << "\n";
        }

        cout << "Jogar novamente? [Y/n]";
        cin >> replay;
        cout << "\n";

    }while(replay == 'y' || replay == 'Y');
    return 0;
}