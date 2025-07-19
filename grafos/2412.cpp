//Milena Bueno, Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define pii pair<int, int>
#define ll long long
#define endl "\n"

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 1005;

pii arvore[MAXN];
int parent[MAXN];
int tam[MAXN];

//https://cp-algorithms.com/data_structures/disjoint_set_union.html
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    tam[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (tam[a] < tam[b]) swap(a, b);
        parent[b] = a;
        tam[a] += tam[b];
    }
}

ll dist(pii a, pii b) {
    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);
}

int main (void) { _
    int n, d;
    cin >> n >> d;
    d *= d;

    for (int i = 0; i < n; i++) {
        cin >> arvore[i].first >> arvore[i].second;
        make_set(i);
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist(arvore[i], arvore[j]) <= d) union_sets(i, j);


    int raiz = find_set(0);
    for (int i = 1; i < n; i++)
        if (find_set(i) != raiz) {
            cout << 'N' << endl;
            return 0;
        }

    cout << 'S' << endl;
    return 0;
}

