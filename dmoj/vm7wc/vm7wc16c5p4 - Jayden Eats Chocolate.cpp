#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int pieces[100001] = {};

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	memset(pieces, -1, sizeof(pieces));
	pieces[0] = 0;
	int N, X, Y, Z;
	cin >> N >> X >> Y >> Z;

	for (int i = 1; i <= N; i++)
	{
	    int a = -1, b = -1, c= -1;

		if (i - X >= 0 && pieces[i - X] + 1 > pieces[i])
			a =  pieces[i - X];
		if (i - Y >= 0 && pieces[i - Y] + 1 > pieces[i])
			b = pieces[i - Y];
		if (i - Z >= 0 && pieces[i - Z] + 1 > pieces[i])
			c = pieces[i - Z];

			if (a != -1 || b != -1 || c != -1)
			{
			    pieces[i] = max(a,max(b,c)) + 1;
			}
	}
	cout << pieces[N] << endl;
	return 0;
}
