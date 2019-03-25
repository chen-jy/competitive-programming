#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100001;
vector<int> adj[MAXN], ap;
int timer = 0, low[MAXN] = {}, tin[MAXN] = {};
bool vis[MAXN] = {};

void dfs(int u, int p) {
	vis[u] = 1;
	low[u] = tin[u] = timer++;
	int v, child = 0;
	bool c = 0;
	for (int j = 0; j < adj[u].size(); j++) {
		if (adj[u][j] != p) {
			if (vis[adj[u][j]])
				low[u] = min(low[u], tin[adj[u][j]]);
			else {
				dfs(adj[u][j], u);
				low[u] = min(low[u], low[adj[u][j]]);
				c |= low[adj[u][j]] >= tin[u];
				child++;
			}
		}
	}
	if (p == -1)
		c = child >= 2;
	if (c)
		ap.push_back(u);
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, x, y;
	scan(N); scan(M);
	while (M--) {
		scan(x); scan(y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < N; i++) {
		if (!vis[i])
			dfs(i, -1);
	}
	sort(ap.begin(), ap.end());
	cout << ap.size() << endl;
	for (int i = 0; i < ap.size(); i++)
		cout << ap[i] << endl;
	return 0;
}
