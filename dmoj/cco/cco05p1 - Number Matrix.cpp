#include <cstdio>
#include <cstring>
using namespace std;

int N, M, grid[100][100], x, y, z;
bool vis[100][100], good = 0;

bool move(int i, int j) {
	if (grid[i][j] == x || grid[i][j] == y || grid[i][j] == z)
		return 1;
	return 0;
}

void dfs(int i, int j) {
	vis[i][j] = 1;
	if (i == M - 1) {
		good = 1;
		return;
	}
	if (i - 1 >= 0 && !vis[i - 1][j] && move(i - 1, j))
		dfs(i - 1, j);
	if (i + 1 < M && !vis[i + 1][j] && move(i + 1, j))
		dfs(i + 1, j);
	if (j - 1 >= 0 && !vis[i][j - 1] && move(i, j - 1))
		dfs(i, j - 1);
	if (j + 1 < N && !vis[i][j + 1] && move(i, j + 1))
		dfs(i, j + 1);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &grid[i][j]);
	}
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c < 10; c++) {
				x = a, y = b, z = c;
				for (int i = 0; i < N; i++) {
					memset(vis, 0, sizeof(vis));
					dfs(0, i);
					if (good) {
						printf("%d %d %d\n", a, b, c);
						return 0;
					}
				}
			}
		}
	}
	printf("-1 -1 -1\n");
	return 0;
}
