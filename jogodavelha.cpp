#include <iostream>

using namespace std;

void createMatrix(char matrix[3][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            matrix[i][j] = '.';
        }
    }
}


bool isPossible(char table[3][3], int linha, int coluna){
    if((table[linha][coluna] == '.') && (linha >= 0 && linha < 3) && (coluna >= 0 && coluna < 3)){
        return true;
    }
    else{
        return false;
    }
}


void printMatrix(char matrix[3][3]){
    int i=0, j;
    cout << "1 2 3 \n";
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout << matrix[i][j] << " ";
        }
        cout << i + 1 << endl;
    }
    cout << endl;
}


bool checkWinner(char matrix[3][3], int linha, int coluna, char symbol){
    int i, j, counting = 0;
    for(i = 0; i < 3; i++){
        if(matrix[linha][i] == symbol){
            counting++;
        }
        if(counting == 3){
            return true;
        }
    }
    counting = 0;
    for(i = 0; i < 3; i++){
        if(matrix[i][coluna] == symbol){
            counting++;
        }
        if(counting == 3){
            return true;
        }
    }
    counting = 0;
    for(i = 0; i < 3; i++){
        if(matrix[i][i] == symbol){
            counting++;
        }
        if(counting == 3){
            return true;
        }
    }
    counting = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(j + i == 2 && matrix[i][j] == symbol){
                counting++;
            }
            if(counting == 3){
                return true;
            }
        }
    }
    return false;
}


int main(){
    char table[3][3], playersIcon[2] = {'X', 'O'}, replay = 'y';
    int play, l, c, player;
    bool ending = false;
    do{
        player = 0;
        play = 0;
        createMatrix(table);
        do{

            printMatrix(table);
            cout << "Jogada " << play + 1 << ": \n";
            cout << "Digite sua jogada: ";
            cin >> l >> c;
            if(isPossible(table, l-1, c-1)){
                table[l-1][c-1] = playersIcon[player];
                play++;
                if(player == 0){
                    player = 1;
                }
                else{
                    player = 0;
                }

            }
            else{
                cout << endl << "Jogada inválida, tente novamente!\n" << endl;
            }

            if(checkWinner(table, l-1, c-1, playersIcon[0])){
                cout << "O jogador " << playersIcon[0] << " venceu! Parabéns!\n"; 
                ending = true;
            }

            if(checkWinner(table, l-1, c-1, playersIcon[1])){
                cout << "O jogador " << playersIcon[1] << " venceu! Parabéns!\n"; 
                ending = true;
            }

            if(play == 9){
                cout << "Deu velha!\n";
                ending = true;
            }
        }while(!ending);
        cout << "Jogar novamente? [Y/n]";
        cin >> replay;
    }while(replay == 'y' || replay == 'Y');
    return 0;
}
