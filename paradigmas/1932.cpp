#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

const int INF = 0x3f3f3f3f;
const int MAX_N = 200005;

int n, c;
int p[MAX_N], memo[MAX_N][2];

int dp() {
    memo[0][0] = 0;
    memo[0][1] = -p[0] - c;

    for (int i = 1; i < n; i++) {
        memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + p[i]); 
        memo[i][1] = max(memo[i - 1][1], memo[i - 1][0] - p[i] - c);
    }

    return memo[n - 1][0];
}

int main (void) {_
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> p[i];

    cout << dp() << endl;

    return 0;
}