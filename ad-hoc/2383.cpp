//Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

const int INF = 0x3f3f3f3f;

ll memo[35][35];
ll n, k;

ll dp () {
    ll r = 0;

    while (memo[k][r] < n) {
        r++;
        for (int i = 1; i <= k; i++)
            memo[i][r] = 1 + memo[i - 1][r - 1] + memo[i][r - 1];
    }

    return r;
}

int main(void) { _
    memset(memo, 0, sizeof memo);
    cin >> n >> k; 

    if (k > 32) k = 32;
    else if (k == 1) {
        cout << n << endl;

        return 0;
    }

    cout << dp () << endl;

    return 0;
}
