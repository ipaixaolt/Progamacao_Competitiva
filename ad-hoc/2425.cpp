#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define dgb(x) cout << #x << " = " << x << endl;
#define ll long long
#define uint unsigned int
#define MP make_pair
#define PB push_back
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int caixas[11], c, n, resposta, disponiveis, t, d;

int main (void) {_
    cin >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> d;

        disponiveis = 0;
        for (int i = 1; i < c; i++)
            if (caixas[i] < caixas[disponiveis]) disponiveis = i;
        
        if (t > caixas[disponiveis])
            caixas[disponiveis] = t + d;
        else {
            if (caixas[disponiveis] - t > 20) resposta++;
            caixas[disponiveis] += d;
        }
    }
    printf("%d\n", resposta);
    return 0;
}
