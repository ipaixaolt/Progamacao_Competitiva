#include <bits/stdc++.h>

using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define dgb(x) cout << #x << " = " << x << endl;
#define ll long long
#define uint unsigned int
#define MP make_pair
#define PB push_back
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int m, n;
vector<vector<char>> mapa;
vector<pii> terra;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main(void) {_
    int contador = 0;
    cin >> m >> n;
    
    mapa.resize(m, vector<char>(n));

    char c;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] == '#') terra.PB({i, j});
        }

    for (auto p : terra) {
        if (p.first == 0 || p.first == m - 1 || p.second == 0 || p.second == n - 1) {
            contador++;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && mapa[nx][ny] == '.') {
                contador++;
                break;
            }
        }
    }
    cout << contador << endl;

    return 0;
}
