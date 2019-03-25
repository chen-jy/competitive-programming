#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[1000001];
double prob[1000001];

int main() {
	int N, M, u, v;
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	prob[1] = 1;
	for (int i = 1; i <= N; i++) {
		double p = prob[i] / adj[i].size();
		for (int j = 0; j < adj[i].size(); j++)
			prob[adj[i][j]] += p;
		if (adj[i].size() == 0)
			printf("%.9f\n", prob[i]);
	}
	return 0;
}
