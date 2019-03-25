#include <iostream>
#include <set>

using namespace std;

set<int> gates;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int G, P, g, c = 0;
	set<int>::iterator it;
	cin >> G >> P;
	for (int i = -1; i >= -G; i--)
		gates.insert(i);
	for (int i = 0; i < P; i++)
	{
		cin >> g;
		it = gates.lower_bound(-g);
		if (it != gates.end())
		{
			gates.erase(it);
			c++;
		}
		else break;
	}
	cout << c;
	return 0;
}
