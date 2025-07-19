//Nomes: Isadellis Paixão, Milena Bueno
#include <algorithm>
#include <iostream>
#include <vector> 
#include <queue>
#include <map>

using namespace std;

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

vector<vector<int>> tabuleiro;
vector<vector<char>> entrada;
map<int, int> tamanhos;

int linhas[] = {1, 0, -1, 0}, colunas[] = {0, 1, 0, -1};

//Flood fill (BFS)
void bfs(int i, int j, int N, int M, int id) {
    int tamanho = 1;
    queue<pair<int, int>> fila;
    fila.push(make_pair(i, j)); //Adiciona a posição à fila

    tabuleiro[i][j] = id; //Muda a identifiação do navio para o seu número

    while (!fila.empty()) {
        int l = fila.front().first;
        int c = fila.front().second;

        fila.pop();

        //Olha as posições adjacentes
        for (int k = 0; k < 4; k++) {
            int linha = l + linhas[k];
            int coluna = c + colunas[k];

            //Se a posição não está nos limites do tabuleiro, já foi mapeada ou não corresponda a um navio, não é necessário verificá-la
            if ((linha < 0) || (linha >= N) || (coluna < 0) || (coluna >= M) || tabuleiro[linha][coluna] > 0 || entrada[linha][coluna] == '.') 
                continue;

            tamanho++;
            
            tabuleiro[linha][coluna] = id;
            fila.push(make_pair(linha, coluna)); //Adiciona a posição à fila para ter seus adjacentes verificados
        }
    }

    tamanhos.insert(make_pair(id, tamanho));
}

//Verifica se um navio foi destruído
bool isDestruido(const pair<int, int>& navio) {
    return navio.second == 0;
}

int main(void) {_
    int N, M, K, resultado = 0; //N = número de linhas, M = número de colunas, K = número de disparos

    cin >> N >> M;

    tabuleiro = vector<vector<int>>(N, vector<int>(M));
    entrada = vector<vector<char>>(N, vector<char>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> entrada[i][j];
        }

    int id = 1; //Para povoarmos o tabuleiro identificando os navios como números
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tabuleiro[i][j] == 0 && entrada[i][j] == '#') { //Se a posição for de um navio e ainda não tiver sido identificada
                bfs(i, j, N, M, id);
                id++; //Terminamos o navio atual
            }
    
    cin >> K;
    for (int i = 0; i < K; i++) {
        int l, c;

        cin >> l >> c;
        l--, c--;

        if (tabuleiro[l][c] > 0) //Se a posição corresponder à de um navio, então aquela posição foi destruída
            tamanhos[tabuleiro[l][c]]--;
        
    }  
            
    //Um navio só foi destruído completamente se seu tamanho for 0
    cout << count_if(tamanhos.begin(), tamanhos.end(), isDestruido) << endl;

    return 0;
}

