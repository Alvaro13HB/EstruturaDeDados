#include <iostream>

using namespace std;

int main(){
    int i, j, isPrimo;
    for(i=100; i <= 500; i++){
        isPrimo = 1;
        for(j=2; j < i; j++){
            if(i % j == 0){
                isPrimo = 0;
                j = i;
            }
        }
        if(isPrimo == 1){
            cout << i << " ";
        }
    }
    return 0;
}