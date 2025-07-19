//Milena Bueno, Isadellis Paixao
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dgb(x) cout << #x << " = " << x << endl
#define endl "\n"
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

pair<int,int> mov(int x, int y, int qual){
    if(qual == 1 && x+1<8 && y+2<8) return make_pair(x+1,y+2);
    if(qual == 2 && x+2<8 && y+1<8) return make_pair(x+2,y+1);
    if(qual == 3 && x+2<8 && y-1>=0) return make_pair(x+2,y-1);
    if(qual == 4 && x+1<8 && y-2>=0) return make_pair(x+1,y-2);
    if(qual == 5 && x-1>=0 && y-2>=0) return make_pair(x-1,y-2);
    if(qual == 6 && x-2>=0 && y-1>=0) return make_pair(x-2,y-1);
    if(qual == 7 && x-2>=0 && y+1<8) return make_pair(x-2,y+1);
    if(qual == 8 && x-1>=0 && y+2<8) return make_pair(x-1,y+2);

    return make_pair(-1,-1);

}

int main(){ _
    
    vector<vector<int>> mapa (8, vector<int>(8,0));
    mapa[1][3] = 1;
    mapa[2][3] = 1;
    mapa[2][5] = 1;
    mapa[5][4] = 1;

    int n, cont=0; cin >> n;
    pair<int,int> loc = make_pair(4,3);
    while(n--){
        int a; cin >> a;
        cont++;
        loc = mov(loc.first, loc.second, a);
        if(mapa[loc.first][loc.second]) break;
    }

    cout << cont << endl;
    return 0;
}
