#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;

int beac[500][3], dist[501];
vector<vector<int>> graph(501);

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int B, Q, a, b, x;
	cin >> B >> Q;
	for (int i = 0; i < B; i++)
	{
		cin >> beac[i][0] >> beac[i][1] >> beac[i][2];
		dist[i + 1] = INT32_MAX;
	}
	for (int i = 0; i < B; i++)
	{
		for (int j = 0; j < B; j++)
		{
			if (j == i)
				continue;
			if (sqrt(pow(abs(beac[i][1] - beac[j][1]), 2) + pow(abs(beac[i][0] - beac[j][0]), 2)) <= beac[i][2])
				graph[i + 1].push_back(j + 1);
		}
	}
	for (int query = 0; query < Q; query++)
	{
		for (int i = 1; i <= B && query > 0; i++)
			dist[i] = INT32_MAX;
		cin >> a >> b;
		queue<int> que;
		que.push(a);
		while (!que.empty())
		{
			x = que.front();
			que.pop();
			for (int i = 0; i < graph[x].size(); i++)
			{
				if (dist[graph[x][i]] == INT32_MAX)
				{
					dist[graph[x][i]] = dist[x] + 1;
					if (graph[x][i] == b)
						break;
					else que.push(graph[x][i]);
				}
			}
		}
		if (dist[b] == INT32_MAX)
			cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
