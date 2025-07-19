// Grupo 9: Isadellis Luísa da Paixão Teixeira, Lucas Andrade Brandão e Milena Bueno Maciel
#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

const int INF = 0x3f3f3f3f;

int n;
pair<int, int> coordenadas[16];
double memo[100005][16];

double dist(int i, int j) {
    return hypot(coordenadas[i].first - coordenadas[j].first, coordenadas[i].second - coordenadas[j].second);
}

//https://www.geeksforgeeks.org/travelling-salesman-problem-using-dynamic-programming/
double totalCost(int mask, int pos) {
    if (mask == (1 << (n + 1)) - 1) return dist(pos, 0);
    if (memo[mask][pos] != -1) return memo[mask][pos];
    
    double ans = INF;
    for (int i = 0; i < n + 1; i++)
        if ((mask & (1 << i)) == 0) ans = min(ans, dist(pos, i) + totalCost(mask | (1 << i), i));
    
    return memo[mask][pos] = ans;
}

int main (void) {_
    while (cin >> n && n) {
        fill(&memo[0][0], &memo[0][0] + 100005 * 16, -1.0);

        cin >> coordenadas[0].first >> coordenadas[0].second;
        
        for (int i = 1; i <= n; i++) cin >> coordenadas[i].first >> coordenadas[i].second; 
        
        cout << fixed << setprecision(2) << totalCost(1, 0) << endl;
    }
    return 0;
}

