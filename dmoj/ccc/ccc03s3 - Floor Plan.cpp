#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char grid[25][25];
vector<int> rooms;
int r, c, counter;

void Explore(int i, int j)
{
	if (grid[i][j] == 'I' || grid[i][j] == 'X')
		return;
	grid[i][j] = 'X';
	counter++;
	if (i > 0)
		Explore(i - 1, j);
	if (i < r - 1)
		Explore(i + 1, j);
	if (j > 0)
		Explore(i, j - 1);
	if (j < c - 1)
		Explore(i, j + 1);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int f;
	cin >> f >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> grid[i][j];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (grid[i][j] == 'I' || grid[i][j] == 'X')
				continue;
			else
			{
				counter = 0;
				Explore(i, j);
				rooms.push_back(counter);
			}
		}
	}
	counter = 0;
	sort(rooms.begin(), rooms.end());
	for (int i = rooms.size() - 1; i >= 0; i--)
	{
		if (f < rooms[i])
			break;
		counter++;
		f -= rooms[i];
	}
	if (counter == 1)
		cout << "1 room, " << f << " square metre(s) left over";
	else cout << counter << " rooms, " << f << " square metre(s) left over";
	return 0;
}
