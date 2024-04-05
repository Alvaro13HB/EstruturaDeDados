#include <iostream>

using namespace std;

string sortearPalavra(string dicionario[20]){
    srand(time(NULL));
    return dicionario[rand() % 20];
}

string esconderPalavra(string palavra){
    string palavraEscondida;
    for(int i = 0; i < palavra.length(); i++){
        palavraEscondida += '-';
    }
    return palavraEscondida;
}

string atualizarEscondida(string palavra, string escondida, char palpite, bool *checar){
    *checar = false;
    for(int i = 0; i < palavra.length(); i++){
        if(palavra[i] == palpite){
            *checar = true;
            escondida[i] = palpite;
        }
    }
    return escondida;
}

void exibirJogo(string escondida, string palpites, int tentativas){
    cout << escondida << endl;
    cout << palpites << endl;
    cout << "Restam " << tentativas << " tentativas.\n" << endl;
    cout << "Dê um palpite: ";
}



int main(){
    string dicionario[20] = {"sabado", "maiden", "uva", "pneumoultramicroscopicosilicovulcanoconiotico", "domingo",
                             "metal", "massacration", "gibson", "vazio", "astronauta",
                             "gentilico", "temperamental", "powerslave", "contrabaixo", "guitarra",
                             "bateria", "camundongo", "guaxinim", "senjutsu", "killers"};

    string escondida, palavra, palpites;
    char letra, repetir = 'S';
    bool checar;
    bool vitoria;
    int tentativas;

    do{
        system("clear");
        palpites = " ";
        tentativas = 7;
        vitoria = false;
        palavra = sortearPalavra(dicionario);
        escondida = esconderPalavra(palavra);

        do{
            exibirJogo(escondida, palpites, tentativas);
            cin >> letra;
            palpites += letra;
            palpites += ' ';
            escondida = atualizarEscondida(palavra, escondida, letra, &checar);
            if(!checar){
                tentativas--;
            }
            if(palavra == escondida){
                vitoria = true;
            }
        }while(tentativas > 0 && !vitoria);
        if(vitoria){
            cout << "Parabéns, você acertou!\n";
        }
        else{
            cout << "Que pena, mais sorte na próxima.\n";
        }
        cout << "A palavra era " << palavra << ".\n\n";

        cout << "Deseja tentar novamente? [S/n] ";
        cin >> repetir;
    }while(repetir == 'S' || repetir == 's');
    return 0;
}