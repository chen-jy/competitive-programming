#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

char grid[20][20];
int dist[20][20];
vector<int> perm;
vector<pair<int, int>> hide;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, T, xs, ys, a = 0, x, y, time = INT32_MAX, c, t;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'G')
				xs = j, ys = i;
			else if (grid[i][j] == 'H')
				hide.push_back(make_pair(j, i));
		}
	}
	for (int i = 0; i < T; i++)
		perm.push_back(i);
	do
	{
		c = 0, x = xs, y = ys;
		for (int i = 0; i < T; i++)
		{
			t = 0;
			for (int a = 0; a < N; a++)
			{
				for (int b = 0; b < M; b++)
					dist[a][b] = INT32_MAX;
			}
			queue<pair<int, int>> que;
			dist[y][x] = 0;
			que.push(make_pair(x, y));
			while (!que.empty())
			{
				x = que.front().first, y = que.front().second;
				que.pop();
				if (x == hide[perm[i]].first && y == hide[perm[i]].second)
				{
					t += dist[y][x];
					break;
				}
				if (x - 1 >= 0 && grid[y][x - 1] != 'X' && dist[y][x - 1] == INT32_MAX)
				{
					que.push(make_pair(x - 1, y));
					dist[y][x - 1] = dist[y][x] + 1;
				}
				if (x + 1 < M && grid[y][x + 1] != 'X' && dist[y][x + 1] == INT32_MAX)
				{
					que.push(make_pair(x + 1, y));
					dist[y][x + 1] = dist[y][x] + 1;
				}
				if (y - 1 >= 0 && grid[y - 1][x] != 'X' && dist[y - 1][x] == INT32_MAX)
				{
					que.push(make_pair(x, y - 1));
					dist[y - 1][x] = dist[y][x] + 1;
				}
				if (y + 1 < N && grid[y + 1][x] != 'X' && dist[y + 1][x] == INT32_MAX)
				{
					que.push(make_pair(x, y + 1));
					dist[y + 1][x] = dist[y][x] + 1;
				}
			}
			c += t;
		}
		if (c < time)
			time = c;
	} while (next_permutation(perm.begin(), perm.end()));
	cout << time;
	return 0;
}
