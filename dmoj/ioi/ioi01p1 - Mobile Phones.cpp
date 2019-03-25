#include <iostream>
using namespace std;

const int MAXN = 1025;
int bit[MAXN][MAXN], S;

void add(int x, int y, int v) {
	for (; x <= S; x += (x & -x)) {
		for (int j = y; j <= S; j += (j & -j))
			bit[x][j] += v;
	}
}

int sum(int x, int y) {
	int res = 0;
	for (; x > 0; x -= (x & -x)) {
		for (int j = y; j > 0; j -= (j & -j))
			res += bit[x][j];
	}
	return res;
}

int sum(int x1, int y1, int x2, int y2) {
	return sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x1 - 1, y2) - sum(x2, y1 - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int op, a, b, c, d;
	cin >> op >> S;
	while (cin >> op, op != 3)
	{
		cin >> a >> b >> c;
		if (op == 1)
			add(a + 1, b + 1, c);
		else {
			cin >> d;
			cout << sum(a + 1, b + 1, c + 1, d + 1) << '\n';
		}
	}
	return 0;
}
