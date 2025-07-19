#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

int memo[10005][6], n, t;
vector<int> pesos;

int dp(int id, int diferenca) {
    if (diferenca > 5) return 0;
    if (id == n) return 1;

    if (memo[id][diferenca] != -1) return memo[id][diferenca];

    return memo[id][diferenca] = dp(id + 1, diferenca + pesos[id]) || dp(id + 1, abs(diferenca - pesos[id]));
}

int main(void) { _
    cin >> t;

    while (t--) {
        cin >> n;
        
        pesos = vector<int>(n);

        for (int &peso : pesos) cin >> peso;
        
        memset(memo, -1, sizeof(memo));

        if (dp(0, 0)) cout << "Feliz Natal!" << endl;
        else cout << "Ho Ho Ho!" << endl;
    }

    return 0;
}

