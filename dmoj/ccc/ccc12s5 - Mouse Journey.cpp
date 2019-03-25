#include <iostream>

using namespace std;

int paths[26][26] = {};
bool visited[26][26] = {};
int R, C;

int DFS(int x, int y)
{
	if (x == C && y == R)
		return 1;
	int t = 0;
	if (x + 1 <= C && !visited[y][x + 1])
	{
		if (paths[y][x + 1] > 0)
			t += paths[y][x + 1];
		else
		{
			visited[y][x + 1] = 1;
			paths[y][x + 1] = DFS(x + 1, y);
			visited[y][x + 1] = 0;
			t += paths[y][x + 1];
		}
	}
	if (y + 1 <= R && !visited[y + 1][x])
	{
		if (paths[y + 1][x] > 0)
			t += paths[y + 1][x];
		else
		{
			visited[y + 1][x] = 1;
			paths[y + 1][x] = DFS(x, y + 1);
			visited[y + 1][x] = 0;
			t += paths[y + 1][x];
		}
	}
	return t;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int K, x, y;
	cin >> R >> C >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		visited[x][y] = 1;
	}
	visited[1][1] = 1;
	cout << DFS(1, 1);
	return 0;
}
