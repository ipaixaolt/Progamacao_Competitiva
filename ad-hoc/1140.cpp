//Nome: Milena Bueno e Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define dgb(x) cout << #x << " = " << x << endl

int main() { _
    string a;
    while(1){
        getline(cin, a);
        if(a == "*") break;

        bool ant = true;
        bool result = true;
        char letra  = a[0];
        //cout << letra << endl;
        for(auto u : a){
            
            if(ant && !(u == letra || u-32 == letra ||u+32 == letra)){
                
                result = false;
                break;
            }

            if(u == ' ') ant = true;
            else ant = false;
        }

        if(result) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
