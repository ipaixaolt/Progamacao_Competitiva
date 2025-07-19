// Grupo 9: Isadellis Luísa da Paixão Teixeira, Lucas Andrade Brandão e Milena Bueno Maciel

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

//https://codeforces.com/blog/entry/43230
const int MAXN = 100005;
const int MAXM = 100005;
const int LOGN = 21;

int n, m, cur, LVL[MAXN], DP[LOGN][MAXN];
int l[MAXN], r[MAXN], ID[MAXN << 1], timer = 0;
bool VIS[MAXN];
vector<int> adj[MAXN], euler;
map<string, int> presenteMap;
int presentes[MAXN], ANS[MAXM], VAL[MAXN];
vector<int> freq, vis;
int distinct = 0;

struct query {
    int id, l, r, lc;
    bool operator<(const query &rhs) {
        int blockA = l / 316, blockB = rhs.l / 316;
        return (blockA == blockB) ? ((blockA & 1) ? (r > rhs.r) : (r < rhs.r)) : (blockA < blockB);
    }
} Q[MAXM];

void dfs(int u, int par) {
    l[u] = ++timer;
    ID[timer] = u;
    euler.push_back(u);
    DP[0][u] = (par == -1 ? u : par);
    for (int i = 1; i < LOGN; i++) {
        DP[i][u] = DP[i - 1][DP[i - 1][u]];
    }
    for (int v : adj[u]) {
        if (v == par) continue;
        LVL[v] = LVL[u] + 1;
        dfs(v, u);
    }
    r[u] = ++timer;
    ID[timer] = u;
    euler.push_back(u);
}

void buildLCA() {
    timer = 0;
    euler.clear();
    dfs(1, -1);
    for (int k = 1; k < LOGN; k++) {
        for (int i = 1; i <= n; i++) {
            DP[k][i] = DP[k - 1][DP[k - 1][i]];
        }
    }
}

int lca(int u, int v) {
    if (LVL[u] > LVL[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--)
        if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--)
        if (DP[i][u] != DP[i][v]) {
            u = DP[i][u];
            v = DP[i][v];
        }
    return DP[0][u];
}

inline void toggle(int pos) {
    int v = ID[pos];
    int id = presentes[v];
    if (vis[v]) {
        if (freq[id] == 1)
            distinct--;
        freq[id]--;
        vis[v] = false;
    } else {
        if (freq[id] == 0)
            distinct++;
        freq[id]++;
        vis[v] = true;
    }
}

void compute() {
    int curL = 0, curR = -1;
    distinct = 0;
    freq.assign(presenteMap.size(), 0);
    vis.assign(n + 1, false);
    vector<int> ans(m, 0);
    sort(Q, Q + m);
    for (int i = 0; i < m; i++) {
        while (curR < Q[i].r) toggle(++curR);
        while (curR > Q[i].r) toggle(curR--);
        while (curL < Q[i].l) toggle(curL++);
        while (curL > Q[i].l) toggle(--curL);
        if (Q[i].lc != -1 && (Q[i].lc != ID[Q[i].l] && Q[i].lc != ID[Q[i].r])) toggle(l[Q[i].lc]);
        ans[Q[i].id] = distinct;
        if (Q[i].lc != -1 && (Q[i].lc != ID[Q[i].l] && Q[i].lc != ID[Q[i].r])) toggle(l[Q[i].lc]);
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}

int main (void) {_
    cin >> n >> m;
    string presente;
    int idCounter = 0;
    for (int i = 1; i <= n; i++) {
        cin >> presente;
        if (presenteMap.find(presente) == presenteMap.end()) 
            presenteMap[presente] = idCounter++;
        presentes[i] = presenteMap[presente];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    buildLCA();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Q[i].lc = lca(u, v);
        if (l[u] > l[v]) swap(u, v);
        if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
        else Q[i].l = r[u], Q[i].r = l[v];
        Q[i].id = i;
    }
    compute();
}

