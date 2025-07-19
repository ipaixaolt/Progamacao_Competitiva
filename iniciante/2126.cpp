//Nomes: Isadellis Paixão, Milena Bueno

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

string n1, n2;
int qt_subsequencias, pos;

//https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
void search(int q) {
    int M = n1.size();
    int N = n2.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int d = 256;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + n1[i]) % q;
        t = (d * t + n2[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) if (n2[i + j] != n1[j]) break;
            
            if (j == M) { 
                pos = i + 1;
                qt_subsequencias++;
            }
        }

        if (i < N - M) {
            t = (d * (t - n2[i] * h) + n2[i + M]) % q;
            if (t < 0)t = (t + q);
        }
    }
}

int main(void) { _
    int caso = 1;

    while (cin >> n1) {
        cin >> n2;
        qt_subsequencias = 0;

        cout << "Caso #" << caso++ << ":" << endl;
        
        search(INT_MAX);
        if (qt_subsequencias == 0) cout << "Nao existe subsequencia" << endl;
        else {
            cout << "Qtd.Subsequencias: " << qt_subsequencias << endl;
            cout << "Pos: " << pos << endl;
        }

        cout << endl;
    }

    return 0;
}