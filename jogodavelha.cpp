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
bool isPossible(char posicion, int linha, int coluna){
    if((posicion == '.') && (linha > 0 && linha < 4) && (coluna > 0 && coluna < 4)){
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
    int play = 0, l, c, player = 0;
    bool win = false;

    createMatrix(table);
    do{
        printMatrix(table);
        cout << "Jogada " << play + 1 << ": \n";
        cout << "Digite sua jogada: ";
        cin >> l >> c;
        if(isPossible(table[l][c], l, c)){
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
        if(checkWinner(table, l, c, playersIcon[player])){
            cout << "O jogador " << playersIcon[player] << " venceu! Parabéns!\n"; 
            win = true;
            cout << "Jogar novamente? [Y/n]";
            cin >> replay;
        }
        if(play == 9){
            cout << "Deu velha!\n";
            cout << "Jogar novamente? [Y/n]";
            cin >> replay;
        }

    }while(replay == 'y' || replay == 'Y');
    return 0;
}