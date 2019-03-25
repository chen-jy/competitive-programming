#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#define MAXN 20001
#define INF 0x3f3f3f3f
#define start(x) get<0>(x)
#define end(x) get<1>(x)
#define len(x) get<2>(x)
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
	int N, M, A, B, L;
	scanf("%d%d", &N, &M);
	graph adj_f(N + 1), adj_b(N + 1);
	vector<tuple<int, int, int>> edges(M);
	while (M--) {
		scanf("%d%d%d", &A, &B, &L);
		adj_f[A].push_back(make_pair(B, L));
		adj_b[B].push_back(make_pair(A, L));
		edges.push_back(make_tuple(A, B, L));
	}
	vector<int> dist_f = dijkstra(adj_f, 1);
	vector<int> dist_b = dijkstra(adj_b, N);
	int fastest = dist_f[N], ans = INF;
	for (int i = 0; i < edges.size(); i++) {
		A = start(edges[i]), B = end(edges[i]), L = len(edges[i]);
		int t = dist_f[A] + L + dist_b[B];
		if (t > fastest && t < ans)
			ans = t;
	}
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}
