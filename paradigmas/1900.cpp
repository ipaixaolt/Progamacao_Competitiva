#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define ll long long

const int INF = 0x3f3f3f3f;


int main(void) { _
    unordered_map<ll, int> v;
    ll n, v_i, r = 0;
    ll aux = 0;
    
    v[0] = 1;

    cin >> n;
    
    while (n--) {
        cin >> v_i;
        aux += v_i;

        if (v.count(aux)) r += v[aux];
        v[aux]++;
    }

    cout << r << endl;
    return 0;
}