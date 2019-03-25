#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int clubs[32];
bool visited[5281];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int d, n, x, c, ans = 2147483647;
	cin >> d >> n;
	memset(visited, 0, sizeof(visited));
	queue<int> que;
	for (int i = 0; i < n; i++)
	{
		cin >> clubs[i];
		if (clubs[i] <= d)
		{
			que.push(clubs[i]);
			que.push(1);
			visited[clubs[i]] = 1;
		}
	}
	while (!que.empty())
	{
		x = que.front(), que.pop();
		c = que.front(), que.pop();
		for (int i = 0; i < n; i++)
		{
			if (x + clubs[i] <= d && !visited[x + clubs[i]])
			{
				if (x + clubs[i] == d && c + 1 < ans)
					ans = c + 1;
				else
				{
					que.push(x + clubs[i]);
					que.push(c + 1);
					visited[x + clubs[i]] = 1;
				}
			}
		}
	}
	if (ans == 2147483647)
		cout << "Roberta acknowledges defeat.";
	else cout << "Roberta wins in " << ans << " strokes.";
	return 0;
}
