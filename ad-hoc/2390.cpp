//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>

using namespace std;

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

int main (void) {_
    int N; //N = núm. de pessoas que o sensor detectou
    int aux;
 
    cin >> N >> aux;

    int tempoLigada = 10; //A primeira pessoa já fez a escada rolar

    for (int i = 1; i < N; i++) {
        int T;

        cin >> T;

        /*  Se a pessoa atual entrou a menos de 10 segundos que a pessoa anterior, então adicionamos esse intervalo,
            caso contrário a escada foi desligada e precisamos contar mais 10 segundos 
        */
        tempoLigada += min(10, T - aux); 
        aux = T;
    }

    cout << tempoLigada << endl;
    return 0;
}
