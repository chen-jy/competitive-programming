#define Enqueue(x, y) que.push(x); que.push(y)
#define Dequeue(x, y) x = que.front(), que.pop(); y = que.front(), que.pop()
#include <iostream>
#include <queue>

using namespace std;

char grid[200][200];
bool visited[200][200] = {};

// Absolutely ridiculous problem
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);

	for (int test = 0; test < 10; test++)
	{
		int W, H, hx, hy, sx, sy, jx, jy, cx, cy, fx, fy, tx, ty, x, y;
		bool c = 0, f = 0, t = 0;
		cin >> W >> H;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> grid[i][j];

				if (grid[i][j] == 'h')
				{
					hx = j, hy = i;
					grid[i][j] = '.';
				}
				else if (grid[i][j] == 's')
				{
					sx = j, sy = i;
					grid[i][j] = '.';
				}
				else if (grid[i][j] == 'j')
				{
					jx = j, jy = i;
					grid[i][j] = '.';
				}

				else if (grid[i][j] == 'C')
				{
					cx = j, cy = i;
					grid[i][j] = '.';
				}
				else if (grid[i][j] == 'F')
				{
					fx = j, fy = i;
					grid[i][j] = '.';
				}
				else if (grid[i][j] == 'T')
				{
					tx = j, ty = i;
					grid[i][j] = '.';
				}
			}
		} // End grid input

		queue<int> que, empty;

		// Hop
		// Should write a function; copy-paste works too
		que.push(hx), que.push(hy);
		while (!que.empty())
		{
			Dequeue(x, y);
			visited[y][x] = 1;

			if (x == cx && y == cy)
				c = 1;
			else if (x == fx && y == fy)
				f = 1;
			else if (x == tx && y == ty)
				t = 1;
			if (c && f && t)
				break;

			if (y == H - 1)
				continue;

			// Falling
			if (y + 1 < H && grid[y][x] == '.' && grid[y + 1][x] == '.')
			{
				// Never fallen here, keep falling
				if (!visited[y + 1][x])
				{
					Enqueue(x, y + 1);
					visited[y + 1][x] = 1;
				}
				continue;
			}
			// Move left
			if (x - 1 >= 0 && grid[y][x - 1] != '=' && !visited[y][x - 1])
			{
				Enqueue(x - 1, y);
				visited[y][x - 1] = 1;
			}
			// Move right
			if (x + 1 < W && grid[y][x + 1] != '=' && !visited[y][x + 1])
			{
				Enqueue(x + 1, y);
				visited[y][x + 1] = 1;
			}
			// Climb up
			if (y - 1 >= 0 && grid[y][x] == '#' && grid[y - 1][x] != '=' && !visited[y - 1][x])
			{
				Enqueue(x, y - 1);
				visited[y - 1][x] = 1;
			}
			// Climb down
			if (y + 1 < H && grid[y + 1][x] == '#' && !visited[y + 1][x])
			{
				Enqueue(x, y + 1);
				visited[y + 1][x] = 1;
			}

			// Hop
			if (y - 1 >= 0 && grid[y - 1][x] != '=')
			{
				// Left
				if (x - 1 >= 0 && grid[y - 1][x - 1] != '=' && !visited[y - 1][x - 1])
				{
					Enqueue(x - 1, y - 1);
					visited[y - 1][x - 1] = 1;
				}
				// Right
				if (x + 1 < W && grid[y - 1][x + 1] != '=' && !visited[y - 1][x + 1])
				{
					Enqueue(x + 1, y - 1);
					visited[y - 1][x - 1] = 1;
				}
				// Up
				if (!visited[y - 1][x])
				{
					Enqueue(x, y - 1);
					visited[y - 1][x] = 1;
				}
			}
		}

		cout << "HOP";
		if (c || f || t)
			cout << ' ';
		if (c)
			cout << 'C';
		if (f)
			cout << 'F';
		if (t)
			cout << 'T';
		cout << '\n';

		// Reset
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				visited[i][j] = 0;
		}
		c = f = t = 0;
		que = empty;

		// Hop
		que.push(sx), que.push(sy);
		while (!que.empty())
		{
			Dequeue(x, y);
			visited[y][x] = 1;

			if (x == cx && y == cy)
				c = 1;
			else if (x == fx && y == fy)
				f = 1;
			else if (x == tx && y == ty)
				t = 1;
			if (c && f && t)
				break;

			if (y == H - 1)
				continue;

			// Falling
			if (y + 1 < H && grid[y][x] == '.' && grid[y + 1][x] == '.')
			{
				// Never fallen here, keep falling
				if (!visited[y + 1][x])
				{
					Enqueue(x, y + 1);
					visited[y + 1][x] = 1;
				}
				continue;
			}
			// Move left
			if (x - 1 >= 0 && grid[y][x - 1] != '=' && !visited[y][x - 1])
			{
				Enqueue(x - 1, y);
				visited[y][x - 1] = 1;
			}
			// Move right
			if (x + 1 < W && grid[y][x + 1] != '=' && !visited[y][x + 1])
			{
				Enqueue(x + 1, y);
				visited[y][x + 1] = 1;
			}
			// Climb up
			if (y - 1 >= 0 && grid[y][x] == '#' && grid[y - 1][x] != '=' && !visited[y - 1][x])
			{
				Enqueue(x, y - 1);
				visited[y - 1][x] = 1;
			}
			// Climb down
			if (y + 1 < H && grid[y + 1][x] == '#' && !visited[y + 1][x])
			{
				Enqueue(x, y + 1);
				visited[y + 1][x] = 1;
			}

			// Skip left
			if (x - 2 >= 0 && grid[y][x - 1] != '=' && grid[y][x - 2] != '=' && !visited[y][x - 2])
			{
				Enqueue(x - 2, y);
				visited[y][x - 2] = 1;
			}
			// Skip right
			if (x + 2 < W && grid[y][x + 1] != '=' && grid[y][x + 2] != '=' && !visited[y][x + 2])
			{
				Enqueue(x + 2, y);
				visited[y][x + 2] = 1;
			}
		}

		cout << "SKIP";
		if (c || f || t)
			cout << ' ';
		if (c)
			cout << 'C';
		if (f)
			cout << 'F';
		if (t)
			cout << 'T';
		cout << '\n';

		// Reset
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				visited[i][j] = 0;
		}
		c = f = t = 0;
		que = empty;

		// Jump
		que.push(jx), que.push(jy);
		while (!que.empty())
		{
			Dequeue(x, y);
			visited[y][x] = 1;

			if (x == cx && y == cy)
				c = 1;
			else if (x == fx && y == fy)
				f = 1;
			else if (x == tx && y == ty)
				t = 1;
			if (c && f && t)
				break;

			if (y == H - 1)
				continue;

			// Falling
			if (y + 1 < H && grid[y][x] == '.' && grid[y + 1][x] == '.')
			{
				// Never fallen here, keep falling
				if (!visited[y + 1][x])
				{
					Enqueue(x, y + 1);
					visited[y + 1][x] = 1;
				}
				continue;
			}
			// Move left
			if (x - 1 >= 0 && grid[y][x - 1] != '=' && !visited[y][x - 1])
			{
				Enqueue(x - 1, y);
				visited[y][x - 1] = 1;
			}
			// Move right
			if (x + 1 < W && grid[y][x + 1] != '=' && !visited[y][x + 1])
			{
				Enqueue(x + 1, y);
				visited[y][x + 1] = 1;
			}
			// Climb up
			if (y - 1 >= 0 && grid[y][x] == '#' && grid[y - 1][x] != '=' && !visited[y - 1][x])
			{
				Enqueue(x, y - 1);
				visited[y - 1][x] = 1;
			}
			// Climb down
			if (y + 1 < H && grid[y + 1][x] == '#' && !visited[y + 1][x])
			{
				Enqueue(x, y + 1);
				visited[y + 1][x] = 1;
			}

			// Hop
			if (y - 1 >= 0 && grid[y - 1][x] != '=')
			{
				// Left
				if (x - 1 >= 0 && grid[y - 1][x - 1] != '=' && !visited[y - 1][x - 1])
				{
					Enqueue(x - 1, y - 1);
					visited[y - 1][x - 1] = 1;
					// High jump left
					if (x - 2 >= 0 && grid[y - 1][x - 2] != '=' && !visited[y - 1][x - 2])
					{
						Enqueue(x - 2, y - 1);
						visited[y - 1][x - 2] = 1;
					}
				}
				// Right
				if (x + 1 < W && grid[y - 1][x + 1] != '=' && !visited[y - 1][x + 1])
				{
					Enqueue(x + 1, y - 1);
					visited[y - 1][x - 1] = 1;
					// High jump right
					if (x + 2 < W && grid[y - 1][x + 2] != '=' && !visited[y - 1][x + 2])
					{
						Enqueue(x + 2, y - 1);
						visited[y - 1][x + 2] = 1;
					}
				}
				// Up
				if (!visited[y - 1][x])
				{
					Enqueue(x, y - 1);
					visited[y - 1][x] = 1;
					// Spring jump
					if (y - 2 >= 0 && grid[y - 2][x] != '=' && !visited[y - 2][x])
					{
						Enqueue(x, y - 2);
						visited[y - 2][x] = 1;
					}
				}
			}

			// Skip left
			if (x - 2 >= 0 && grid[y][x - 1] != '=' && grid[y][x - 2] != '=' && !visited[y][x - 2])
			{
				Enqueue(x - 2, y);
				visited[y][x - 2] = 1;
			}
			// Long jump left
			if (x - 3 >= 0 && grid[y][x - 1] != '=' && grid[y][x - 2] != '=' && grid[y][x - 3] != '=' && !visited[y][x - 3])
			{
				Enqueue(x - 3, y);
				visited[y][x - 3] = 1;
			}
			// Skip right
			if (x + 2 < W && grid[y][x + 1] != '=' && grid[y][x + 2] != '=' && !visited[y][x + 2])
			{
				Enqueue(x + 2, y);
				visited[y][x + 2] = 1;
			}
			// Long jump right
			if (x + 3 < W && grid[y][x + 1] != '=' && grid[y][x + 2] != '=' && grid[y][x + 3] != '=' && !visited[y][x + 3])
			{
				Enqueue(x + 3, y);
				visited[y][x + 3] = 1;
			}
		}

		cout << "JUMP";
		if (c || f || t)
			cout << ' ';
		if (c)
			cout << 'C';
		if (f)
			cout << 'F';
		if (t)
			cout << 'T';
		cout << '\n';

		if (test != 9)
		{
			// Reset
			for (int i = 0; i < H; i++)
			{
				for (int j = 0; j < W; j++)
					visited[i][j] = 0;
			}
			cout << '\n';
		}
	}
	return 0;
}
