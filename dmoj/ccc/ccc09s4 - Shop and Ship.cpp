#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#define INF 2147384647
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj(5001);
bool visited[5001] = {};
int dist[5001];
pair<int, int> shops[5001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, T, x, y, C, K;
	scan(N); scan(T);
	fill(dist + 1, dist + N + 1, INF);
	for (int i = 0; i < T; i++)
	{
		scan(x); scan(y); scan(C);
		adj[x].push_back(make_pair(y, C));
		adj[y].push_back(make_pair(x, C));
	}
	scan(K);
	for (int i = 0; i < K; i++)
	{
		scan(x); scan(C);
		shops[i].first = x, shops[i].second = C;
	}
	scan(T);
	dist[T] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, T));
	while (!q.empty())
	{
		x = q.top().second;
		q.pop();
		visited[x] = 1;
		for (int i = 0; i < adj[x].size(); i++)
		{
			if (!visited[adj[x][i].first])
			{
				C = dist[x] + adj[x][i].second;
				if (C < dist[adj[x][i].first])
				{
					dist[adj[x][i].first] = C;
					q.push(make_pair(-C, adj[x][i].first));
				}
			}
		}
	}
	C = INF;
	for (int i = 0; i < K; i++)
	{
		if (dist[shops[i].first] + shops[i].second < C)
			C = dist[shops[i].first] + shops[i].second;
	}
	cout << C;
	return 0;
}
