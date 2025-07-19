#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define pii pair<int, int>
#define ll long long

const int INF = 0x3f3f3f3f;

int memo[1005][3605];
vector<pii> v;
int n;


int dp(int idx, int fim_intervalo) {
    if (idx == n) return 0;
    if (memo[idx][fim_intervalo] != -1) return memo[idx][fim_intervalo];

    if (fim_intervalo > v[idx].first) return memo[idx][fim_intervalo] = dp(idx + 1, fim_intervalo);
    
    return memo[idx][fim_intervalo] = max((v[idx].second - v[idx].first) + dp(idx + 1, v[idx].second), dp(idx + 1, fim_intervalo));
}

int main(void) { _
    memset(memo, -1, sizeof memo);
    cin >> n;

    v = vector<pii>(n);
    for (pii &i : v) cin >> i.first >> i.second;

    sort(v.begin(), v.end());

    cout << dp(0,0) << endl;

    return 0;
}