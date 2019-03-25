#include <iostream>

using namespace std;

bool games[6]{ 0 };
int points[5]{ 0 };

void Play(int rem, int a, int b, int c, int d, int t)
{
	if (rem == 0)
	{
		if (t == 1)
		{
			if (a > b && a > c && a > d)
				points[4]++;
		}
		else if (t == 2)
		{
			if (b > a && b > c && b > d)
				points[4]++;
		}
		else if (t == 3)
		{
			if (c > a && c > b && c > d)
				points[4]++;
		}
		else if (t == 4)
		{
			if (d > a && d > b && d > c)
				points[4]++;
		}
		return;
	}
	int i = 0;
	for (; i < 6; i++)
	{
		if (games[i] == 0)
		{
			games[i] = 1;
			break;
		}
	}
	if (i == 0)
	{
		Play(rem - 1, a + 3, b, c, d, t);
		Play(rem - 1, a, b + 3, c, d, t);
		Play(rem - 1, a + 1, b + 1, c, d, t);
	}
	else if (i == 1)
	{
		Play(rem - 1, a + 3, b, c, d, t);
		Play(rem - 1, a, b, c + 3, d, t);
		Play(rem - 1, a + 1, b, c + 1, d, t);
	}
	else if (i == 2)
	{
		Play(rem - 1, a + 3, b, c, d, t);
		Play(rem - 1, a, b, c, d + 3, t);
		Play(rem - 1, a + 1, b, c, d + 1, t);
	}
	else if (i == 3)
	{
		Play(rem - 1, a, b + 3, c, d, t);
		Play(rem - 1, a, b, c + 3, d, t);
		Play(rem - 1, a, b + 1, c + 1, d, t);
	}
	else if (i == 4)
	{
		Play(rem - 1, a, b + 3, c, d, t);
		Play(rem - 1, a, b, c, d + 3, t);
		Play(rem - 1, a, b + 1, c, d + 1, t);
	}
	else if (i == 5)
	{
		Play(rem - 1, a, b, c + 3, d, t);
		Play(rem - 1, a, b, c, d + 3, t);
		Play(rem - 1, a, b, c + 1, d + 1, t);
	}
	games[i] = 0;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int T, G, A, B, sA, sB, c = 0;
	cin >> T >> G;
	for (int i = 0; i < G; i++)
	{
		cin >> A >> B >> sA >> sB;
		if (sA > sB) points[A - 1] += 3;
		else if (sA < sB) points[B - 1] += 3;
		else if (sA == sB)
		{
			points[A - 1]++;
			points[B - 1]++;
		}
		if (A == 1)
		{
			if (B == 2) games[0] = 1;
			else if (B == 3) games[1] = 1;
			else if (B == 4) games[2] = 1;
		}
		else if (A == 2)
		{
			if (B == 1) games[0] = 1;
			else if (B == 3) games[3] = 1;
			else if (B == 4) games[4] = 1;
		}
		else if (A == 3)
		{
			if (B == 1) games[1] = 1;
			else if (B == 2) games[3] = 1;
			else if (B == 4) games[5] = 1;
		}
		else if (A == 4)
		{
			if (B == 1) games[2] = 1;
			else if (B == 2) games[4] = 1;
			else if (B == 3) games[5] = 1;
		}
	}
	Play(6 - G, points[0], points[1], points[2], points[3], T);
	cout << points[4];
	return 0;
}
