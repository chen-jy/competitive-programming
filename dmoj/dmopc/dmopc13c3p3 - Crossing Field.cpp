#include <iostream>
#include <cstdlib>

using namespace std;

int grid[1500][1500], N, H;
bool visited[1500][1500], poss = 0;

void DFS(int i, int j)
{
	if (i == N - 1 && j == N - 1)
	{
		poss = 1;
		return;
	}
	visited[i][j] = 1;
	if (i >= 1 && abs(grid[i][j] - grid[i - 1][j]) <= H && visited[i - 1][j] == 0 && !poss)
		DFS(i - 1, j);
	if (i <= N - 2 && abs(grid[i][j] - grid[i + 1][j]) <= H && visited[i + 1][j] == 0 && !poss)
		DFS(i + 1, j);
	if (j >= 1 && abs(grid[i][j] - grid[i][j - 1]) <= H && visited[i][j - 1] == 0 && !poss)
		DFS(i, j - 1);
	if (j <= N - 2 && abs(grid[i][j] - grid[i][j + 1]) <= H && visited[i][j + 1] == 0 && !poss)
		DFS(i, j + 1);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	cin >> N >> H;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
			visited[i][j] = 0;
		}
	}
	DFS(0, 0);
	if (poss)
		cout << "yes";
	else cout << "no";
	return 0;
}
