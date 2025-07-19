// Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

int n, m, q, s;
vector<vector<int>> quadrados, pref;

int main(void) { _
    cin >> n >> m;
    
    quadrados = pref = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> quadrados[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (quadrados[i][j] == 0);
        }

    cin >> q;
    while (q--) {
        cin >> s;
        int encontrou = false;

        for (int i = s; i <= n && !encontrou; i++)
            for (int j = s; j <= m; j++) {
                int qtd_zeros = pref[i][j] - pref[i - s][j] - pref[i][j - s] + pref[i - s][j - s];
                if (qtd_zeros == 0) {
                    encontrou = 1;
                    break;
                }
            }

        cout << (encontrou ? "yes" : "no") << endl;
    }

    return 0;
}