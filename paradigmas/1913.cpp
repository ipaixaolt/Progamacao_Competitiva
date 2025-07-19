#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

const int INF = 0x3f3f3f3f;
const int MAX_N = 1005;

struct Cilindro {
    int raio, altura;
    string cor;

    bool operator <(const Cilindro &b) const {
        return raio > b.raio;
    }
};

int memo[MAX_N], n;
Cilindro cilindro[MAX_N];

bool empilha(const string &a, const string &b) {
    return !((b == "LARANJA" && a == "VERMELHO") || (b == "AZUL" && a == "LARANJA") || (b == "VERDE" && a == "AZUL") || (b == "VERMELHO" && a == "VERDE"));
}

int dp () {
    int r = 0;

    for (int i = 0; i < n; i++) {
        memo[i] = cilindro[i].altura;

        for (int j = 0; j < i; j++)
            if (cilindro[i].raio < cilindro[j].raio && empilha(cilindro[i].cor, cilindro[j].cor))
                memo[i] = max(memo[i], memo[j] + cilindro[i].altura);
    
        r = max(r, memo[i]);
    }

    return r;
}

int main(void) { _
    while (cin >> n, n) {
        for (int i = 0; i < n; i++)
            cin >> cilindro[i].altura >> cilindro[i].raio >> cilindro[i].cor;

        sort(cilindro, cilindro + n);

        cout << dp() << " centimetro(s)" << endl;
    }

    return 0;
}