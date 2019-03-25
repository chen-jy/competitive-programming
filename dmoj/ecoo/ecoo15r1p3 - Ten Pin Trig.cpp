#include <iostream>
#include <cmath>

using namespace std;

double ppos[10][2];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	for (int test = 0; test < 10; test++)
	{
		double X, Xc, Xe, Y, Yc, Ye, S, Sc, Se, N, a, b, c;
		cin >> Xc >> Xe >> Yc >> Ye >> Sc >> Se >> N;
		X = Xc * (pow(10, Xe));
		Y = Yc * (pow(10, Ye));
		S = Sc * (pow(10, Se));
		c = S / 3.0;
		a = c * 0.5;
		b = c * (sqrt(3) / 2);
		double r2 = Y + b, r3 = r2 + b, r4 = r3 + b;
		ppos[0][0] = X; ppos[0][1] = Y;
		ppos[1][0] = X - a; ppos[1][1] = r2;
		ppos[2][0] = X + a; ppos[2][1] = r2;
		ppos[3][0] = ppos[1][0] - a; ppos[3][1] = r3;
		ppos[4][0] = ppos[1][0] + a; ppos[4][1] = r3;
		ppos[5][0] = ppos[2][0] + a; ppos[5][1] = r3;
		ppos[6][0] = ppos[3][0] - a; ppos[6][1] = r4;
		ppos[7][0] = ppos[3][0] + a; ppos[7][1] = r4;
		ppos[8][0] = ppos[5][0] - a; ppos[8][1] = r4;
		ppos[9][0] = ppos[5][0] + a; ppos[9][1] = r4;
		for (int query = 0; query < 5; query++)
		{
			double sd = 10000.0, t;
			int pn;
			cin >> Xc >> Xe >> Yc >> Ye;
			X = Xc * (pow(10, Xe));
			Y = Yc * (pow(10, Ye));
			for (int i = 0; i < 10; i++)
			{
				t = sqrt(pow(ppos[i][1] - Y, 2) + pow(ppos[i][0] - X, 2));
				if (t < sd)
				{
					sd = t;
					pn = i + 1;
				}
			}
			cout << pn << ' ';
		}
		cout << '\n';
	}
	return 0;
}
