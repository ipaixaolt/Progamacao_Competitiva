//Milena Bueno, Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX 2130;

int n, I, m, p;

vector<int> custo;
vector<int> valor;
vector<vector<int>> memo;
vector<vector<int>> proximo; //idade do proximo ano

int dp(int tempo, int idade){
    if(tempo == n + 1) return 0;
    if(memo[tempo][idade] != -1) return memo[tempo][idade];
    
    int vender, manter = INF;
    vender = custo[0] + p - valor[idade] + dp(tempo+1, 1);

    if(idade < m) manter = custo[idade] + dp(tempo+1, idade+1);

    if(vender <= manter){
        proximo[tempo][idade]=1;
        memo[tempo][idade] = vender;
    } 
    else{
        proximo[tempo][idade] = idade + 1;
        memo[tempo][idade] = manter;
    } 

    return memo[tempo][idade];

}


int main(){ _
    
    while( cin >> n >> I >> m >>p){
        custo.clear();
        valor.clear();
        memo.assign(n + 2, vector<int>(m + 2, -1));
        proximo.assign(n + 2, vector<int>(m + 2));

        for(int i=0; i<m; i++){
            int a; cin >> a;
            custo.push_back(a);
        }
        valor.push_back(0);
        for(int i=1; i<=m; i++){
            int a; cin >> a;
            valor.push_back(a);
        }

        cout << dp(1, I) << endl;

        int tempo=1, idade=I;
        vector<int> trocas;

        do{
            if(proximo[tempo][idade] == 1){
                trocas.push_back(tempo);
        }
        idade = proximo[tempo][idade];
        tempo++;
       } while(tempo <= n);
       if(trocas.empty()) cout << 0 << endl;
       else{
            for(int i=0; i<trocas.size(); i++){
                if(i!=0) cout << " ";
                cout << trocas[i];
            }
            cout << endl;
       }
    }

    return 0;
}