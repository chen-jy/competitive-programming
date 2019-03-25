#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <map>

using namespace std;

unordered_set<int> stores;
vector<vector<pair<int, int>>> graph(2001);
int dist[2001];
multimap<int, int> vertexSet;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int T, N, M, G, A, B, L;
	map<int, int>::iterator it;
	cin >> T >> N >> M >> G;
	for (int i = 0; i < G; i++)
	{
		cin >> A;
		stores.insert(A);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> L;
		graph[A].push_back(make_pair(B, L));
	}
	for (int i = 1; i <= N; i++)
	{
		vertexSet.insert(make_pair(2147384647, i));
		dist[i] = 2147384647;
	}
	vertexSet.insert(make_pair(0, 0));
	dist[0] = B = 0;
	while (!vertexSet.empty())
	{
		it = vertexSet.begin();
		L = (*it).first, A = (*it).second;
		vertexSet.erase(it);
		if (dist[A] >= T)
			continue;
		if (stores.find(A) != stores.end())
		{
			B++;
			stores.erase(A);
		}
		for (int i = 0; i < graph[A].size(); i++)
		{
			G = dist[A] + graph[A][i].second;
			if (G < dist[graph[A][i].first])
			{
				it = vertexSet.find(dist[graph[A][i].first]);
				while ((*it).first == dist[graph[A][i].first] && (*it).second != graph[A][i].first)
					++it;
				vertexSet.erase(it);
				dist[graph[A][i].first] = G;
				vertexSet.insert(make_pair(G, graph[A][i].first));
			}
		}
	}
	cout << B;
    return 0;
}
