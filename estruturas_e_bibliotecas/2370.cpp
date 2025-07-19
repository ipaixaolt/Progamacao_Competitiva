//Nomes: Isadellis Paixão, Milena Bueno
#include <iostream>
#include <vector>
#include <algorithm>

#define _                    \
ios_base::sync_with_stdio(0); \
cin.tie(0);


using namespace std;

struct Aluno {
    string nome;
    int habilidade;
};

bool maisHabilidoso(const Aluno& a, const Aluno& b) {
    return a.habilidade > b.habilidade;
}


int main (void) {_
    int N, T; // N = quantidade de alunos, T = número de times
    int timeAtual = 0;

    cin >> N >> T;

    vector<Aluno> alunos(N);
    vector<vector<string>> times(T);

    //Lê os dados dos jogadores
    for (int i = 0; i < N; ++i)
        cin >> alunos[i].nome >> alunos[i].habilidade;

    sort(alunos.begin(), alunos.end(), maisHabilidoso); //Ordena por ordem decrescente de habilidade

    //Distribuis os jogadores alternadamente, começando do mais habilidoso
    for (int i = 0; i < N; ++i) {
        times[timeAtual].push_back(alunos[i].nome);
        timeAtual = (timeAtual + 1) % T;
    }

    for (int i = 0; i < T; ++i) {
        //Coloca os integrantes do time em ordem alfabética
        sort(times[i].begin(), times[i].end());

        cout << "Time " << i + 1 << endl;
        for (const auto& jogador : times[i])
            cout << jogador << endl;
        
        cout << endl;
    }

    return 0;
}
