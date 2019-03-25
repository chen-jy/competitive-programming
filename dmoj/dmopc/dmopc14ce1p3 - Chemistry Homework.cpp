#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[1001];
bool vis[1001][1001];

void make_bond(int A, int B) {
	bool g = 0;
	for (int i = 0; i < adj[A].size(); i++) {
		if (adj[A][i].first == B) {
			adj[A][i].second++;
			g = 1;
		}
	}
	if (!g)
		adj[A].push_back(make_pair(B, 1));
}

int count_bonds(int A) {
	int count = 0;
	for (int i = 0; i < adj[A].size(); i++) {
		if (adj[A][i].second > 2)
			return -1;
		count += adj[A][i].second;
	}
	if (count == 2 || count == 3 || count > 4)
		return -1;
	return count;
}

int main() {
	int N, M, A, B, H = 0, C = 0, ans = 0;
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d", &A, &B);
		make_bond(A, B);
		make_bond(B, A);
	}
	for (int i = 1; i <= N; i++) {
		int count_i = count_bonds(i);
		if (count_i == -1 || count_i == 0) {
			printf("Impossible\n");
			return 0;
		}
		count_i == 1 ? H++ : C++;
		for (int j = 0; j < adj[i].size(); j++) {
			if (vis[i][adj[i][j].first] || i == adj[i][j].first)
				continue;
			vis[i][adj[i][j].first] = vis[adj[i][j].first][i] = 1;
			int count_j = count_bonds(adj[i][j].first);
			if (count_j == -1) {
				printf("Impossible\n");
				return 0;
			}
			if (adj[i][j].second == 1) {
				if (count_i == 4 && count_j == 1 || count_i == 1 && count_j == 4)
					ans += 413;
				else if (count_i == 4 && count_j == 4)
					ans += 346;
				else {
					printf("Impossible\n");
					return 0;
				}
			}
			else if (adj[i][j].second == 2) {
				if (count_i == 4 && count_j == 4)
					ans += 615;
				else {
					printf("Impossible\n");
					return 0;
				}
			}
			else {
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("%d\n", ans);
	if (C == 1) printf("C");
	else printf("C%d", C);
	if (H == 1) printf("H");
	else printf("H%d\n", H);
	return 0;
}
