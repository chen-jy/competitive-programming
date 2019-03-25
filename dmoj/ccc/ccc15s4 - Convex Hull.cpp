#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <queue>

using namespace std;

vector<vector<tuple<int, int, int>>> graph(2001);
int dist[2001][200];
bool inQ[2001] = {};

const int INF = 1195853639;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int K, N, M, a, b, t, h, A, B;
	scan(K); scan(N); scan(M);
	while (M--)
	{
		scan(a); scan(b); scan(t); scan(h);
		graph[a].push_back(make_tuple(b, t, h));
		graph[b].push_back(make_tuple(a, t, h));
	}
	scan(A); scan(B);
	memset(dist, INF, sizeof(dist));
	dist[A][0] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, A));
	while (!q.empty())
	{
		a = q.top().second, t = q.top().first;
		inQ[a] = 0;
		q.pop();
		for (int i = 0; i < graph[a].size(); i++)
		{
			b = get<0>(graph[a][i]);
			if (b == A)
				continue;
			for (int j = 0; j + get<2>(graph[a][i]) < K; j++)
			{
				t = dist[a][j] + get<1>(graph[a][i]), h = get<2>(graph[a][i]);
				if (t < dist[b][j + h])
				{
					dist[b][j + h] = t;
					if (!inQ[b])
					{
						inQ[b] = 1;
						q.push(make_pair(-t, b));
					}
				}
			}
		}
	}
	t = INF;
	for (int i = 0; i < K; i++)
	{
		if (dist[B][i] < t)
			t = dist[B][i];
	}
	if (t != INF)
		cout << t << '\n';
	else cout << "-1\n";
	return 0;
}
