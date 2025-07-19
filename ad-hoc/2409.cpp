//Milena Bueno, Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;


int main (void) { _
	int a, b, c;
	int h, l;

	cin >> a >> b >> c;
	cin >> h >> l;


	if ((a <= h && b <= l) || (a <= l && b <= h) || (a <= h && c <= l) || (a <= l && c <= h) || (b <= h && c <= l) || (b <= l && c <= h))
		cout << 'S' << endl;
	else
		cout << 'N' << endl;	
	return 0;

}
