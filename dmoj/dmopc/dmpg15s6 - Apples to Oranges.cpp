#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

unordered_map<string, int> dict;
vector<pair<int, double>> adj[501];
double maxi[501] = {};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, A, x;
	string a, b;
	double c;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a;
		dict[a] = i;
	}
	while (M--) {
		cin >> a >> b >> c;
		adj[dict[a]].push_back(make_pair(dict[b], c));
	}
	A = dict["APPLES"];
	maxi[A] = 1.0;
	queue<pair<int, double>> q;
	q.push(make_pair(A, 1.0));
	while (!q.empty()) {
		x = q.front().first, c = q.front().second, q.pop();
		if (x == A && c > 1.0 && ceil(c) == c) {
			cout << "YA\n";
			return 0;
		}
		for (int i = 0; i < adj[x].size(); i++) {
			if (c * adj[x][i].second > maxi[adj[x][i].first]) {
				maxi[adj[x][i].first] = c * adj[x][i].second;
				q.push(make_pair(adj[x][i].first, c * adj[x][i].second));
			}
		}
	}
	cout << "NAW\n";
	return 0;
}
