#include <iostream>

using namespace std;

char maze[21][21];
int grid[21][21];
int r, c;

void Explore(int i, int j, int counter)
{
	if (grid[i][j] != -1 && counter < grid[i][j])
	{
		if (maze[i][j] == '*')
		{
			grid[i][j] = -1;
			return;
		}
		else if (maze[i][j] == '+')
		{
			grid[i][j] = counter;
			if (i > 0)
				Explore(i - 1, j, counter + 1);
			if (i < r - 1)
				Explore(i + 1, j, counter + 1);
			if (j > 0)
				Explore(i, j - 1, counter + 1);
			if (j < c - 1)
				Explore(i, j + 1, counter + 1);
		}
		else if (maze[i][j] == '|')
		{
			grid[i][j] = counter;
			if (i > 0)
				Explore(i - 1, j, counter + 1);
			if (i < r - 1)
				Explore(i + 1, j, counter + 1);
		}
		else if (maze[i][j] == '-')
		{
			grid[i][j] = counter;
			if (j > 0)
				Explore(i, j - 1, counter + 1);
			if (j < c - 1)
				Explore(i, j + 1, counter + 1);
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
	
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> maze[i][j];
				grid[i][j] = 100000;
			}
		}
		Explore(0, 0, 1);
		if (grid[r - 1][c - 1] != 100000)
			cout << grid[r - 1][c - 1] << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}
