//Nome: Milena Bueno e Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

int main() { _
    int n;
    while (cin >> n) { 
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        vector<int> lis; 

        for (int x : v) {
            auto it = lower_bound(lis.begin(), lis.end(), x); //Verifica se ja tem um valor maior ou igual
            if (it == lis.end()) lis.push_back(x); //Se nao, acrescenta x no fim da lista
            else *it = x; //Se sim, substitui esse valor maior por x (numeros menores aumentam a possibilidade de colocar novos valores)
        }

        cout << lis.size() << endl;
    }
    return 0;
}
