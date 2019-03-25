#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph(10001);
int cherries[10001], weights[10001], outdegree[10001] = {};
unordered_set<int> starts;
int C, K, ans = 0;

void DFS(int x, int c, int k)
{
	cherries[x] += c;
	weights[x] += k;
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (graph[x][i] == 1)
			continue;
		if (outdegree[graph[x][i]] > 1)
		{
			cherries[graph[x][i]] += cherries[x];
			weights[graph[x][i]] += weights[x];
			outdegree[graph[x][i]]--;
			continue;
		}
		else if (outdegree[graph[x][i]] == 1 && weights[x] + weights[graph[x][i]] <= K)
		{
			if (cherries[x] + cherries[graph[x][i]] >= C)
				ans++;
			DFS(graph[x][i], cherries[x], weights[x]);
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, a, b, k;
	cin >> N >> C >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> cherries[i];
		starts.insert(i);
	}
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> k;
		graph[b].push_back(a);
		weights[b] = k;
		outdegree[a]++;
		if (starts.find(a) != starts.end())
			starts.erase(a);
	}
	for (auto it = starts.begin(); it != starts.end(); ++it)
	{
		if (cherries[*it] >= C && weights[*it] <= K)
			ans++;
		DFS(*it, 0, 0);
	}
	cout << ans;
    return 0;
}
