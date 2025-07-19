//Milena Bueno, Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> casas;
int n, k;
int a, b;

int main (void) { _
	cin >> n;

	casas  = vector<int> (n);
	for (int &c : casas) cin >> c;
	
	cin >> k;


	//Two pointers
	int  l = 0, r = n - 1, soma = 0;
	while (l < r) {
		soma = casas[l] + casas[r];

		if (soma == k) {
		       a = casas[l], b = casas[r];
		       break;	
		}

		if (soma < k) l++;
		else r--;
	}

	cout << a << ' ' << b << endl;

	return 0;

}
