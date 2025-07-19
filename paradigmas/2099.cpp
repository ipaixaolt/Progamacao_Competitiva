// Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

int n;
int memo[1001][1001][2];

int dp(int resto, int max_tam, int f) {
    if (resto == 0) return (f == 0);
    if (max_tam == 0) return 0;

    if (memo[resto][max_tam][f] != -1) 
        return memo[resto][max_tam][f];

    int res = dp(resto, max_tam - 1, f);
    if (resto >= max_tam) res = (res + dp(resto - max_tam, max_tam, f ^ 1)) % 1000000007;

    return memo[resto][max_tam][f] = res;
}

int main (void) { _
    cin >> n;

    memset(memo, -1, sizeof(memo));

    cout << dp(n, n, (n % 2) ^ 1) << endl;

    return 0;
}
