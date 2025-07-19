//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>
#include <cmath>

#define _ \
ios_base::sync_with_stdio(0); \
cin.tie(0);

using namespace std;

typedef unsigned long long ull;

int main(void) {_
    int N; //Número total de árvores

    cin >> N;

    ull limite = sqrt(N / 2); //Maior número de colunas que teremos 

    ull resultado = 0;
    for (ull i = 1; i <= limite; i++) {
        ull arvoresPorLinha = 3*i+2; //Quantidade de árvores que cada linha terá
        ull faltam = N - arvoresPorLinha; //Quantas árvores que faltam para serem plantadas
        
        arvoresPorLinha -= (i + 1); //Remove a quantidade de árvores compartilhadas entre 2 linhas

        if(faltam % arvoresPorLinha == 0)
            resultado++;
    }

   cout << resultado << endl;

    return 0;
}
