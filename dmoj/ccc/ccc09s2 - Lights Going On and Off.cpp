#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

char grid[31][9];
char gcopy[31][9];
unordered_set<string> exists;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int R, L;
	string pattern = "aaaaaaaa";
	cin >> R >> L;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < L; j++)
		{
			cin >> grid[i][j];
			if (i == R - 1)
				pattern[j] = grid[i][j];
		}
	}
	exists.insert(pattern);
	for (int i = 1; i < R; i++)
	{
		copy(&grid[0][0], &grid[0][0] + 31 * 9, &gcopy[0][0]);
		pattern = "aaaaaaaa";
		for (int j = i; j < R; j++)
		{
			for (int k = 0; k < L; k++)
			{
				if (gcopy[j][k] == gcopy[j - 1][k])
					gcopy[j][k] = '0';
				else gcopy[j][k] = '1';
			}
		}
		for (int j = 0; j < L; j++)
			pattern[j] = gcopy[R - 1][j];
		if (exists.find(pattern) == exists.end())
			exists.insert(pattern);
	}
	cout << exists.size();
	return 0;
}
