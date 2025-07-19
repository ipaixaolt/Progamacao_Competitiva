// Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

const int INF = 0x3f3f3f3f;

struct Feitico {
    int d, m;
};

int n, p, memo[1010][2020];
Feitico feiticos[1010];

int dp(int i, int hp) {
    if (hp <= 0) return 0;
    if (i >= n) return INF;
    if (memo[i][hp] != -1) return memo[i][hp];

    int aux = dp(i + 1, hp - feiticos[i].d);
    return memo[i][hp] = min(dp(i + 1, hp), aux + (aux == INF ? 0 : feiticos[i].m));
}

int main (void) { _
    int r;
    while (cin >> n >> p) {
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++) cin >> feiticos[i].d >> feiticos[i].m;
        r = dp(0, p);
        cout << (r == INF ? -1 : r) << endl;
    }
    return 0;
}