#define inf INT32_MAX
#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int grid[25][25], oxy[25][25], n;

void DFS(int i, int j)
{
	if (i == n - 1 && j == n - 1)
		return;
	if (i - 1 >= 0 && abs(grid[i][j] - grid[i - 1][j]) <= 2)
	{
		if (grid[i][j] > grid[0][0] || grid[i - 1][j] > grid[0][0])
		{
			if (oxy[i][j] + 1 < oxy[i - 1][j])
			{
				oxy[i - 1][j] = oxy[i][j] + 1;
				DFS(i - 1, j);
			}
		}
		else
		{
			if (oxy[i][j] < oxy[i - 1][j])
			{
				oxy[i - 1][j] = oxy[i][j];
				DFS(i - 1, j);
			}
		}
	}
	if (i + 1 < n && abs(grid[i][j] - grid[i + 1][j]) <= 2)
	{
		if (grid[i][j] > grid[0][0] || grid[i + 1][j] > grid[0][0])
		{
			if (oxy[i][j] + 1 < oxy[i + 1][j])
			{
				oxy[i + 1][j] = oxy[i][j] + 1;
				DFS(i + 1, j);
			}
		}
		else
		{
			if (oxy[i][j] < oxy[i + 1][j])
			{
				oxy[i + 1][j] = oxy[i][j];
				DFS(i + 1, j);
			}
		}
	}
	if (j - 1 >= 0 && abs(grid[i][j] - grid[i][j - 1]) <= 2)
	{
		if (grid[i][j] > grid[0][0] || grid[i][j - 1] > grid[0][0])
		{
			if (oxy[i][j] + 1 < oxy[i][j - 1])
			{
				oxy[i][j - 1] = oxy[i][j] + 1;
				DFS(i, j - 1);
			}
		}
		else
		{
			if (oxy[i][j] < oxy[i][j - 1])
			{
				oxy[i][j - 1] = oxy[i][j];
				DFS(i, j - 1);
			}
		}
	}
	if (j + 1 < n && abs(grid[i][j] - grid[i][j + 1]) <= 2)
	{
		if (grid[i][j] > grid[0][0] || grid[i][j + 1] > grid[0][0])
		{
			if (oxy[i][j] + 1 < oxy[i][j + 1])
			{
				oxy[i][j + 1] = oxy[i][j] + 1;
				DFS(i, j + 1);
			}
		}
		else
		{
			if (oxy[i][j] < oxy[i][j + 1])
			{
				oxy[i][j + 1] = oxy[i][j];
				DFS(i, j + 1);
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> grid[i][j];
				oxy[i][j] = inf;
			}
		}
		oxy[0][0] = 0;
		DFS(0, 0);
		if (oxy[n - 1][n - 1] == inf)
			cout << "CANNOT MAKE THE TRIP\n\n";
		else cout << oxy[n - 1][n - 1] << "\n\n";
	}
	return 0;
}
