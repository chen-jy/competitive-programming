#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
using namespace std;

int root[100001];
vector<pair<int, int>> E;
vector<int> mst;

int find_root(int x) {
	if (root[x] != x)
		root[x] = find_root(root[x]);
	return root[x];
}

void kruskal(int N) {
	int u, v;
	for (int i = 1; i <= N; i++)
		root[i] = i;
	for (int i = 0; i < E.size(); i++) {
		u = find_root(E[i].first);
		v = find_root(E[i].second);
		if (u != v) {
			mst.push_back(i + 1);
			root[u] = root[v];
		}
	}
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, u, v;
	scan(N); scan(M);
	while (M--) {
		scan(u); scan(v);
		E.push_back(make_pair(u, v));
	}
	kruskal(N);
	if (mst.size() == N - 1) {
		for (int i = 0; i < mst.size(); i++)
			cout << mst[i] << endl;
	}
	else cout << "Disconnected Graph" << endl;
	return 0;
}
