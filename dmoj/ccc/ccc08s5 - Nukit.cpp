// Bananas with memoization
#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

#include <iostream>
#include <map>
#include <tuple>

#define tfi tuple<int, int, int, int>
#define params int a, int b, int c, int d
#define param a, b, c, d

using namespace std;

map<tfi, bool> cache;

bool AABDD(params) { return a >= 2 && b >= 1 && d >= 2; }
bool ABCD(params) { return a >= 1 && b >= 1 && c >= 1 && d >= 1; }
bool CCD(params) { return c >= 2 && d >= 1; }
bool BBB(params) { return b >= 3; }
bool AD(params) { return a >= 1 && d >= 1; }

bool Lose(params);
bool Win(params)
{
	tfi t = make_tuple(param);
	auto it = cache.find(t);
	if (it != cache.end())
		return it->second == 1;

	if (AABDD(param) && Lose(a - 2, b - 1, c, d - 2)) {
		cache.insert(make_pair(t, 1));
		return 1;
	}
	if (ABCD(param) && Lose(a - 1, b - 1, c - 1, d - 1)) {
		cache.insert(make_pair(t, 1));
		return 1;
	}
	if (CCD(param) && Lose(a, b, c - 2, d - 1)) {
		cache.insert(make_pair(t, 1));
		return 1;
	}
	if (BBB(param) && Lose(a, b - 3, c, d)) {
		cache.insert(make_pair(t, 1));
		return 1;
	}
	if (AD(param) && Lose(a - 1, b, c, d - 1)) {
		cache.insert(make_pair(t, 1));
		return 1;
	}

	cache.insert(make_pair(t, 0));
	return 0;
}
bool Lose(params)
{
	tfi t = make_tuple(param);
	auto it = cache.find(t);
	if (it != cache.end())
		return it->second == 0;

	if (!AABDD(param) && !ABCD(param) && !CCD(param) && !BBB(param) && !AD(param)) {
		cache.insert(make_pair(t, 0));
		return 1;
	}

	bool g = 1;
	if (AABDD(param) && !Win(a - 2, b - 1, c, d - 2))
		g = 0;
	if (ABCD(param) && !Win(a - 1, b - 1, c - 1, d - 1))
		g = 0;
	if (CCD(param) && !Win(a, b, c - 2, d - 1))
		g = 0;
	if (BBB(param) && !Win(a, b - 3, c, d))
		g = 0;
	if (AD(param) && !Win(a - 1, b, c, d - 1))
		g = 0;

	if (g) {
		cache.insert(make_pair(t, 0));
		return 1;
	}
	cache.insert(make_pair(t, 1));
	return 0;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int n, a, b, c, d;
	scan(n);
	while (n--)
	{
		scan(a); scan(b); scan(c); scan(d);
		if (Win(param))
			cout << "Patrick" << endl;
		else cout << "Roland" << endl;
	}
	return 0;
}
