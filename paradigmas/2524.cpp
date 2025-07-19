#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

const int INF = 0x3f3f3f3f;

int n, m;
int memo[1005][1005], b[1005];

int dp(int i, int mod) {
    if (i == m) return (mod == 0) ? 0 : -INF;

    if (memo[i][mod] != -1) return memo[i][mod];

    return memo[i][mod] = max(dp(i + 1, mod), 1 + dp(i + 1, (mod + b[i]) % n));
}

int main(void) { _
    while (cin >> n >> m) {
        memset(memo, -1, sizeof memo);
        memset(b, 0, sizeof b);

        for (int i = 0; i < m; i++) cin >> b[i];

        cout << dp(0, 0) << endl;
    }

    return 0;
}