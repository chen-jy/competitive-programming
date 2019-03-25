#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int pins[30001], sums[30001];
int dp[501][30001];

int main() {
	int t, n, k, w;
	scan(t);
	while (t--) {
		memset(pins, 0, sizeof(pins));
		memset(sums, 0, sizeof(sums));
		memset(dp, 0, sizeof(dp));
		scan(n); scan(k); scan(w);
		for (int i = 1; i <= n; i++) {
			scan(pins[i]);
			for (int j = i; j > i - w && j > 0; j--)
				sums[i] += pins[j];
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				if (j - w < 1)
					dp[i][j] = sums[j];
				else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - w] + sums[j]);
			}
		}
		cout << dp[k][n] << endl;
	}
	return 0;
}
