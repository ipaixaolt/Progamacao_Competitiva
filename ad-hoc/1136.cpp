// Nomes: Isadellis Paixão e Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

int main() { _
    int n, b;

    while ((cin >> n >> b) && (n || b)) {
        vector<int> bolas(b);
        vector<int> val(n + 1, 0);
        short isPossivel = 1;

        for (int &b_i : bolas) cin >> b_i;

        for (int i = 0; i < b; i++)
            for (int j = i; j < b; j++)
                val[abs(bolas[i] - bolas[j])] = 1;
        
        for (int i = 0; i <= n; i++)
            if (val[i] == 0) {
                isPossivel = 0;
                break;
            }

        cout << (isPossivel ? 'Y' : 'N') << endl;
    }
    return 0;
}