//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>
#include <vector>

using namespace std;

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);

void floydWarshall (vector<vector<int>> &distancias, int N) {
    for (int k = 0; k < N; k++) 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) 
                if ((distancias[i][j] > (distancias[i][k] + distancias[k][j])) && ((distancias[k][j] != 10001) && (distancias[i][k] != 10001)))
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
            
        
}
 
int main (void) {_
    int N, M;
    cin >> N >> M;

    vector<vector<int>> distancias(N, vector<int>(N, 10001));
    
    //A distância de uma cidade para ela mesmo é 0
    for (int i = 0; i < N; i++)
        distancias[i][i] = 0;

    //Leitura das estradas
    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;

        distancias[U][V] = distancias[V][U] = W; //A distância dos caminhos de ida e de volta são iguais
    }
    
    floydWarshall(distancias, N); //
    int resposta = 10001;

    //Encontrando a menor distância máxima (vide planilha)
    for (int i = 0; i < N; i++) {
        int distanciaMaxima = 0;

        for (int j = 0; j < N; j++)
            if (distancias[i][j] > distanciaMaxima)
                distanciaMaxima = distancias[i][j];  

        if (distanciaMaxima < resposta) 
            resposta = distanciaMaxima;
    }

    cout << resposta << endl;

    return 0;
}
