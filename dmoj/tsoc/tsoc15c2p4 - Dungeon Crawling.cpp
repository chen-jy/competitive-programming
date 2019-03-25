#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> graph(20000);
set<int> entr, dest;
long long paths[20000];
int dist[20000];

long long pathDFS(int x)
{
	if (graph[x].size() == 0)
		return 1;
	long long t = 0;
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (paths[graph[x][i]] == -1)
		{
			paths[graph[x][i]] = pathDFS(graph[x][i]);
			t += paths[graph[x][i]];
		}
		else t += paths[graph[x][i]];
	}
	return t;
}

void shortDFS(int x)
{
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (dist[x] + 1 < dist[graph[x][i]])
		{
			dist[graph[x][i]] = dist[x] + 1;
			shortDFS(graph[x][i]);
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, a, b;
	long long p = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		entr.insert(i);
		paths[i] = -1;
		dist[i] = 2147384647;
	}
	dest = entr;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		if (entr.find(b) != entr.end())
			entr.erase(b);
		if (dest.find(a) != dest.end())
			dest.erase(a);
	}
	for (auto it = entr.begin(); it != entr.end(); ++it)
	{
		if (graph[*it].size() > 0)
		{
			paths[*it] = pathDFS(*it);
			p += paths[*it];
			dist[*it] = 1;
			shortDFS(*it);
		}
	}
	cout << p % 1000000007 << '\n';
	for (auto it = dest.begin();;)
	{
		if (dist[*it] != 2147384647)
			cout << dist[*it];
		++it;
		if (it == dest.end())
			break;
		cout << ' ';
	}
	return 0;
}
