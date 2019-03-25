#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <cstring>

using namespace std;

// Finally learned adjacency matrix and dense Dijkstra's
int graph[101][101], item[101], items[101] = {}, dist[101];
bool vis[101] = {};

const int INF = 0x3f3f3f3f;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	memset(dist, INF, sizeof(dist));
	memset(graph, INF, sizeof(graph));
	int n, m, a, b, d;
	scan(n);
	for (int i = 1; i <= n; i++)
		scan(item[i]);
	scan(m);
	for (int i = 0; i < m; i++)
	{
		scan(a); scan(b); scan(d);
		graph[a][b] = graph[b][a] = d;
	}
	dist[1] = 0, items[1] = item[1];
	for (int i = 0; i < n; i++)
	{
		a = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j])
			{
				if (dist[j] < dist[a] || (dist[j] == dist[a] && items[j] > items[a]))
					a = j;
			}
		}
		vis[a] = 1;
		for (int j = 1; j <= n; j++)
		{
			d = dist[a] + graph[a][j], b = items[a] + item[j];
			if (d < dist[j] || (d == dist[j] && b > items[j]))
			{
				dist[j] = d;
				items[j] = b;
			}
		}
	}
	if (dist[n] != INF)
		cout << dist[n] << ' ' << items[n] << endl;
	else cout << "impossible" << endl;
	return 0;
}
