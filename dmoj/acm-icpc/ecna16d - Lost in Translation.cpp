#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

unordered_map<string, int> dict;
vector<pair<int, int>> adj[101];
int dist[101], cost[101];

inline int getidx(string a) {
	return dict.find(a)->second;
}

void bfs(int u = 0) {
	queue<int> q;
	dist[0] = cost[0] = 0;
	q.push(0);
	while (!q.empty()) {
		u = q.front(), q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, w = adj[u][i].second;
			if (dist[u] + 1 <= dist[v]  &&  w <= cost[v]) {
				if (dist[v] == INF)
					q.push(v);
				dist[v] = dist[u] + 1, cost[v] = w;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	memset(dist, INF, sizeof(dist));
	memset(cost, INF, sizeof(cost));
	int n, m, c;
	string a, b;
	cin >> n >> m;
	dict["English"] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		dict[a] = i;
	}
	while (m--) {
		cin >> a >> b >> c;
		int A = getidx(a), B = getidx(b);
		adj[A].push_back(make_pair(B, c));
		adj[B].push_back(make_pair(A, c));
	}
	bfs();
	c = 0;
	for (int i = 1; i <= n; i++) {
		if (cost[i] == INF) {
			cout << "Impossible\n";
			return 0;
		}
		c += cost[i];
	}
	cout << c << '\n';
	return 0;
}
