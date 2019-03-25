#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int dist[1001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, T, a, b, Q;
	vector<int> t;
	cin >> N >> M >> T;
	for (int i = 0; i <= N; i++)
	{
		graph.push_back(t);
		dist[i] = INT32_MAX;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}
	cin >> Q;
	for (int query = 0; query < Q; query++)
	{
		if (query != 0)
		{
			for (int i = 1; i <= N; i++)
				dist[i] = INT32_MAX;
		}
		cin >> a >> b;
		queue<int> que;
		dist[a] = 0;
		que.push(a);
		while (!que.empty())
		{
			M = que.front();
			que.pop();
			for (int i = 0; i < graph[M].size(); i++)
			{
				if (dist[graph[M][i]] == INT32_MAX)
				{
					dist[graph[M][i]] = dist[M] + 1;
					if (graph[M][i] == b)
						break;
					else que.push(graph[M][i]);
				}
			}
		}
		if (dist[b] == INT32_MAX)
			cout << "Not enough hallways!\n";
		else cout << dist[b] * T << '\n';;
	}
	return 0;
}
