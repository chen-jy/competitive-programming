#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> graph(100001);
bool vis[100001] = {};
unsigned long long dist[100001];

int main()
{
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	fill(dist, dist + 100001, ULLONG_MAX);
	int V, E, P, D, R, A, B, C;
	scan(V); scan(E); scan(P); scan(D); scan(R);
	while (E--)
	{
		scan(A); scan(B); scan(C);
		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}
	priority_queue<pair<int, int>> q, empty;
	q.push(make_pair(0, P));
	dist[P] = 0;
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		vis[x] = 1;
		for (int i = 0; i < graph[x].size(); i++)
		{
			if (!vis[graph[x][i].first])
			{
				unsigned long long d = dist[x] + graph[x][i].second;
				if (d < dist[graph[x][i].first])
				{
					dist[graph[x][i].first] = d;
					q.push(make_pair(-d, graph[x][i].first));
				}
			}
		}
	}
	if (!vis[D])
		cout << "Nooooooooo!!!" << endl;
	else
	{
		unsigned long long ans = dist[D];
		fill(vis, vis + 100001, false);
		fill(dist, dist + 100001, ULLONG_MAX);
		q = empty;
		q.push(make_pair(0, D));
		dist[D] = 0;
		while (!q.empty())
		{
			int x = q.top().second;
			q.pop();
			vis[x] = 1;
			for (int i = 0; i < graph[x].size(); i++)
			{
				if (!vis[graph[x][i].first])
				{
					unsigned long long d = dist[x] + graph[x][i].second;
					if (d < dist[graph[x][i].first])
					{
						dist[graph[x][i].first] = d;
						q.push(make_pair(-d, graph[x][i].first));
					}
				}
			}
		}
		unsigned long long price = 3;
		if (!vis[R])
		{
			if (ans > 10)
				price += 20, ans -= 10, price += ans;
			else price += 2 * ans;
			cout << price << endl << "Yippee!!!" << endl;
		}
		else
		{
			ans += dist[R];
			if (ans > 10)
				price += 20, ans -= 10, price += ans;
			else price += 2 * ans;
			cout << price << endl;
		}
	}
	return 0;
}
