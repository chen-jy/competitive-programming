#include <iostream>
#include <queue>
#include <utility>
#define INF 0x3f3f3f3f

using namespace std;

char grid[1000][1000];
int dist[1000][1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int n, m, xs, ys, xd, yd;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 's')
				xs = j, ys = i;
			else if (grid[i][j] == 'e')
				xd = j, yd = i;
			dist[i][j] = INF;
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(xs, ys));
	dist[ys][xs] = 0;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (grid[y][x] == 'o')
			break;
		if (y - 1 >= 0 && grid[y - 1][x] != 'X' && dist[y - 1][x] == INF)
		{
			dist[y - 1][x] = dist[y][x] + 1;
			q.push(make_pair(x, y - 1));
		}
		if (y + 1 < n && grid[y + 1][x] != 'X' && dist[y + 1][x] == INF)
		{
			dist[y + 1][x] = dist[y][x] + 1;
			q.push(make_pair(x, y + 1));
		}
		if (x - 1 >= 0 && grid[y][x - 1] != 'X' && dist[y][x - 1] == INF)
		{
			dist[y][x - 1] = dist[y][x] + 1;
			q.push(make_pair(x - 1, y));
		}
		if (x + 1 < m && grid[y][x + 1] != 'X' && dist[y][x + 1] == INF)
		{
			dist[y][x + 1] = dist[y][x] + 1;
			q.push(make_pair(x + 1, y));
		}
	}
	if (dist[yd][xd] != INF)
		cout << dist[yd][xd] - 1 << endl;
	else cout << -1 << endl;
	return 0;
}
