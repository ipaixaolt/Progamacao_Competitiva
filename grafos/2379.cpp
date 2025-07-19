//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>
#include <set>
#include <vector>
#include <utility>

#define _                    \
ios_base::sync_with_stdio(0);\
cin.tie(0);

#define INF 0x3f3f3f3f

typedef long long ll;
using namespace std;

int main (void) {_
    int N, E; // N = núm. de toras, E = núm. de indígenas
    set<ll> torasIniciais;

    cin >> N >> E;

    vector<pair<int, int>> indigenas(E); // first = tora, second = sentido

    for (int i = 0; i < E; i++) {
        int V, D;

        cin >> V >> D;

        V--;
        
        torasIniciais.insert(V);
        indigenas[i] = make_pair(V, D);
    }

    ll distancia = INF;
    for (auto tora : torasIniciais) {
        set<ll> torasAtuais; //até onde os indígenas andaram para chegar na tora atual
        ll distTora = (indigenas[0].second * (tora - indigenas[0].first) + N - 1) % N + 1; //distância entre o primeiro indígena e a tora. Vide planilha

        for (int i = 0; i < E; i++)
            torasAtuais.insert((indigenas[i].first + distTora * indigenas[i].second + N) % N); //Atualiza as posições dos indígenas
    
        //Se os indígenas voltaram à mesma posição após a dança, então podemos definir a distância mínima
        if(torasIniciais == torasAtuais)
            distancia = min(distancia, distTora);
    }

    cout << distancia << endl;

    return 0;
}
