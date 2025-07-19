//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

using namespace std;

int main (void) {_
    int N, C, S, E; //N = núm. leituras, C = capacidade, S = quant. pessoas saíram, E = quant. pessoas entraram
    int qtPessoas = 0;
    bool excedeu = false;

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> S >> E;
        
        qtPessoas += E - S;

        //Se excedeu em algum momento, marcamos como verdadeiro
        excedeu = excedeu || (qtPessoas > C);
    }

    cout << (excedeu ? 'S' : 'N') << endl;

    return 0;
}
