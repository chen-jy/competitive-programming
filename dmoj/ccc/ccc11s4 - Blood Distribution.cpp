#include <iostream>
#include <iterator>

using namespace std;

int g[8], r[8], c = 0;
int cg[8], cr[8];

void Sub(int a, int b)
{
	if (g[a] > 0)
	{
		if (g[a] >= r[b])
		{
			c += r[b];
			g[a] -= r[b];
			r[b] = 0;
		}
		else
		{
			c += g[a];
			r[b] -= g[a];
			g[a] = 0;
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int in, a;
	for (int i = 0; i < 8; i++)
	{
		cin >> in;
		g[i] = in;
		cg[i] = in;
	}
	for (int i = 0; i < 8; i++)
	{
		cin >> in;
		r[i] = in;
		cr[i] = in;
	}
	Sub(0, 0);
	Sub(1, 1); Sub(0, 1);
	Sub(2, 2); Sub(0, 2);
	Sub(4, 4); Sub(0, 4);
	Sub(3, 3); Sub(1, 3);
	Sub(5, 5); Sub(1, 5);
	Sub(2, 3); Sub(0, 3);
	Sub(4, 5); Sub(0, 5);
	Sub(6, 6); Sub(4, 6);
	Sub(2, 6); Sub(0, 6);
	for (int i = 7; i >= 0; i--)
		Sub(i, 7);
	a = c; c = 0;
	copy(begin(cg), end(cg), begin(g));
	copy(begin(cr), end(cr), begin(r));
	Sub(0, 0);
	Sub(1, 1); Sub(0, 1);
	Sub(2, 2); Sub(0, 2);
	Sub(4, 4); Sub(0, 4);
	Sub(3, 3); Sub(2, 3);
	Sub(5, 5); Sub(4, 5);
	Sub(1, 3); Sub(0, 3);
	Sub(1, 5); Sub(0, 5);
	Sub(6, 6); Sub(4, 6);
	Sub(2, 6); Sub(0, 6);
	for (int i = 7; i >= 0; i--)
		Sub(i, 7);
	if (c > a) cout << c;
	else cout << a;
	return 0;
}
