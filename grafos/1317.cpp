//Grupo 9: Isadellis Luísa da Paixão Teixeira, Lucas Andrade Brandão e Milena Bueno Maciel
#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define endl '\n'
#define dbg(x) cout << #x << '=' << x << endl;

vector<tuple<int, int, int, string, string, string>> spams;
vector<vector<string>> adjetivos;
vector<vector<int>> amigos;
vector<string> nomes;
vector<int> vis;
int n;

void bfs(int o) {
    int v, u;
    queue<int> q;
    
    q.push(o), vis[o] = 1;
    
    while (!q.empty()) {
        u = q.front();
        q.pop();
        
        for (int v : amigos[u]) {
            if (vis[v]) continue;
            else vis[v] = 1;
            q.push(v);
        }
    }
}

int main (void) {_
    int aux, t1, t2;
    string a1, a2, a3;
    
    while (cin >> n && n) {
        amigos.assign(n, vector<int>());
        adjetivos.assign(n, vector<string>());
        nomes.assign(n, "");
        spams.clear();
        
        // Lendo amigos
        for (int i = 0; i < n; i++)
            while (cin >> aux && aux) amigos[i].pb(aux - 1);
        
        // Lendo spams
        while (cin >> aux && aux) {
            cin >> t1 >> t2 >> a1 >> a2 >> a3;
            spams.pb({aux - 1, t1, t2, a1, a2, a3});
        }
        
        // Lendo nomes
        for (int i = 0; i < n; i++) {
            cin >> nomes[i];
        }
        
        for (auto &[p, t1, t2, a1, a2, a3] : spams) {
            vis.assign(n, 0);
            bfs(p);
            
            for (int i = 0; i < n; i++) {
                aux = amigos[i].size();
                if (!vis[i] || aux < t1) adjetivos[i].pb(a1);
                else if (aux < t2) adjetivos[i].pb(a2);
                else adjetivos[i].pb(a3);
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << nomes[i] << ": ";
                for (int j = 0; j < adjetivos[i].size(); j++) cout << adjetivos[i][j] << " ";
                
                cout << endl;
        }
    }
    
    return 0;
}

