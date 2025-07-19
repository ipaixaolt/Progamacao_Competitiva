//Grupo 9: Isadellis Luísa da Paixão Teixeira, Lucas Andrade Brandão e Milena Bueno Maciel
#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define endl '\n'
#define dbg(x) cout << #x << '=' << x << endl;

int m, n;

//https://github.com/brunomaletta/Biblioteca/blob/master/content/docs/Grafos/minCostMaxFlow.md
template<typename T> struct mcmf {
	struct edge {
		int to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
		bool res; // se eh reversa
		T cost; // custo da unidade de fluxo
		edge() : to(0), rev(0), flow(0), cap(0), cost(0), res(false) {}
		edge(int to_, int rev_, int flow_, int cap_, T cost_, bool res_)
			: to(to_), rev(rev_), flow(flow_), cap(cap_), res(res_), cost(cost_) {}
	};

	vector<vector<edge>> g;
	vector<int> par_idx, par;
	T inf;
	vector<T> dist;

	mcmf(int n) : g(n), par_idx(n), par(n), inf(numeric_limits<T>::max()/3) {}

	void add(int u, int v, int w, T cost) { // de u pra v com cap w e custo cost
		edge a = edge(v, g[v].size(), 0, w, cost, false);
		edge b = edge(u, g[u].size(), 0, 0, -cost, true);

		g[u].push_back(a);
		g[v].push_back(b);
	}

	vector<T> spfa(int s) { // nao precisa se nao tiver custo negativo
		deque<int> q;
		vector<bool> is_inside(g.size(), 0);
		dist = vector<T>(g.size(), inf);

		dist[s] = 0;
		q.push_back(s);
		is_inside[s] = true;

		while (!q.empty()) {
			int v = q.front();
			q.pop_front();
			is_inside[v] = false;

			for (int i = 0; i < g[v].size(); i++) {
				auto [to, rev, flow, cap, res, cost] = g[v][i];
				if (flow < cap and dist[v] + cost < dist[to]) {
					dist[to] = dist[v] + cost;

					if (is_inside[to]) continue;
					if (!q.empty() and dist[to] > dist[q.front()]) q.push_back(to);
					else q.push_front(to);
					is_inside[to] = true;
				}
			}
		}
		return dist;
	}

	bool dijkstra(int s, int t, vector<T>& pot) {
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> q;
		dist = vector<T>(g.size(), inf);
		dist[s] = 0;
		q.emplace(0, s);
		while (q.size()) {
			auto [d, v] = q.top();
			q.pop();
			if (dist[v] < d) continue;
			for (int i = 0; i < g[v].size(); i++) {
				auto [to, rev, flow, cap, res, cost] = g[v][i];
				cost += pot[v] - pot[to];
				if (flow < cap and dist[v] + cost < dist[to]) {
					dist[to] = dist[v] + cost;
					q.emplace(dist[to], to);
					par_idx[to] = i, par[to] = v;
				}
			}
		}
		return dist[t] < inf;
	}

	pair<int, T> min_cost_flow(int s, int t, int flow) {
		vector<T> pot(g.size(), 0);
		pot = spfa(s); // mudar algoritmo de caminho minimo aqui

		int f = 0;
		T ret = 0;
		while (f < flow and dijkstra(s, t, pot)) {
			for (int i = 0; i < g.size(); i++)
				if (dist[i] < inf) pot[i] += dist[i];

			int mn_flow = flow - f, u = t;
			while (u != s){
				mn_flow = min(mn_flow,
					g[par[u]][par_idx[u]].cap - g[par[u]][par_idx[u]].flow);
				u = par[u];
			}

			ret += pot[t] * mn_flow;

			u = t;
			while (u != s) {
				g[par[u]][par_idx[u]].flow += mn_flow;
				g[u][g[par[u]][par_idx[u]].rev].flow -= mn_flow;
				u = par[u];
			}

			f += mn_flow;
		}

		return make_pair(f, ret);
	}
};

int main (void) {_
	int d, k;
	int aux = 1;
	vector<tuple<int, int, int>> rotas;

	while (cin >> n >> m) {
		rotas = vector<tuple<int, int, int>>(m);
		mcmf<int> custoMin(n);

		cout << "Instancia " << aux  << endl; aux++;
		
		// Lendo rotas
		for (auto &[a, b, c] : rotas) cin >> a >> b >> c;
		
		// Lendo o número de amigos e assentos livres
		cin >> d >> k;

		for (auto &[a, b, c] : rotas) {
			custoMin.add(a - 1, b - 1, k, c);
			custoMin.add(b - 1, a - 1, k, c);
		}
		
		auto [fluxo, custo] = custoMin.min_cost_flow(0, n-1, d);
		if (fluxo < d) cout << "impossivel";
		else cout << custo;
		cout << endl << endl; 
	}

	return 0;
}

