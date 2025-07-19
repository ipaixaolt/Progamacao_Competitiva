//Milena Bueno, Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
    int f1, f2, x1, y1, x2, y2;
    cin >> f1 >> f2 >> x1 >> y1 >> x2 >> y2;

    bool resp = false;

    int t1, t2;
    t1 = f1 - x1; t2 = f2 - y1;
    

    if(t1>=0 && t2>=0 &&((t1>=x2 && f2>=y2) || (t1>=y2 && f2>=x2) ||(t2>=x2 && f1>=y2) || (t2>=y2 && f1>=x2)))
        resp = true;
    
    t1 = f1 - y1; t2 = f2 - x1;
    
    if(t1>=0 && t2>=0 &&((t1>=x2 && f2>=y2) || (t1>=y2 && f2>=x2) ||(t2>=x2 && f1>=y2) || (t2>=y2 && f1>=x2)))
        resp = true;


    if(resp) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}
