#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

struct edge {
	int t, d, u;
};

vector<edge> adj[1601];
int dist[1601][3601];
bool inQ[1601];

int main() {
	memset(dist, INF, sizeof(dist));
	int S, N, E, s, t, d, u, x;
	scanf("%d%d%d", &S, &N, &E);
	while (E--) {
		scanf("%d%d%d%d", &s, &t, &d, &u);
		adj[s].push_back({ t, d, u });
		adj[t].push_back({ s, d, u });
	}
	priority_queue<pair<int, int>> q;
	dist[0][0] = 0;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		s = q.top().second, q.pop();
		inQ[s] = 0;
		for (int i = 0; i < adj[s].size(); i++) {
			t = adj[s][i].t, d = adj[s][i].d, u = adj[s][i].u;
			if (u) {
				for (int j = 0; j + d <= S; j++) {
					x = dist[s][j] + d;
					if (x < dist[t][j + d]) {
						dist[t][j + d] = x;
						if (!inQ[t]) {
							inQ[t] = 1;
							q.push(make_pair(-x, t));
						}
					}
				}
			}
			else {
				for (int j = 0; j <= 3600; j++) {
					x = dist[s][j] + d;
					if (x < dist[t][j]) {
						dist[t][j] = x;
						if (!inQ[t]) {
							inQ[t] = 1;
							q.push(make_pair(-x, t));
						}
					}
				}
			}
		}
	}
	t = INF;
	for (int i = 0; i <= S; i++) {
		if (dist[N - 1][i] < t)
			t = dist[N - 1][i];
	}
	if (t != INF)
		printf("%d\n", t);
	else printf("-1\n");
	return 0;
}
