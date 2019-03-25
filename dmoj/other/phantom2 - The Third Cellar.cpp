#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primes;

void sieve(int N) {
	vector<bool> p(N + 1, 1);
	for (int i = 3; i <= N; i += 2) {
		if (p[i]) {
			primes.push_back(i);
			for (int j = i * i; j < N; j += i)
				p[j] = 0;
		}
	}
}

int ssieve(int N, int M) {
	int seg = ceil(sqrt(M)), lm, ans = 0;
	sieve(seg);
	vector<bool> p(20000001, 1);
	for (int i = 0; i < primes.size(); i++) {
		lm = floor(N / primes[i]) * primes[i];
		if (lm < N)
			lm += primes[i];
		for (int j = lm; j < M; j += primes[i])
			p[j - N] = 0;
		if (primes[i] >= N && primes[i] < M)
			p[primes[i] - N] = 1;
	}
	for (int i = N % 2 != 0 ? N : N + 1; i < M; i += 2) {
		if (p[i - N])
			ans++;
	}
	if (N == 2)
		ans++;
	return ans;
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int T, N, M;
	scan(T);
	while (T--) {
		scan(N); scan(M);
		cout << ssieve(N, M) << endl;
	}
	return 0;
}
