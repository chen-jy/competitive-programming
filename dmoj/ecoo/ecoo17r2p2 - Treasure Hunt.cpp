#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char grid[1000][1000];
int N, ans, keys;

bool can_dfs(int x, int y) {
	if (grid[y][x] != '#' && grid[y][x] != '*' && (grid[y][x] < '1' || grid[y][x] > '9'))
		return 1;
	return 0;
}

bool good_door(int x, int y) {
	if (y - 1 >= 0 && grid[y - 1][x] == '*')
		return 1;
	if (y + 1 < N && grid[y + 1][x] == '*')
		return 1;
	if (x - 1 >= 0 && grid[y][x - 1] == '*')
		return 1;
	if (x + 1 < N && grid[y][x + 1] == '*')
		return 1;
	return 0;
}

void dfs(int x, int y) {
	if (grid[y][x] == 'K')
		keys++;
	else if (grid[y][x] == 'T')
		ans++;
	grid[y][x] = '*';
	if (y - 1 >= 0 && can_dfs(x, y - 1))
		dfs(x, y - 1);
	if (y + 1 < N && can_dfs(x, y + 1))
		dfs(x, y + 1);
	if (x - 1 >= 0 && can_dfs(x - 1, y))
		dfs(x - 1, y);
	if (x + 1 < N && can_dfs(x + 1, y))
		dfs(x + 1, y);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int test = 0; test < 10; test++) {
		ans = keys = 0;
		int x, y;
		cin >> N;
		vector<pair<int, pair<int, int>>> doors;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				char c;
				cin >> c;
				grid[i][j] = c;
				if (c == 'S')
					x = j, y = i;
				if (c >= '1' && c <= '9')
					doors.push_back(make_pair(c - '0', make_pair(j, i)));
			}
		}
		sort(doors.rbegin(), doors.rend());
		dfs(x, y);
		int n = doors.size() - 1;
		while (n >= 0 && keys >= doors[n].first) {
			if (doors[n].first == -1) {
				doors.pop_back();
				n--;
				continue;
			}
			if (good_door(doors[n].second.first, doors[n].second.second)) {
				dfs(doors[n].second.first, doors[n].second.second);
				doors.pop_back();
			}
			else if (n >= 1) {
				bool g = 0;
				while (n > 0 && keys >= doors[n - 1].first) {
					n--;
					if (doors[n].first != -1 && good_door(doors[n].second.first, doors[n].second.second)) {
						doors[n].first = -1;
						dfs(doors[n].second.first, doors[n].second.second);
						g = 1;
						break;
					}
				}
				if (!g)
					break;
			}
			else break;
			n = doors.size() - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
