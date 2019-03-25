#include <iostream>
#include <queue>

using namespace std;

int cube[150][150][150], dist[150][150][150];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int X, Y, Z, x, y, z, T = 2147483647;
	char in;
	cin >> X >> Y >> Z;
	for (int i = 0; i < Z; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			for (int k = 0; k < X; k++)
			{
				cin >> in;
				if (in != 'J')
				{
					cube[i][j][k] = in - '0';
					dist[i][j][k] = 2147483647;
				}
				else
				{
					x = k, y = j, z = i;
					cube[i][j][k] = 0;
					dist[i][j][k] = 0;
				}
			}
		}
	}
	queue<int> que;
	que.push(x), que.push(y), que.push(z);
	while (!que.empty())
	{
		x = que.front(), que.pop();
		y = que.front(), que.pop();
		z = que.front(), que.pop();
		if (x == 0 || x == X - 1 || y == 0 || y == Y - 1 || z == 0 || z == Z - 1)
		{
			if (dist[z][y][x] < T)
				T = dist[z][y][x];
			continue;
		}
		if (x - 1 >= 0 && dist[z][y][x] + cube[z][y][x - 1] < dist[z][y][x - 1])
		{
			dist[z][y][x - 1] = dist[z][y][x] + cube[z][y][x - 1];
			que.push(x - 1), que.push(y), que.push(z);
		}
		if (x + 1 < X && dist[z][y][x] + cube[z][y][x + 1] < dist[z][y][x + 1])
		{
			dist[z][y][x + 1] = dist[z][y][x] + cube[z][y][x + 1];
			que.push(x + 1), que.push(y), que.push(z);
		}
		if (y - 1 >= 0 && dist[z][y][x] + cube[z][y - 1][x] < dist[z][y - 1][x])
		{
			dist[z][y - 1][x] = dist[z][y][x] + cube[z][y - 1][x];
			que.push(x), que.push(y - 1), que.push(z);
		}
		if (y + 1 < Y && dist[z][y][x] + cube[z][y + 1][x] < dist[z][y + 1][x])
		{
			dist[z][y + 1][x] = dist[z][y][x] + cube[z][y + 1][x];
			que.push(x), que.push(y + 1), que.push(z);
		}
		if (z - 1 >= 0 && dist[z][y][x] + cube[z - 1][y][x] < dist[z - 1][y][x])
		{
			dist[z - 1][y][x] = dist[z][y][x] + cube[z - 1][y][x];
			que.push(x), que.push(y), que.push(z - 1);
		}
		if (z + 1 < X && dist[z][y][x] + cube[z + 1][y][x] < dist[z + 1][y][x])
		{
			dist[z + 1][y][x] = dist[z][y][x] + cube[z + 1][y][x];
			que.push(x), que.push(y), que.push(z + 1);
		}
	}
	cout << T;
	return 0;
}
