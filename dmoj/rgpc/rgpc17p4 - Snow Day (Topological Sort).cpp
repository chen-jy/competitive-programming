#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

#include <iostream>
#include <list>
#include <utility>
#include <cstring>
#define NINF -0x3f3f3f3f

using namespace std;

list<pair<int, int>> graph[1001];
list<int> sorted;
int  mark[1001] = {}, dist[1001], nodes[1001] = {};
bool cycle = 0;

void TopologicalSort(int x)
{
	if (mark[x] == -1)
	{
		cycle = 1;
		return;
	}
	if (mark[x] == 0)
	{
		mark[x] = -1;
		for (auto it = graph[x].begin(); it != graph[x].end(); ++it)
		{
			TopologicalSort(it->first);
			if (cycle)
				return;
		}
		mark[x] = 1;
		sorted.push_front(x);
	}
}

void LongestPath(int N)
{
	for (int i = 1; i <= N; i++)
	{
		if (mark[i] == 0)
			TopologicalSort(i);
		if (cycle)
		{
			cout << -1 << endl;
			return;
		}
	}
	if (!mark[N])
	{
		cout << -1 << endl;
		return;
	}
	memset(dist, NINF, sizeof(dist));
	dist[1] = 0, nodes[1] = 1;
	int x;
	while (!sorted.empty())
	{
		x = sorted.front(), sorted.pop_front();
		if (dist[x] != NINF)
		{
			for (auto it = graph[x].begin(); it != graph[x].end(); ++it)
			{
				if (dist[x] + it->second > dist[it->first])
				{
					dist[it->first] = dist[x] + it->second;
					nodes[it->first] = nodes[x] + 1;
				}
				else if (dist[x] + it->second == dist[it->first] && nodes[x] + 1 > nodes[it->first])
					nodes[it->first] = nodes[x] + 1;
			}
		}
	}
	cout << dist[N] << ' ' << nodes[N] << endl;
}

int main()
{
	int N, M, a, b, d;
	scan(N); scan(M);
	while (M--)
	{
		scan(a); scan(b); scan(d);
		graph[a].push_back(make_pair(b, d));
	}
	LongestPath(N);
	return 0;
}
