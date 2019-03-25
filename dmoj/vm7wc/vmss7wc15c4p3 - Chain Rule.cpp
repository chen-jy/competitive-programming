#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> graph(100000);
int dist[100000], dist2[100000];
bool visited[100000] = {};
priority_queue<pair<int, int>> q;

const int INF = 2147384647;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, a, b, t;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> t;
		graph[a].push_back({ b, t });
		graph[b].push_back({ a, t });
		if (i < N)
			dist[i] = INF;
	}
	for (int i = M - 1; i < N; i++)
		dist[i] = INF;
	t = dist[0] = 0;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		a = q.top().second;
		q.pop();
		visited[a] = 1;
		for (int i = 0; i < graph[a].size(); i++)
		{
			if (!visited[graph[a][i].first])
			{
				b = dist[a] + graph[a][i].second;
				if (b < dist[graph[a][i].first])
				{
					dist[graph[a][i].first] = b;
					q.push({ -b, graph[a][i].first });
				}
			}
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		dist2[i] = INF;
		visited[i] = 0;
	}
	dist2[N - 1] = 0;
	q.push({ 0, N - 1 });
	while (!q.empty())
	{
		a = q.top().second;
		q.pop();
		visited[a] = 1;
		for (int i = 0; i < graph[a].size(); i++)
		{
			if (!visited[graph[a][i].first])
			{
				b = dist2[a] + graph[a][i].second;
				if (b < dist2[graph[a][i].first])
				{
					dist2[graph[a][i].first] = b;
					q.push({ -b, graph[a][i].first });
				}
			}
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		if (dist[i] + dist2[i] > t)
			t = dist[i] + dist2[i];
	}
	cout << t;
	return 0;
}
