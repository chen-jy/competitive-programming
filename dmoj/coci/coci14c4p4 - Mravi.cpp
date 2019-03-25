#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct pipe {
	int end;
	double flow;
	bool super;
	pipe(int _end, double _flow, bool _super) {
		end = _end, flow = _flow, super = _super;
	}
};

vector<pipe> adj[1001];
int K[1001];

bool bfs(float L, int N) {
	float flow[1001] = {};
	bool vis[1001] = {};
	queue<int> q;
	flow[1] = L;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = 1;
		for (int i = 0; i < adj[x].size(); i++) {
			if (!vis[adj[x][i].end]) {
				if (adj[x][i].super && flow[x] > 1)
					flow[adj[x][i].end] = pow(flow[x] * adj[x][i].flow / 100, 2);
				else flow[adj[x][i].end] = flow[x] * adj[x][i].flow / 100;
				if (flow[adj[x][i].end] < K[adj[x][i].end])
					return 0;
				q.push(adj[x][i].end);
			}
		}
	}
	return 1;
}

int main() {
	int N, A, B, T, X;
	double L = 0, R = 2e9, M, ans;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d%d%d", &A, &B, &X, &T);
		adj[A].push_back(pipe(B, X, T));
	}
	for (int i = 1; i <= N; i++)
		scanf("%d", &K[i]);
	ans = 0;
	while (L <= R) {
		M = (L + R) / 2;
		if (bfs(M, N))
			ans = M, R = M - 0.001;
		else L = M + 0.001;
	}
	printf("%f\n", ans);
	return 0;
}
