#include <iostream>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

char grid[1000][1000];
int dist[1000][1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int R, C, x, y, xd, yd, T, t = 0;
	cin >> R >> C >> y >> x >> yd >> xd;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> grid[i][j];
			dist[i][j] = INT32_MAX;
		}
	}
	queue<pair<int, int>> que;
	dist[y][x] = 0;
	que.push(make_pair(x, y));
	while (!que.empty())
	{
		y = que.front().second;
		x = que.front().first;
		que.pop();
		if (y == yd && x == xd)
			break;
		if (x - 1 >= 0 && grid[y][x - 1] != 'X' && dist[y][x - 1] == INT32_MAX)
		{
			que.push(make_pair(x - 1, y));
			dist[y][x - 1] = dist[y][x] + 1;
		}
		if (x + 1 < C && grid[y][x + 1] != 'X' && dist[y][x + 1] == INT32_MAX)
		{
			que.push(make_pair(x + 1, y));
			dist[y][x + 1] = dist[y][x] + 1;
		}
		if (y - 1 >= 0 && grid[y - 1][x] != 'X' && dist[y - 1][x] == INT32_MAX)
		{
			que.push(make_pair(x, y - 1));
			dist[y - 1][x] = dist[y][x] + 1;
		}
		if (y + 1 < R && grid[y + 1][x] != 'X' && dist[y + 1][x] == INT32_MAX)
		{
			que.push(make_pair(x, y + 1));
			dist[y + 1][x] = dist[y][x] + 1;
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> y >> x;
		if (dist[y][x] < dist[yd][xd] && dist[yd][xd] - dist[y][x] > t)
			t = dist[yd][xd] - dist[y][x];
	}
	cout << t;
	return 0;
}
