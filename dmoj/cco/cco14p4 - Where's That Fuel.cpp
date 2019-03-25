#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> pf;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, P, a, b, cf, p = 0, pv = 0;
	cin >> N >> P;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (i == P - 1)
		{
			cf = a;
			pv++;
		}
		else if (a >= b)
		{
			pf.push_back(make_pair(a, b));
			p++;
		}
	}
	sort(pf.begin(), pf.end());
	for (int i = 0; i < p; i++)
	{
		if (cf < pf[i].second) continue;
		cf += pf[i].first;
		cf -= pf[i].second;
		pv++;
	}
	cout << cf << "\n" << pv;
    return 0;
}
