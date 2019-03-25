#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <string>
#define White 0
#define Gray 1
#define Black -1
using namespace std;

vector<int> adj[2][10001];
bool vis[2][10001] = {}, overflow = 0;
int color[10001] = {}, paths[10001] = {};

void dfs(int G, int u) {
	vis[G][u] = 1;
	for (int i = 0; i < adj[G][u].size(); i++) {
		if (!vis[G][adj[G][u][i]])
			dfs(G, adj[G][u][i]);
	}
}

int sort(int u) {
	if (color[u] == Black)
		return paths[u];
	if (color[u] == Gray)
		throw "inf";
	color[u] = Gray;
	if (u == 2)
		paths[u] = 1;
	for (int i = 0; i < adj[0][u].size(); i++) {
		if (vis[0][adj[0][u][i]] && vis[1][adj[0][u][i]])
			paths[u] += sort(adj[0][u][i]);
		if (paths[u] >= 1000000000) {
			paths[u] -= 1000000000;
			overflow = 1;
		}
	}
	color[u] = Black;
	return paths[u];
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, A, B;
	scan(N); scan(M);
	while (M--) {
		scan(A); scan(B);
		adj[0][A].push_back(B);
		adj[1][B].push_back(A);
	}
	dfs(0, 1); dfs(1, 2);
	try {
		int ans = sort(1);
		if (ans < 1000000000 && !overflow)
			cout << ans << endl;
		else {
			string res = "0000000000" + to_string(ans);
			for (int i = res.size() - 9; i < res.size(); i++)
				cout << res[i];
			cout << endl;
		}
	}
	catch (...) {
		cout << "inf" << endl;
	}
	return 0;
}
