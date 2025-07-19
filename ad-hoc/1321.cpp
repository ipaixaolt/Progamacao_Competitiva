// Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl;
#define endl "\n"

int main(void) {_
    int princesa[3], principe[2], baralho[52], possibilidade[3];

    while ((cin >> princesa[0] >> princesa[1] >> princesa[2] >> principe[0] >> principe[1]) &&
           (princesa[0] || princesa[1] || princesa[2] || principe[0] || principe[1])) {
        
        memset(baralho, 0, sizeof baralho);
        baralho[princesa[0] - 1] = baralho[princesa[1] - 1] = baralho[princesa[2] - 1] = 1;
        baralho[principe[0] - 1] = baralho[principe[1] - 1] = 1;

        // Ordenamos corretamente as cartas
        sort(princesa, princesa + 3);
        sort(principe, principe + 2);

        if ((princesa[0] > principe[0] && princesa[1] > principe[1]) || (princesa[1] > principe[0] && princesa[2] > principe[1])) {
            cout << -1 << endl;
            continue;
        }

        int resposta = -1;

        for (int i = 0; i < 52; i++) {
            possibilidade[0] = principe[0];
            possibilidade[1] = principe[1];

            if (!baralho[i]) { 
                baralho[i] = 1;

                possibilidade[2] = i + 1;
                sort(possibilidade, possibilidade + 3);

                int aux = 0;
                if (possibilidade[2] > princesa[0]) aux++;
                if (possibilidade[1] > princesa[2]) aux++;
                if (possibilidade[0] > princesa[1]) aux++;

                if (aux >= 2) {
                    resposta = i + 1;
                    break;
                }
            }
        }

        cout << resposta << endl;
    }

    return 0;
} 