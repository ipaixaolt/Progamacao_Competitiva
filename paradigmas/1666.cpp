// Nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

string s;
int memo[205][205], n;

int isConjunto(int i, int j);

int isAtomo(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = (s[i] == '{' || s[i] == '}' || s[i] == ',');
}

int isElemento(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = (i == j) ? isAtomo(i, j) : isConjunto(i, j);
}

int isLista(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    if (isElemento(i, j)) return memo[i][j] = 1;

    for (int k = i + 1; k < j; k++)
        if (s[k] == ',' && isElemento(i, k - 1) && isLista(k + 1, j)) {
            return memo[i][j] = 1;
        }
    return memo[i][j] = 0;
}

int isConjunto(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = (s[i] == '{' && s[j] == '}' && (i + 1 > j - 1 || isLista(i + 1, j - 1)));
}

int main(void) {_
    cin >> n;
    cin.ignore();
    
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        memset(memo, -1, sizeof(memo));
        
        cout << "Word #" << i << ": " << (isConjunto(0, s.size() - 1) ? "Set" : "No Set") << endl;
    }
    
    return 0;
}