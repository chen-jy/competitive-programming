#include <iostream>

using namespace std;

char grid[100][100];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, T, x, y;
	cin >> N >> M >> T;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'O')
				x = j, y = i;
		}
	}
	int cd = 3, t = 0;
	while (1)
	{
		t++;
		if (t > T)
		{
			cout << "The observer stays within the grid.";
			return 0;
		}
		if (cd == 0)
		{
			if (y - 1 < 0)
				break;
			y--;
			if (grid[y][x] == '-')
			{
				cd = 1;
				grid[y][x] = '|';
			}
			else if (grid[y][x] == '\\')
			{
				cd = 2;
				grid[y][x] = '/';
			}
			else if (grid[y][x] == '/')
			{
				cd = 3;
				grid[y][x] = '\\';
			}
		}
		else if (cd == 1)
		{
			if (y + 1 >= M)
				break;
			y++;
			if (grid[y][x] == '-')
			{
				cd = 0;
				grid[y][x] = '|';
			}
			else if (grid[y][x] == '\\')
			{
				cd = 3;
				grid[y][x] = '/';
			}
			else if (grid[y][x] == '/')
			{
				cd = 2;
				grid[y][x] = '\\';
			}
		}
		else if (cd == 2)
		{
			if (x - 1 < 0)
				break;
			x--;
			if (grid[y][x] == '|')
			{
				cd = 3;
				grid[y][x] = '-';
			}
			else if (grid[y][x] == '/')
			{
				cd = 1;
				grid[y][x] = '\\';
			}
			else if (grid[y][x] == '\\')
			{
				cd = 0;
				grid[y][x] = '/';
			}
		}
		else
		{
			if (x + 1 >= N)
				break;
			x++;
			if (grid[y][x] == '|')
			{
				cd = 2;
				grid[y][x] = '-';
			}
			else if (grid[y][x] == '\\')
			{
				cd = 1;
				grid[y][x] = '/';
			}
			else if (grid[y][x] == '/')
			{
				cd = 0;
				grid[y][x] = '\\';
			}
		}
	}
	cout << "The observer leaves the grid after " << t << " tick(s).";
	return 0;
}
