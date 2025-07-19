#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

map<string, string> apaixonados;
map<string, int> vis;

int bfs () {
    int qt = 0;

    for (auto &[p, ama] : apaixonados) {
        if (vis[p]) continue;
        queue<string> fila;
        set<string> ciclo;
        
        fila.push(p);
        vis[p] = true;

        while (!fila.empty()) {
            string u = fila.front();
            fila.pop();
            ciclo.insert(u);
            
            if (!apaixonados.count(u)) continue;
            string v = apaixonados[u];
            
            if (ciclo.count(v)) {
                qt++;
                break;
            }
            
            if (vis[v]) continue;
            
            fila.push(v);
            vis[v] = true;
        }
    }
    return qt;
}

int main (void) {_
    string a, b;

    while (cin >> a >> b) {
        apaixonados[a] = b;
        vis[a] = vis[b] = 0;
    }
    
    cout << bfs() << endl;
    return 0;
}

