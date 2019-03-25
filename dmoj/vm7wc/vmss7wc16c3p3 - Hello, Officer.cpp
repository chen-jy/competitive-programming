#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

vector<vector<pair<int, int>>> graph(2001);
multimap<int, int> vertexSet;
int dist[2001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, B, Q, X, Y, Z;
	multimap<int, int>::iterator it;
	cin >> N >> M >> B >> Q;
	for (int i = 1; i <= M; i++)
	{
		cin >> X >> Y >> Z;
		graph[X].push_back(make_pair(Y, Z));
		graph[Y].push_back(make_pair(X, Z));
		if (i <= N && i != B)
		{
			dist[i] = 2147384647;
			vertexSet.insert(make_pair(2147384647, i));
		}
	}
	for (int i = M + 1; i <= N; i++)
	{
		if (i != B)
		{
			dist[i] = 2147384647;
			vertexSet.insert(make_pair(2147384647, i));
		}
	}
	dist[B] = 0;
	vertexSet.insert(make_pair(0, B));
	while (!vertexSet.empty())
	{
		X = (*vertexSet.begin()).second;
		vertexSet.erase(vertexSet.begin());
		for (int i = 0; i < graph[X].size(); i++)
		{
			Y = dist[X] + graph[X][i].second;
			if (Y < dist[graph[X][i].first])
			{
				it = vertexSet.find(dist[graph[X][i].first]);
				while ((*it).first == dist[graph[X][i].first] && (*it).second != graph[X][i].first)
					++it;
				vertexSet.erase(it);
				dist[graph[X][i].first] = Y;
				vertexSet.insert(make_pair(Y, graph[X][i].first));
			}
		}
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> X;
		if (dist[X] != 2147384647)
			cout << dist[X] << '\n';
		else cout << -1 << '\n';
	}
    return 0;
}
