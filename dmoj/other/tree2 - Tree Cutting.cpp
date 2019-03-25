#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

int R, C;
int grid[11][11], cost[11][11], trees[11][11];
bool inQueue[11][11] = {};
vector<pair<int, int>> maxHeights;

inline int square(int x) {
	return x * x;
}

inline bool isValidMove(int x, int y, bool Y, int dir) {
	return Y ? cost[y][x] + grid[y + dir][x] < cost[y + dir][x] || cost[y][x] + grid[y + dir][x] == cost[y + dir][x] &&
		trees[y][x] + (grid[y + dir][x] == 0 ? 0 : 1) < trees[y + dir][x] : cost[y][x] + grid[y][x + dir] < cost[y][x + dir] ||
		cost[y][x] + grid[y][x + dir] == cost[y][x + dir] && trees[y][x] + (grid[y][x + dir] == 0 ? 0 : 1) < trees[y][x + dir];
}

void bfs(int x, int y, int xt, int yt) {
	queue<pair<int, int>> q;
	cost[y][x] = trees[y][x] = 0;
	inQueue[y][x] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first, y = q.front().second;
		inQueue[y][x] = 0, q.pop();
		if (y - 1 >= 0 && isValidMove(x, y, 1, -1)) {
			cost[y - 1][x] = cost[y][x] + grid[y - 1][x];
			trees[y - 1][x] = trees[y][x] + (grid[y - 1][x] == 0 ? 0 : 1);
			if (!inQueue[y - 1][x]) {
				q.push(make_pair(x, y - 1));
				inQueue[y - 1][x] = 1;
			}
		}
		if (y + 1 < R && isValidMove(x, y, 1, 1)) {
			cost[y + 1][x] = cost[y][x] + grid[y + 1][x];
			trees[y + 1][x] = trees[y][x] + (grid[y + 1][x] == 0 ? 0 : 1);
			if (!inQueue[y + 1][x]) {
				q.push(make_pair(x, y + 1));
				inQueue[y + 1][x] = 1;
			}
		}
		if (x - 1 >= 0 && isValidMove(x, y, 0, -1)) {
			cost[y][x - 1] = cost[y][x] + grid[y][x - 1];
			trees[y][x - 1] = trees[y][x] + (grid[y][x - 1] == 0 ? 0 : 1);
			if (!inQueue[y][x - 1]) {
				q.push(make_pair(x - 1, y));
				inQueue[y][x - 1] = 1;
			}
		}
		if (x + 1 < C && isValidMove(x, y, 0, 1)) {
			cost[y][x + 1] = cost[y][x] + grid[y][x + 1];
			trees[y][x + 1] = trees[y][x] + (grid[y][x + 1] == 0 ? 0 : 1);
			if (!inQueue[y][x + 1]) {
				q.push(make_pair(x + 1, y));
				inQueue[y][x + 1] = 1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	memset(cost, INF, sizeof(cost));
	memset(trees, INF, sizeof(trees));
	int x, y, xt, yt, maxHeight = 0, maxDist = INF;
	char c;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			if (c >= '0' && c <= '9') {
				int t = c - '0';
				grid[i][j] = t;
				if (t > maxHeight) {
					maxHeights.clear();
					maxHeights.push_back(make_pair(i, j));
					maxHeight = t;
				}
				else if (t == maxHeight)
					maxHeights.push_back(make_pair(i, j));
			}
			else {
				grid[i][j] = 0;
				if (c == 'X')
					x = j, y = i;
			}
		}
	}
	for (int i = 0; i < maxHeights.size(); i++) {
		int d = square(maxHeights[i].first - y) + square(maxHeights[i].second - x);
		if (d < maxDist) {
			xt = maxHeights[i].second, yt = maxHeights[i].first;
			maxDist = d;
		}
	}
	bfs(x, y, xt, yt);
	cout << trees[yt][xt] - 1 << '\n';
	return 0;
}
