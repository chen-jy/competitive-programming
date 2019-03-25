#include <cstdio>
#define MAXN 10000001
using namespace std;

int p[MAXN];

int main() {
	for (int i = 2; i <= MAXN; i++) {
		if (p[i] == 0) {
			for (int j = i; j <= MAXN; j += i)
				p[j]++;
		}
	}
	int T, A, B, K;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d", &A, &B, &K);
		int ans = 0;
		for (int j = A; j <= B; j++) {
			if (p[j] == K)
				ans++;
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
