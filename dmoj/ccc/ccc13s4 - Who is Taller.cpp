#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph(1000001);

bool isTaller(int x, int y)
{
	bool visited[1000001] = {};
	queue<int> q;
	visited[x] = 1;
	q.push(x);
	while (!q.empty())
	{
		x = q.front(), q.pop();
		for (int i = 0; i < graph[x].size(); i++)
		{
			if (graph[x][i] == y)
				return 1;
			else if (!visited[graph[x][i]])
			{
				visited[graph[x][i]] = 1;
				q.push(graph[x][i]);
			}
		}
	}
	return 0;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
    int N, M, x, y;
    scan(N); scan(M);
    while (M--)
    {
        scan(x); scan(y);
        graph[x].push_back(y);
    }
    scan(x); scan(y);
    if (isTaller(x, y))
        cout << "yes" << endl;
    else if (isTaller(y, x))
        cout << "no" << endl;
    else cout << "unknown" << endl;
	return 0;
}
