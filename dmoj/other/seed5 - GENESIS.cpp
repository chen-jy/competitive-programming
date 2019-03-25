#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

int adj[202][202], pred[202];
bool vis[202];

bool bfs(int N) {
	fill(vis, vis + N * 2 + 1, false);
	fill(pred, pred + N * 2 + 1, -1);
	queue<int> q;
	q.push(2);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == N * 2)
			return 1;
		vis[u] = 1;
		for (int v = 3; v <= N * 2; v++) {
			if (!vis[v] && adj[u][v]) {
				pred[v] = u;
				q.push(v);
			}
		}
	}
	return 0;
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, u, v, ans = 0;
	scan(N);
	for (int i = 1; i < N; i++) {
		scan(u);
		adj[i * 2][i * 2 + 1] = u;
	}
	scan(M);
	for (int i = 0; i < M; i++) {
		scan(u); scan(v);
		adj[u * 2 + 1][v * 2] = INF;
	}
	while (bfs(N)) {
		int flow = INF;
		for (v = N * 2; v != 2; v = pred[v]) {
			u = pred[v];
			flow = min(flow, adj[u][v]);
		}
		for (v = N * 2; v != 2; v = pred[v]) {
			u = pred[v];
			adj[u][v] -= flow, adj[v][u] += flow;
		}
		ans += flow;
	}
	cout << ans << endl;
	return 0;
}
