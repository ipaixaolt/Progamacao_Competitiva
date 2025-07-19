//Nomes: Isadellis Paixão e Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pii pair<int, int>
#define endl "\n"

int n, q, logN;
vector<vector<pii>> tuneis;
vector<int> nivel;
vector<vector<int>> memo;
vector<vector<ll>> custo_minimo;

//https://www.geeksforgeeks.org/lca-in-a-tree-using-binary-lifting-technique/ (adaptado)
void dfs(int u, int p) { 
    memo[u][0] = p;
    for (int i = 1; i <= logN; i++)
        if (memo[u][i - 1] != -1) {
            memo[u][i] = memo[memo[u][i - 1]][i - 1];
            custo_minimo[u][i] = custo_minimo[u][i - 1] + custo_minimo[memo[u][i - 1]][i - 1];
        
        } else memo[u][i] = -1;

    for (auto [v, custo] : tuneis[u])
        if (v != p) { 
            nivel[v] = nivel[u] + 1;
            custo_minimo[v][0] = custo;
            dfs(v, u);
        }
} 

ll lca(int u, int v) { 
    ll custo_total = 0; 
    
    if (nivel[u] < nivel[v]) swap(u, v); 

    for (int i = logN; i >= 0; i--)
        if (memo[u][i] != -1 && nivel[memo[u][i]] >= nivel[v]) {
            custo_total += custo_minimo[u][i];
            u = memo[u][i];
        }

    if (u == v) return custo_total;
    for (int i = logN; i >= 0; i--)
        if (memo[u][i] != -1 && memo[u][i] != memo[v][i]) { 
            custo_total += custo_minimo[u][i] + custo_minimo[v][i];
            u = memo[u][i]; 
            v = memo[v][i]; 
        } 

    return custo_total + custo_minimo[u][0] + custo_minimo[v][0];
} 

int main(void) { _
    int a_i, l_i, s, t;
    
    while (cin >> n && n) {
        vector<ll> resposta;

        logN = log2(n) + 1; 
        tuneis.assign(n, vector<pii>());
        nivel.assign(n, 0);
        memo.assign(n, vector<int>(logN + 1, -1));
        custo_minimo.assign(n, vector<ll>(logN + 1, 0));
        
        for (int i = 1; i < n; i++) {
            cin >> a_i >> l_i;
            tuneis[a_i].push_back({i, l_i});
            tuneis[i].push_back({a_i, l_i});
        }

        dfs(0, -1);
        
        cin >> q;
        while (q--) {
            cin >> s >> t;
            resposta.push_back(lca(s, t));
        }
        
        cout << resposta[0];
        for (int i = 1; i < resposta.size(); i++) cout << ' ' << resposta[i];
        cout << endl;
    }
    return 0;
}