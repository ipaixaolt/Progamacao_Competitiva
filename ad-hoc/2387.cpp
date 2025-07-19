//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define _                    \
ios_base::sync_with_stdio(0);\
cin.tie(0);

using namespace std;

bool isMaior (const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main (void) {_
    int N; //núm. de consultas marcadas
    int resultado = 1; //Quantidade de consultas que não se sobrepõem, a primeira é garantida
    vector <pair<int, int>> consultas;


    cin >> N;

    for (int i = 0; i < N; i++) {
        int X, Y; //X = horário de início, Y = horário de término

        cin >> X >> Y;
        consultas.push_back(make_pair(X, Y));
    }

    sort(consultas.begin(), consultas.end(), isMaior); //Ordena as consultas pelo horário de término
    int termino = consultas[0].second;

    for (int i = 1; i < consultas.size(); i++)
        if(consultas[i].first >= termino) {
            resultado++;
            termino = consultas[i].second;
        }

    cout << resultado << endl;

    return 0;
}
