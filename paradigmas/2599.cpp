#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

const int MOD = 1000000007;

int n, m;
int radares[1005], memo[10005];

int dp(int idx) {
    if (idx >= n) return 1;
    if (memo[idx] != -1) return memo[idx];

    int r = 0;
    for (int j = 0; j < m; j++) r = (r + dp(idx + radares[j])) % MOD;
    
    return memo[idx] = r;
}

int main(void) { _
    int c;
    cin >> c;

    while (c--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) cin >> radares[i];

        memset(memo, -1, sizeof memo);

        cout << dp(0) << endl;
    }

    return 0;
}