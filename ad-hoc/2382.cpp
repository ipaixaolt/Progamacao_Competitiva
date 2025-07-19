//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>
#include <cmath> 

using namespace std;

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

int main (void) {_
    int L, A, P, R;
    cin >> L >> A >> P >> R;

    //Se a diagonal da caixa for menor ou igual ao diâmetro da esfera ela vai caber
    cout << ((sqrt(L * L + A * A + P * P) <= (2 * R)) ? 'S' : 'N') << endl;

    return 0;
}
