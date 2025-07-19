#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"


int main(void) { _
    int v, t, a;
    cin >> v >> t;

    while (t--) {
        cin >> a;
        
        if (v + a < 0) v  = 0;
        else if (v + a > 100) v = 100;
        else v += a;
    }
    
    cout << v << endl;
    return 0;
}