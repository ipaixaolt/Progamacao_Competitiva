// Grupo 9: Isadellis Luísa da Paixão Teixeira, Lucas Andrade Brandão e Milena Bueno Maciel
#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

//https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/kosaraju.html
vector<vector<int>> g, gInverso;
int v, e, tempo, comp;
int compConexa[5005], grauSaida[5005], vis[5005], ordem[5005];
stack<int> s;

void dfs1(int u) {
    vis[u] = 1;
    for (int prox : g[u])
        if (!vis[prox]) dfs1(prox);
    s.push(u);
}

void dfs2(int u, int comp) {
    vis[u] = 1;
    compConexa[u] = comp;
    for (int prox : gInverso[u]) {
        if (!vis[prox]) dfs2(prox, comp);
    }
}

int main (void) {_
    while (cin >> v && v) {
        cin >> e;
        g.assign(v + 1, vector<int>());
        gInverso.assign(v + 1, vector<int>());
        memset(compConexa, 0, sizeof compConexa);
        memset(grauSaida, 0, sizeof grauSaida);
        memset(vis, 0, sizeof vis);

        int v1, w1;
        for (int i = 0; i < e; i++) {
            cin >> v1 >> w1;
            g[v1].push_back(w1);
            gInverso[w1].push_back(v1);
        }

        for (int i = 1; i <= v; i++)
            if (!vis[i]) dfs1(i);
        

        memset(vis, 0, sizeof vis);
        comp = 0;
        while (!s.empty()) {
            int u = s.top(); s.pop();
            if (!vis[u]) dfs2(u, comp++);
        }

        for (int i = 1; i <= v; i++)
            for (int prox : g[i])
                if (compConexa[i] != compConexa[prox]) grauSaida[compConexa[i]]++;

        set<int> solucao;
        for (int i = 1; i <= v; i++)
            if (grauSaida[compConexa[i]] == 0) solucao.insert(i);
        
        if (!solucao.empty()) cout << *solucao.begin();
        for (auto it = next(solucao.begin()); it != solucao.end(); it++) cout << " " << *it;
        cout << endl;
    }
    return 0;
}

