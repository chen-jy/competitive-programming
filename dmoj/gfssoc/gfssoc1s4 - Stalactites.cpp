#include <iostream>
using namespace std;

int N, val[251][251][251];
unsigned long long bit[251][251][251];

void add(int x, int y, int z, int v) {
	val[x][y][z] += v;
	for (int i = x; i <= N; i += i & -i) {
		for (int j = y; j <= N; j += j & -j) {
			for (int k = z; k <= N; k += k & -k)
				bit[i][j][k] += v;
		}
	}
}

void set(int x, int y, int z, int v) {
	int diff = v - val[x][y][z];
	add(x, y, z, diff);
}

unsigned long long sum(int x, int y, int z) {
	unsigned long long ans = 0;
	for (int i = x; i > 0; i -= i & -i) {
		for (int j = y; j > 0; j -= j & -j) {
			for (int k = z; k > 0; k -= k & -k)
				ans += bit[i][j][k];
		}
	}
	return ans;
}

unsigned long long sum(int x1, int y1, int z1, int x2, int y2, int z2) {
	return sum(x2, y2, z2) - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) + sum(x1 - 1, y1 - 1, z2) -
		sum(x2, y2, z1 - 1) + sum(x1 - 1, y2, z1 - 1) + sum(x2, y1 - 1, z1 - 1) - sum(x1 - 1, y1 - 1, z1 - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int Q, X1, Y1, Z1, X2, Y2, Z2, L;
	unsigned long long ans = 0;
	char op;
	cin >> N >> Q;
	while (Q--) {
		cin >> op >> X1 >> Y1 >> Z1;
		if (op == 'C') {
			cin >> L;
			set(X1, Y1, Z1, L);
		}
		else {
			cin >> X2 >> Y2 >> Z2;
			ans += sum(X1, Y1, Z1, X2, Y2, Z2);
		}
	}
	cout << ans << '\n';
	return 0;
}
