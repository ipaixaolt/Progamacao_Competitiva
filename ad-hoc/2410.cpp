//Milena Bueno, Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;


int main (void) { _
	int n, aux;
	unordered_set<int> alunos_presentes;
	
	cin >> n;

	while (n--) cin >> aux, alunos_presentes.insert(aux);

	cout << alunos_presentes.size() << endl;
	
	return 0;

}
