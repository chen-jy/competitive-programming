#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> graph(10000);
int memo[10000], n;

int DFS(int x)
{
	if (x == n)
		return 1;
	int t = 0;
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (memo[graph[x][i]] != -1)
			t += memo[graph[x][i]];
		else
		{
			memo[graph[x][i]] = DFS(graph[x][i]);
			t += memo[graph[x][i]];
		}
	}
	return t;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int x, y;
	cin >> n;
	while (cin >> x >> y, x != 0 && y != 0)
		graph[x].push_back(y);
	memset(memo, -1, sizeof(memo));
	cout << DFS(1);
	return 0;
}
