#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<vector<int>> graph(101);
vector<queue<int>> antQue(15);
int dist[101];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, X, Y, W, turn = 0;
	bool g = 1;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		graph[X].push_back(Y);
		graph[Y].push_back(X);
		dist[i + 1] = INT32_MAX;
	}
	for (int i = M; i <= N; i++)
		dist[i] = INT32_MAX;
	cin >> W;
	for (int i = 0; i < W; i++)
	{
		cin >> X;
		antQue[i].push(X);
		dist[X] = -1;
	}
	queue<int> que;
	dist[1] = 0;
	que.push(1);
	while (!que.empty() && g)
	{
		X = que.front();
		que.pop();
		for (int i = 0; i < graph[X].size(); i++)
		{
			if (dist[graph[X][i]] == INT32_MAX)
			{
				dist[graph[X][i]] = dist[X] + 1;
				if (graph[X][i] == N)
					break;
				else que.push(graph[X][i]);
			}
		}
		if (dist[N] != INT32_MAX || que.empty())
			break;
		turn++;
		if (turn == 4)
		{
			turn = 0;
			for (int i = 0; i < W && g; i++)
			{
				Y = antQue[i].front();
				antQue[i].pop();
				for (int j = 0; j < graph[Y].size() && g; j++)
				{
					if (dist[graph[Y][j]] != -1)
					{
						dist[graph[Y][j]] = -1;
						if (graph[Y][j] == N)
							g = 0;
						else antQue[i].push(graph[Y][j]);
					}
				}
			}
		}
	}
	if (dist[N] > -1 && dist[N] < INT32_MAX)
		cout << dist[N];
	else cout << "sacrifice bobhob314";
	return 0;
}
