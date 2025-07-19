//Nomes: Isadellis Paixao e Milena Bueno
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

const int MAX = 11;
const int INF = 1000;

vector<vector<char>> labirinto(MAX, vector<char>(MAX));
int memo[MAX][MAX][MAX][MAX][MAX][MAX];
int r, n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
pii A, B, C;


int valido (pii p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n && labirinto[p.first][p.second] != '#';
}

int condicaoSaida (const tuple<pii, pii, pii, int>& st) {
    return labirinto[get<0>(st).first][get<0>(st).second] == 'X' &&
           labirinto[get<1>(st).first][get<1>(st).second] == 'X' &&
           labirinto[get<2>(st).first][get<2>(st).second] == 'X';
}

int diferentes (pii p1, pii p2, pii p3) {
    return !(p1 == p2 || p2 == p3 || p1 == p3);
}

int confere (const tuple<pii, pii, pii, int>& st) {
    if (!memo[get<0>(st).first][get<0>(st).second][get<1>(st).first][get<1>(st).second][get<2>(st).first][get<2>(st).second] &&
        diferentes(get<0>(st), get<1>(st), get<2>(st))) {
        return memo[get<0>(st).first][get<0>(st).second][get<1>(st).first][get<1>(st).second][get<2>(st).first][get<2>(st).second] = 1;
    }
    return 0;
}   

void bfs () {
    queue<tuple<pii, pii, pii, int>> q;
    memo[A.first][A.second][B.first][B.second][C.first][C.second] = 1;
    q.push(make_tuple(A, B, C, 0));

    while (!q.empty()) {
        tuple<pii, pii, pii, int> atual = q.front(); q.pop();
        if (condicaoSaida(atual)) r = min(r, get<3>(atual));
    
        for (int c = 0; c < 4; c++) {
            pii nA = {get<0>(atual).first + dx[c], get<0>(atual).second + dy[c]};
            pii nB = {get<1>(atual).first + dx[c], get<1>(atual).second + dy[c]};
            pii nC = {get<2>(atual).first + dx[c], get<2>(atual).second + dy[c]};

            int valido_A = valido (nA);
            int valido_B = valido (nB);
            int valido_C = valido (nC);

            if (valido_A || valido_B || valido_C) {
                tuple<pii, pii, pii, int> prox = atual;

                if (valido_A) {
                    if (!valido_B && !valido_C && nA != get<1>(atual) && nA != get<2>(atual)) get<0>(prox) = nA;
                    else if (valido_B && !valido_C && nA != get<2>(atual)) get<0>(prox) = nA;
                    else if (valido_C && !valido_B && nA != get<1>(atual)) get<0>(prox) = nA;
                    else if (valido_B && valido_C) get<0>(prox) = nA;
                }

                if (valido_B) {
                    if (!valido_A && !valido_C && nB != get<0>(atual) && nB != get<2>(atual)) get<1>(prox) = nB;
                    else if (valido_A && !valido_C && nB != get<2>(atual)) get<1>(prox) = nB;
                    else if (valido_C && !valido_A && nB != get<0>(atual)) get<1>(prox) = nB;
                    else if (valido_A && valido_C) get<1>(prox) = nB;
                }

                if (valido_C) {
                    if (!valido_A && !valido_B && nC != get<1>(atual) && nC != get<0>(atual)) get<2>(prox) = nC;
                    else if (valido_A && !valido_B && nC != get<1>(atual)) get<2>(prox) = nC;
                    else if (valido_B && !valido_A && nC != get<0>(atual)) get<2>(prox) = nC;
                    else if (valido_A && valido_B) get<2>(prox) = nC;
                }

                get<3>(prox) = get<3>(atual) + 1;
                if (confere(prox)) q.push(prox);
            }
        }
    }
}

int main (void) {_
    int t, caso = 1;
    cin >> t;

    while (t--) {
        r = INF;
        cout << "Case " << caso++ << ": ";
        cin >> n;
        memset(memo, 0, sizeof memo);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> labirinto[i][j];
                if (labirinto[i][j] == 'A') A = {i, j};
                if (labirinto[i][j] == 'B') B = {i, j};
                if (labirinto[i][j] == 'C') C = {i, j};
            }
        }

        bfs();
        if (r != INF) cout << r << endl;
        else cout << "trapped" << endl;
    }

    return 0;
}
