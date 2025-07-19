//nome: Milena Bueno e Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n; 
    while(cin >> n){
        int resp=0;
        int lucro_ant = 0;
        int valor; cin >> valor;
        for(int i=0; i<n; i++){
            int dia; cin >> dia;
            
            if((dia+lucro_ant)- valor < 0) lucro_ant = 0;
            else{
                lucro_ant = (lucro_ant+dia) - valor;
                resp = max(lucro_ant, resp);
            }
        }
        cout << resp << endl;
    }
    return 0;
}