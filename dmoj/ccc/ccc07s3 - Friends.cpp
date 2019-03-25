#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <cstring>

using namespace std;

int graph[10000];
bool vis[10000];

int main()
{
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int n, x, y;
	bool g;
	scan(n);
	while (n--)
	{
		scan(x); scan(y);
		graph[x] = y;
	}
	while (cin >> x >> y, x != 0)
	{
		memset(vis, 0, sizeof(vis));
		n = 0, g = 0;
		while (1)
		{
			if (graph[x] == y)
			{
				g = 1;
				break;
			}
			if (vis[x])
				break;
			vis[x] = 1;
			x = graph[x];
			n++;
		}
		if (g)
			cout << "Yes " << n << endl;
		else cout << "No" << endl;
	}
	return 0;
}
