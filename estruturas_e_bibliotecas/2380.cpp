//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>
#include <vector>

using namespace std;

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

using namespace std;

//Disjoint Set (Union-Find Algorithm), union by size, disponível em: https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/ 

//Encontra a raiz de um elemento
int busca(vector<int>& fusoes, int p) {
    while (p != fusoes[p])
        p = fusoes[p];
    return p;
}

//Une dois conjuntos
void unionSets(vector<int>& fusoes, vector<int>& tamamho, int p, int q) {
    int raizP = busca(fusoes, p);
    int raizQ = busca(fusoes, q);
    
    if (raizP == raizQ) return; // Se já estão no mesmo conjunto
    
    // Anexa a árvore menor à raiz da maior
    if (tamamho[raizP] < tamamho[raizQ]) {
        fusoes[raizP] = raizQ;
        tamamho[raizQ] += tamamho[raizP];
    } else {
        fusoes[raizQ] = raizP;
        tamamho[raizP] += tamamho[raizQ];
    }
}

int main (void) {_
    int N , b; //N = núm. de bancos, b = núm. de operações
    
    cin >> N >> b;

    vector<int> fusoes(N);
    vector<int> tamanhos(N, 1); //Inicialmente, cada árvore tem tamanho 1, pois cada elemento será sua própria raiz

    for (int i = 0; i < N; i++)
        fusoes[i] = i;

    for(int i = 0; i < b; i++) {
        char op;
        int bancoA, bancoB;

        cin >> op >> bancoA >> bancoB;
        bancoA--, bancoB--;

        if (op == 'C')
            if (busca(fusoes, bancoA) == busca(fusoes, bancoB)) //Se ambos os bancos pertencerem à mesma empresa, então são fusões
                cout << 'S' << endl;
            else
                cout << 'N' << endl;
        else
            unionSets(fusoes, tamanhos, bancoA, bancoB);
    }

    return 0;
}
