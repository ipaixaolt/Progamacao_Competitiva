//nomes: Isadellis Paixão, Milena Bueno
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

int fatorial(int n) {
    return (n == 1 || n == 0) ? 1 : n * fatorial(n - 1);
}

int main (void) {
    string n;
    
    while (cin >> n && n != "0") {
        int tam = n.size(), r = 0;
        for (int i = 0; i < tam; i++) r += (n[i] - '0') * fatorial(tam - i);

        cout << r << endl;
    }

    return 0;
}