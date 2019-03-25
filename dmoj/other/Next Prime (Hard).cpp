#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull mulmod(ull a, ull b, ull m) {
	ull x = 0, y = a % m;
	for (; b > 0; b >>= 1) {
		if (b & 1)
			x = (x + y) % m;
		y = (y << 1) % m;
	}
	return x % m;
}

ull powmod(ull a, ull b, ull m) {
	ull x = 1, y = a;
	for (; b > 0; b >>= 1) {
		if (b & 1)
			x = mulmod(x, y, m);
		y = mulmod(y, y, m);
	}
	return x % m;
}

bool is_prime(ull n) {
	static const ull det[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;
	if ((n & 1) == 0)
		return 0;
	ull d = n - 1;
	int s = 0;
	for (; ~d & 1; s++)
		d >>= 1;
	for (int i = 0; i < 7; i++) {
		if (det[i] > n - 2)
			break;
		ull x = powmod(det[i], d, n);
		if (x == 1 || x == n - 1)
			continue;
		bool g = 0;
		for (int j = 0; j < s; j++) {
			x = powmod(x, 2, n);
			if (x == 1)
				return 0;
			if (x == n - 1) {
				g = 1;
				break;
			}
		}
		if (!g)
			return 0;
	}
	return 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	ull N;
	cin >> N;
	if (N <= 2) {
		cout << 2 << endl;
		return 0;
	}
	if (N % 2 == 0)
		N++;
	while (!is_prime(N))
		N += 2;
	cout << N << endl;
	return 0;
}
