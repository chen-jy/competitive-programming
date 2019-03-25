#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
using namespace std;

vector<int> adj[123];
bool vis[123];
set<char> sets, elem;

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (adj[x][i] <= 'Z' && !vis[adj[x][i]])
			dfs(adj[x][i]);
		else if (adj[x][i] >= 'a')
			elem.insert(adj[x][i]);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N;
	char a, b;
	string contains;
	cin >> N;
	while (N--) {
		cin >> a >> contains >> b;
		adj[a].push_back(b);
		if (a <= 'Z') sets.insert(a);
		if (b <= 'Z') sets.insert(b);
	}
	for (auto it = sets.begin(); it != sets.end(); ++it) {
		memset(vis, 0, sizeof(vis));
		elem.clear();
		dfs(*it);
		cout << (char)*it << " = {";
		if (elem.size() == 0)
			cout << "}\n";
		else {
			auto it2 = elem.begin();
			for (int i = 0; i < elem.size() - 1; ++it2, i++)
				cout << *it2 << ',';
			cout << *it2 << "}\n";
		}
	}
	return 0;
}
