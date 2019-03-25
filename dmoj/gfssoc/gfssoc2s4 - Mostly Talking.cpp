#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
#define start(x) get<0>(x)
#define end(x) get<1>(x)
#define weight(x) get<2>(x)
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;

vector<int> dijkstra(graph adj, int source) {
	vector<int> dist(adj.size(), INF);
	vector<bool> vis(adj.size(), 0);
	priority_queue<pii> q;
	q.push(make_pair(0, source));
	dist[source] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		vis[u] = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, w = dist[u] + adj[u][i].second;
			if (!vis[v] && w < dist[v]) {
				dist[v] = w;
				q.push(make_pair(-w, v));
			}
		}
	}
	return dist;
}

int main() {
	int N, M, a, b, k;
	scanf("%d%d", &N, &M);
	graph adj_f(N + 1), adj_b(N + 1);
	while (M--) {
		scanf("%d%d%d", &a, &b, &k);
		adj_f[a].push_back(make_pair(b, k));
		adj_b[b].push_back(make_pair(a, k));
	}
	scanf("%d", &M);
	vector<tuple<int, int, int>> cindy;
	while (M--) {
		scanf("%d%d%d", &a, &b, &k);
		cindy.push_back(make_tuple(a, b, k));
	}
	vector<int> dist_f = dijkstra(adj_f, 1);
	vector<int> dist_b = dijkstra(adj_b, N);
	int ans = dist_f[N];
	for (int i = 0; i < cindy.size(); i++)
		ans = min(ans, dist_f[start(cindy[i])] + weight(cindy[i]) + dist_b[end(cindy[i])]);
	ans == INF ? ans = -1 : ans;
	printf("%d\n", ans);
	return 0;
}
