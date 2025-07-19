#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

const int INF = 0x3f3f3f3f;

int n;
int memo[45][805][805], ticket_verde[45], ticket_azul[45];

int dp(int i, int v, int a) {
    if (i == n) return 0;
    if (memo[i][v][a] != -1) return memo[i][v][a];

    int aux = dp(i + 1, v, a);

    if (v + ticket_verde[i] >= 0 && a + ticket_azul[i] >= 0) {
        aux = max(aux, 1 + dp(i + 1, v + ticket_verde[i], a + ticket_azul[i]));
    }

    return memo[i][v][a] = aux;
}

int main(void) { _
    int v, a;
    while (cin >> n) {
        memset(memo, -1, sizeof memo);
        memset(ticket_verde, 0, sizeof ticket_verde);
        memset(ticket_azul, 0, sizeof ticket_azul);

        cin >> v >> a;
        for (int i = 0; i < n; i++) cin >> ticket_verde[i] >> ticket_azul[i];

        cout << dp(0, v, a) << endl;
    }

    return 0;
}