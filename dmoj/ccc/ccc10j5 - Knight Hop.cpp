#include <iostream>

using namespace std;

int grid[9][9], xa, ya, xb, yb;

void Explore(int i, int j, int counter)
{
	if (counter < grid[i][j])
	{
		grid[i][j] = counter;
		if (i == yb && j == xb)
			return;
		if (i - 2 >= 0 && j + 1 <= 8)
			Explore(i - 2, j + 1, counter + 1);
		if (i - 1 >= 0 && j + 2 <= 8)
			Explore(i - 1, j + 2, counter + 1);
		if (i + 1 <= 8 && j + 2 <= 8)
			Explore(i + 1, j + 2, counter + 1);
		if (i + 2 <= 8 && j + 1 <= 8)
			Explore(i + 2, j + 1, counter + 1);
		if (i + 2 <= 8 && j - 1 >= 0)
			Explore(i + 2, j - 1, counter + 1);
		if (i + 1 <= 8 && j - 2 >= 0)
			Explore(i + 1, j - 2, counter + 1);
		if (i - 1 >= 0 && j - 2 >= 0)
			Explore(i - 1, j - 2, counter + 1);
		if (i - 2 >= 0 && j - 1 >= 0)
			Explore(i - 2, j - 1, counter + 1);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
			grid[i][j] = 10000;
	}
	cin >> xa >> ya >> xb >> yb;
	Explore(ya, xa, 0);
	cout << grid[yb][xb];
	return 0;
}
