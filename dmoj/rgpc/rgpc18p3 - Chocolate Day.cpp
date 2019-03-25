// RGPC '18 P3 - Chocolate Day
// AC Solution 1 (chenj)
#include <cstdio>
#define MAXN 1000001
using namespace std;

long long diff[MAXN];

int main() {
	int N, T, a, b, c, L;
	scanf("%d%d", &N, &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &c);
		diff[a - 1] += c, diff[b] -= c;
	}
	for (int i = 1; i < N; i++)
		diff[i] += diff[i - 1];
	scanf("%d", &L);
	int l = 0, r = 0, ans = 0;
	long long sum = diff[0];
	while (1) {
		if (sum <= L && r - l + 1 > ans)
			ans = r - l + 1;
		if (r == N - 1 && r - l + 1 <= ans)
			break;
		if (sum < L) {
			if (r < N - 1)
				sum += diff[++r];
			else break;
		}
		else sum -= diff[l++];
	}
	printf("%d\n", ans);
	return 0;
}
