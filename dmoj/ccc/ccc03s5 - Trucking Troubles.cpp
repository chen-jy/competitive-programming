#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

unordered_map<int, int> adj[10001];
int dest[10001], maxi[10001] = {};
bool vis[10001] = {};

void add_edge(int u, int v, int w) {
	unordered_map<int, int>::iterator it = adj[u].find(v);
	if (it == adj[u].end())
		adj[u].insert(make_pair(v, w));
	else it->second = max(it->second, w);
}

void prim(int n) {
	int u, v, w;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		vis[i] = 1;
		priority_queue<pair<int, pair<int, int>>> q;
		for (auto j = adj[i].begin(); j != adj[i].end(); ++j)
			q.push(make_pair(j->second, make_pair(i, j->first)));
		while (!q.empty()) {
			w = q.top().first, u = q.top().second.first;
			v = q.top().second.second, q.pop();
			if (vis[u] && !vis[v]) {
				vis[v] = 1;
				if (v != i)
					maxi[v] = w;
				for (auto j = adj[v].begin(); j != adj[v].end(); ++j)
					q.push(make_pair(j->second, make_pair(v, j->first)));
			}
		}
	}
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, D, U, V, W, ans = 0x3f3f3f3f;
	scan(N); scan(M); scan(D);
	while (M--) {
		scan(U); scan(V); scan(W);
		add_edge(U, V, W);
		add_edge(V, U, W);
	}
	for (int i = 0; i < D; i++)
		scan(dest[i]);
	prim(N);
	for (int i = 0; i < D; i++)
		ans = min(ans, maxi[dest[i]]);
	cout << ans << endl;
	return 0;
}
