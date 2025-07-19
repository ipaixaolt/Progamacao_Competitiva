#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

int r, k;
int memo[105][5000], ligacoes[105];

int dp(int regiao, int ponte) {
    if (ponte > k) return 0;
    if (regiao > r) return (ponte == k);
    if (memo[regiao][ponte] != -1) return memo[regiao][ponte];

    return memo[regiao][ponte] = dp(regiao + 1, ponte) || dp(regiao + 1, ponte + ligacoes[regiao]);
}

int main(void) { _
    int a, b;
    while (cin >> r >> k) {
        memset(memo, -1, sizeof memo);
        memset(ligacoes, 0, sizeof ligacoes);

        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            ligacoes[a]++;
            ligacoes[b]++;
        }

        cout << (dp(1, 0) ? 'S' : 'N') << endl;
    }

    return 0;
}