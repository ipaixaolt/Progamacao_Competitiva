//Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define dgb(x) cout << #x << " = " << x << endl;
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PB push_back

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1000000007;

string n, seq;
ull memo[100001];

bool checa(string sub) {
    return (sub[0] != '0') && (sub.length() < n.length() || (sub.length() == n.length() && sub <= n));
}

ull dp(int b) {
    if (memo[b] != -1) return memo[b];
    if (seq[b] == '0') return memo[b] = 0;

    ull qt = 0;
    for (int i = b + 1; i <= seq.size(); i++) {
        string sub = seq.substr(b, i - b);
        if (!checa(sub)) break;
        qt = (qt + memo[i]) % MOD;
    }

    return memo[b] = qt;
}

int main (void) { _
    cin >> n >> seq;

    memset(memo, -1, sizeof(memo));
    memo[seq.size()] = 1;

    for (int i = seq.size() - 1; i >= 0; i--) dp(i);
    
    cout << memo[0] << endl;

    return 0;
}

