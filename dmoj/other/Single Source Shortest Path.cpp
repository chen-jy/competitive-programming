#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int, int>> adj[1001];
int dist[1001];
bool vis[1001] = {};

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	memset(dist, INF, sizeof(dist));
	int N, M, u, v, w;
	scan(N); scan(M);
	while (M--) {
		scan(u); scan(v); scan(w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	priority_queue<pair<int, int>> q;
	dist[1] = 0;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		u = q.top().second, q.pop();
		vis[u] = 1;
		for (int i = 0; i < adj[u].size(); i++) {
			if (!vis[adj[u][i].first]) {
				w = dist[u] + adj[u][i].second;
				if (w < dist[adj[u][i].first]) {
					dist[adj[u][i].first] = w;
					q.push(make_pair(-w, adj[u][i].first));
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i])
			cout << dist[i] << endl;
		else cout << -1 << endl;
	}
	return 0;
}
