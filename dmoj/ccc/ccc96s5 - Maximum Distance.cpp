#include <iostream>
#include <vector>

using namespace std;

vector<int> X, Y;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int T, n, x;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			X.push_back(x);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			Y.push_back(x);
		}
		x = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= i; j--)
			{
				if (j >= i && Y[j] >= X[i] && j - i > x)
				{
				    x = j - i;
				    break;
				}
			}
		}
		cout << "The maximum distance is " << x << '\n';
		X.clear(), Y.clear();
	}
	return 0;
}
