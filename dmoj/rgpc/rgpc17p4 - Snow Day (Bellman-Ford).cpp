#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#define MAXN 1001
#define INF LLONG_MAX
using namespace std;

typedef long long ll;
struct edge { int a, b, d; };

ll dist[MAXN];
int pred[MAXN];
vector<edge> e;

bool bellman_ford(int nodes)
{
	fill(dist, dist + MAXN, INF);
	fill(pred, pred + MAXN, -1);
	dist[1] = 0;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < (int)e.size(); j++)
		{
			if (dist[e[j].a] + e[j].d < dist[e[j].b])
			{
				dist[e[j].b] = dist[e[j].a] + e[j].d;
				pred[e[j].b] = e[j].a;
			}
		}
	}
	for (int i = 0; i < (int)e.size(); i++)
	{
		if (dist[e[i].a] + e[i].d < dist[e[i].b])
			return 0;
	}
	return 1;
}

int reconstruct_path(int x)
{
	int i = 0, j = x, counter = 0;
	while (pred[j] != -1)
		j = pred[j], counter++;
	return counter + 1;
}

int main()
{
	int N, M, a, b, d;
	scan(N); scan(M);
	while (M--)
	{
		scan(a); scan(b); scan(d);
		e.push_back({ a, b, -d });
	}
	if (bellman_ford(N))
		cout << -dist[N] << ' ' << reconstruct_path(N) << endl;
	else cout << -1 << endl;
	return 0;
}
