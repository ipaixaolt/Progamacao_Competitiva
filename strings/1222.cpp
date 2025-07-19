#include <bits/stdc++.h>

using namespace  std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define dgb(x) cout << #x << " = " << x << endl;
#define ll long long
#define MP make_pair
#define PB push_back

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main (void) { _
    int n, l, c;

    while (cin >> n >> l >> c) {
        vector<string> palavras(n);
        int lpag = 1, cpag = 0, pag = 1; 

        for (string &i : palavras) {
            cin >> i;
            
            if (cpag == 0) cpag = i.length();
            else if (cpag + 1 + i.length() <= c) cpag += 1 + i.length(); 
            else {
                lpag++;
                cpag = i.length();
            }

            if (lpag > l) {
                pag++;
                lpag = 1;
            }
        }

        cout << pag << endl;
    }

    return 0;
}
