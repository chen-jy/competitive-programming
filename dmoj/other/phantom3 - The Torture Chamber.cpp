#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

vector<ull> primes;

void sieve(ull N) {
	vector<bool> p(N + 1, 1);
	for (ull i = 3; i <= N; i += 2) {
		if (p[i]) {
			primes.push_back(i);
			for (ull j = i * i; j < N; j += i)
				p[j] = 0;
		}
	}
}

ull ssieve(ull N, ull M) {
	ull seg = ceil(sqrt(M)), lm, ans = 0;
	sieve(seg);
	vector<bool> p(20000001, 1);
	for (ull i = 0; i < primes.size(); i++) {
		lm = floor(N / primes[i]) * primes[i];
		if (lm < N)
			lm += primes[i];
		for (ull j = lm; j < M; j += primes[i])
			p[j - N] = 0;
		if (primes[i] >= N && primes[i] < M)
			p[primes[i] - N] = 1;
	}
	for (ull i = N % 2 != 0 ? N : N + 1; i < M; i += 2) {
		if (p[i - N])
			ans++;
	}
	if (N == 2)
		ans++;
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	ull N, M;
	cin >> N >> M;
	cout << ssieve(N, M);
	return 0;
}
