//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>

#define _                       \
ios_base::sync_with_stdio(0);   \
cin.tie(0);

using namespace std;

int main(void) {_
    int N; //N = dimensão das matrizes A, B e C
    int P, Q, R, S, X, Y; //Parâmentros das matrizes A e B
    int I, J; //I = linha a ser consultada, J = coluna a ser consultada
    
    cin >> N >> P >> Q >> R >> S >> X >> Y >> I >> J;

    //Calcula os valores da linha da matriz C especificada
    long long int Ci = 0;
    for (int pos = 1; pos <= N; pos++)
        Ci += ((P * I + Q * pos) % X) * ((R * pos + S * J) % Y);
    

    cout << Ci << endl;
    return 0;
}
