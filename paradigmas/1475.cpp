// Nomes: Isadellis Paixão, Milena Bueno

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

const int INF = 0x3f3f3f3f;

ll n, c, t1, t2, f[2020], memo[2020];

ll dp(int i) {
    fill(memo, memo + 2 * n, INF);
    memo[i] = 0;

    int aux;
    for (int j = i; j < i + n; j++) {
        aux = j;
        while (aux < i + n && f[aux] <= f[j] + t1) aux++;
        memo[aux] = min(memo[aux], memo[j] + t1);

        aux = j;
        while (aux < i + n && f[aux] <= f[j] + t2) aux++;
        memo[aux] = min(memo[aux], memo[j] + t2);
    }

    return memo[i + n];
}

int main(void) { _
    ll r;
    while (cin >> n >> c >> t1 >> t2) {        
        for (int i = 0; i < n; i++) cin >> f[i];
        sort(f, f + n);

        for (int i = n; i < 2 * n; i++) f[i] = f[i - n] + c;

        r = INF;

        for (int i = 0; i < n; i++) r = min(r, dp(i));
        cout << r << endl;
    }

    return 0;
}