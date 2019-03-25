#define connect(x, y) con.insert(make_pair(x, y)); con.insert(make_pair(y, x))
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

multimap<int, int> con;
multimap<int, int>::iterator it;
map<int, int> visited;
unordered_set<int> direct;
unordered_set<int> done;
int sR;

void Initialize()
{
	connect(1, 6); connect(2, 6); connect(3, 4); connect(3, 5);
	connect(3, 6); connect(3, 15); connect(4, 5); connect(4, 6);
	connect(5, 6); connect(6, 7); connect(7, 8); connect(8, 9);
	connect(9, 10); connect(9, 12); connect(10, 11); connect(11, 12);
	connect(12, 13); connect(13, 14); connect(13, 15); connect(16, 17);
	connect(16, 18); connect(17, 18);
}

int NoF(int x)
{
	int c = 0;
	for (it = con.find(x); it != con.end(); ++it)
	{
		if ((*it).first != x)
			break;
		c++;
	}
	return c;
}

void DoS(int x, int y, int counter)
{
	multimap<int, int>::iterator itt = visited.find(x);
	if (itt != visited.end())
	{
		if ((*itt).second <= counter)
			return;
	}
	for (itt = con.find(x); itt != con.end(); ++itt)
	{
		if ((*itt).first != x)
			return;
		if ((*itt).second == y)
		{
			if (counter < sR)
			{
				sR = counter;
				return;
			}
		}
		visited.insert(make_pair(x, counter));
		DoS((*itt).second, y, counter + 1);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	Initialize();
	char op;
	int x, y;
	bool g;
	while (cin >> op)
	{
		if (op == 'q')
			break;
		else if (op == 'i')
		{
			g = 1;
			cin >> x >> y;
			for (it = con.find(x); it != con.end() && g; ++it)
			{
				if ((*it).first != x)
					break;
				if ((*it).second == y)
					g = 0;
			}
			if (g)
				connect(x, y);
		}
		else if (op == 'd')
		{
			g = 0;
			cin >> x >> y;
			for (it = con.find(x); it != con.end() && !g; ++it)
			{
				if ((*it).first != x)
					break;
				if ((*it).second == y)
				{
					con.erase(it);
					g = 1;
					break;
				}
			}
			if (g)
			{
				for (it = con.find(y); it != con.end(); ++it)
				{
					if ((*it).first != y)
						break;
					if ((*it).second == x)
					{
						con.erase(it);
						break;
					}
				}
			}
		}
		else if (op == 'n')
		{
			cin >> x;
			cout << NoF(x) << '\n';
		}
		else if (op == 'f')
		{
			direct.clear();
			done.clear();
			y = 0;
			cin >> x;
			direct.insert(x);
			for (it = con.find(x); it != con.end(); ++it)
			{
				if ((*it).first != x)
					break;
				direct.insert((*it).second);
			}
			for (it = con.find(x); it != con.end(); ++it)
			{
				if ((*it).first != x)
					break;
				for (auto itt = con.find((*it).second); itt != con.end(); ++itt)
				{
					if ((*itt).first != (*it).second)
						break;
					if (direct.find((*itt).second) == direct.end() &&
						done.find((*itt).second) == done.end())
					{
						done.insert((*itt).second);
						y++;
					}
				}
			}
			cout << y << '\n';
		}
		else if (op == 's')
		{
			visited.clear();
			sR = 10000;
			cin >> x >> y;
			DoS(x, y, 1);
			if (sR == 10000)
				cout << "Not connected\n";
			else cout << sR << '\n';
		}
	}
	return 0;
}
