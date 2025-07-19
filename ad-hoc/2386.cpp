//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>

using namespace std;

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

int main (void) {_
    int A, N; //A = área de abertura do telescópio, N = núm. de estrelas
    int resultado = 0;

    cin >> A >> N;

    for (int i = 0; i <  N; i++) {
        int F; //F = fluxo de fótons de cada estrela

        cin >> F;

        //O olho humano precisa de ao menos 40000000 fótons,sendo que o telescópio usado vai capitar F*A fótons. Verificamos se isso é o suficiente e atualizamos o contador
        if ((F * A) >= 40000000)
            resultado++;
    }

    cout << resultado << endl;

    return 0;
}
