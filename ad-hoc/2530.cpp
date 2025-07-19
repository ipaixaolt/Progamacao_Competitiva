// Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

int n, m;
int s[100005], r[100005];

int main(void) { _
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < m; i++) cin >> r[i];

        int idx = 0;
        for (int i = 0; i < n && idx < m; i++) 
            if (s[i] == r[idx]) idx++;

        cout << (idx == m ? "sim" : "nao") << endl;
    }

    return 0;
}