#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int root[100000];
vector<pair<int, pair<int, int>>> E;

int find_root(int x) {
	if (root[x] != x)
		root[x] = find_root(root[x]);
	return root[x];
}

int kruskal(int n) {
	sort(E.begin(), E.end());
	int u, v, d = 0;
	for (int i = 0; i < n; i++)
		root[i] = i;
	for (int i = 0; i < E.size(); i++) {
		u = find_root(E[i].second.first);
		v = find_root(E[i].second.second);
		if (u != v) {
			d += E[i].first;
			root[u] = root[v];
		}
	}
	return d;
}

int main() {
	int N, K, w;
	scan(N); scan(K);
	for (int i = 0; i < N - 1; i++) {
		scan(w);
		E.push_back(make_pair(w, make_pair(i, i + 1)));
		if (i + K < N)
			E.push_back(make_pair(0, make_pair(i, i + K)));
	}
	int dist = kruskal(N);
	cout << dist << endl;
	return 0;
}
