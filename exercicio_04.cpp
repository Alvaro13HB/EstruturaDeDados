#include <iostream>

using namespace std;

int main(){
    int a, b, x, y, z;

    do{
        cout << "Informe 'a' e 'b': ";
        cin >> a >> b;
    }while(b < a);

    do{
        cout << "Informe 'z': ";
        cin >> z;
    }while(z <= b);

    for(x = a; x < b; x++){
        for(y = x + 1; y <= b; y++){
            if(x + y == z){
                cout << z << " = " << x << " + " <<  y << ".\n";
            }
        }
    }
    return 0;
}