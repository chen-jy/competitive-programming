#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;
typedef unsigned long long ull;

struct query {
	int idx, a, b, q;
	ull ans = 0;

	query(int _idx, int _a, int _b, int _q) {
		idx = _idx, a = _a, b = _b, q = _q;
	}
};

bool compare_by_idx(query a, query b) {
	return a.idx < b.idx;
}
bool compare_by_q(query a, query b) {
	return b.q < a.q;
}

int N;
ull bit[100001];
map<int, vector<int>, greater<int>> trees;
vector<query> queries;

void add(int i, int v) {
	for (; i <= N; i += i & -i)
		bit[i] += v;
}

ull sum(int hi) {
	ull res = 0;
	for (; hi > 0; hi -= hi & -hi)
		res += bit[hi];
	return res;
}

ull sum(int lo, int hi) {
	return sum(hi) - sum(lo - 1);
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int m, Q, a, b, q;
	scan(N);
	for (int i = 1; i <= N; i++) {
		scan(m);
		auto it = trees.find(m);
		if (it != trees.end())
			it->second.push_back(i);
		else {
			vector<int> e = { i };
			trees.insert(make_pair(m, e));
		}
	}
	scan(Q);
	for (int i = 0; i < Q; i++) {
		scan(a); scan(b); scan(q);
		queries.push_back(query(i, a + 1, b + 1, q));
	}
	sort(queries.begin(), queries.end(), compare_by_q);
	for (int i = 0; i < queries.size(); i++) {
		while (trees.size() > 0 && trees.begin()->first >= queries[i].q) {
			auto it = trees.begin();
			m = it->first;
			for (int i = 0; i < it->second.size(); i++) {
				add(it->second[i], m);
			}
			trees.erase(m);
		}
		queries[i].ans = sum(queries[i].a, queries[i].b);
	}
	sort(queries.begin(), queries.end(), compare_by_idx);
	for (query i : queries)
		cout << i.ans << endl;
	return 0;
}
