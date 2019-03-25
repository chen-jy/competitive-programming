#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[400001];
long long dist[400001], memo[400001], d = 0, n = 0;
bool vis[400001];

void dfs(int x) {
	vis[x] = 1, memo[x] = 1, dist[x] = 0;
	for (int i = 0; i < adj[x].size(); i++) {
		if (!vis[adj[x][i]]) {
			dfs(adj[x][i]);
			if (d < dist[x] + dist[adj[x][i]] + 1) {
				d = dist[x] + dist[adj[x][i]] + 1;
				n = memo[x] * memo[adj[x][i]];
			}
			else if (d == dist[x] + dist[adj[x][i]] + 1)
				n += memo[x] * memo[adj[x][i]];
			if (dist[x] < dist[adj[x][i]] + 1) {
				dist[x] = dist[adj[x][i]] + 1;
				memo[x] = memo[adj[x][i]];
			}
			else if (dist[x] == dist[adj[x][i]] + 1)
				memo[x] += memo[adj[x][i]];
		}
	}
}

int main() {
	int N, i, j;
	scan(N);
	while (--N) {
		scan(i); scan(j);
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	dfs(1);
	cout << d + 1 << ' ' << n << endl;
	return 0;
}
