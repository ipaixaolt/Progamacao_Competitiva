#include <iostream>

using namespace std;

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

int main (void) {_
    int N; //N = consumo de água na residência
    int saida = 0;
    
    cin >> N;
    
    if (N >= 101) {
        saida += (N - 100) * 5;
        N -= N - 100;
    } 
    
    if ((N >= 31) && (N <= 100)) {
        saida += (N - 30) * 2;
        N -= N - 30;
    }
    
    if ((N >= 11) && (N <= 30)) {
        saida += N - 10;
        N -= N - 10;
    }
    
    if (N <= 10) {
        saida += 7;
    }
    
    cout << saida << endl;

    return 0;
}
