#include <iostream>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

char grid[5000][5000];
int dist[5000][5000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int t, l, w, x, y, a, b;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		cin >> w >> l;
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> grid[i][j];
				if (grid[i][j] == 'C')
					x = j, y = i;
				if (grid[i][j] == 'W')
					a = j, b = i;
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
			if (grid[y][x] == 'W')
				break;
			if (dist[y][x] >= 60)
				continue;
			if (x - 1 >= 0 && grid[y][x - 1] != 'X' && dist[y][x - 1] == INT32_MAX)
			{
				que.push(make_pair(x - 1, y));
				dist[y][x - 1] = dist[y][x] + 1;
			}
			if (x + 1 < w && grid[y][x + 1] != 'X' && dist[y][x + 1] == INT32_MAX)
			{
				que.push(make_pair(x + 1, y));
				dist[y][x + 1] = dist[y][x] + 1;
			}
			if (y - 1 >= 0 && grid[y - 1][x] != 'X' && dist[y - 1][x] == INT32_MAX)
			{
				que.push(make_pair(x, y - 1));
				dist[y - 1][x] = dist[y][x] + 1;
			}
			if (y + 1 < l && grid[y + 1][x] != 'X' && dist[y + 1][x] == INT32_MAX)
			{
				que.push(make_pair(x, y + 1));
				dist[y + 1][x] = dist[y][x] + 1;
			}
		}
		if (dist[b][a] >= 60)
			cout << "#notworth\n";
		else cout << dist[b][a] << '\n';
	}
	return 0;
}
