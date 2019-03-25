#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, int>> adj[100001];
int dist[100001], dist2[100001], radius;
bool vis[100001] = {};
vector<int> radii;

pair<int, int> bfs(int u, bool X) {
	int fv = u, fd = 0, pred;
	queue<pair<int, int>> q;
	q.push(make_pair(u, -1));
	dist[u] = 0;
	while (!q.empty()) {
		u = q.front().first, pred = q.front().second, q.pop();
		if (!X) vis[u] = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			if (adj[u][i].first != pred) {
				dist[adj[u][i].first] = dist[u] + adj[u][i].second;
				if (dist[adj[u][i].first] > fd)
					fd = dist[adj[u][i].first], fv = adj[u][i].first;
				q.push(make_pair(adj[u][i].first, u));
			}
		}
	}
	return make_pair(fv, fd);
}

bool find_radius(int u, int pred, int fd, int v) {
	vis[u] = 1;
	if (u == v) {
		radius = min(radius, fd);
		dist2[u] = 0;
		return 1;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		if (adj[u][i].first != pred && find_radius(adj[u][i].first, u, fd, v)) {
			dist2[u] = dist2[adj[u][i].first] + adj[u][i].second;
			radius = min(radius, max(dist2[u], fd - dist2[u]));
			return 1;
		}
	}
	return 0;
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
	int ans = 0;
	for (int i = 0; i < M; i++) {
		adj[A[i]].push_back(make_pair(B[i], T[i]));
		adj[B[i]].push_back(make_pair(A[i], T[i]));
	}
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			pair<int, int> bfs1 = bfs(i, 0), bfs2 = bfs(bfs1.first, 1);
			ans = max(ans, bfs2.second), radius = INF;
			find_radius(bfs1.first, -1, bfs2.second, bfs2.first);
			radii.push_back(radius);
		}
	}
	sort(radii.rbegin(), radii.rend());
	if (radii.size() >= 2)
		ans = max(ans, radii[0] + L + radii[1]);
	if (radii.size() >= 3)
		ans = max(ans, radii[1] + 2 * L + radii[2]);
	return ans;
}
