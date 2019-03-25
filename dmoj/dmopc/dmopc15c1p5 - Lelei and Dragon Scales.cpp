#include <cstdio>
#include <algorithm>
using namespace std;

int psa[252][252];

int main() {
	int W, H, N, ans = 0;
	scanf("%d%d%d", &W, &H, &N);
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &psa[i][j]);
			psa[i][j] = psa[i][j] + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			for (int y = 1; y <= N && i + y - 1 <= H; y++) {
				int x = min(N / y, W - j + 1);
				int sum = psa[i + y - 1][j + x - 1] - psa[i - 1][j + x - 1] - psa[i + y - 1][j - 1] + psa[i - 1][j - 1];
				ans = max(ans, sum);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
