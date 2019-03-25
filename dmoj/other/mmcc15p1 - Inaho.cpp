#include <iostream>
#include <stack>
//using namespace std;

int root[500001], rank[500001];
std::stack<std::pair<int, int>> E;

int find_root(int x) {
	if (root[x] == x)
		return x;
	return find_root(root[x]);
}

void Init(int N) {
	for (int i = 0; i <= N; i++)
		root[i] = i, rank[i] = 1;
}

void AddEdge(int U, int V) {
	int u = find_root(U), v = find_root(V);
	if (u == v) {
		E.push(std::make_pair(-1, -1));
		return;
	}
	E.push(std::make_pair(u, v));
	if (rank[u] <= rank[v]) {
		root[u] = root[v];
		rank[v] += rank[u];
	}
	else {
		root[v] = root[u];
		// Thanks typo
		rank[u] += rank[v];
	}
}

void RemoveLastEdge() {
	int u = E.top().first, v = E.top().second;
	E.pop();
	if (u == -1)
		return;
	if (root[u] == u) {
		root[v] = v;
		rank[u] -= rank[v];
	}
	else {
		root[u] = u;
		rank[v] -= rank[u];
	}
}

int GetSize(int U) {
	return rank[find_root(U)];
}
