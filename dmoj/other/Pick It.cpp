#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int nums[200], dp[200][200];

int dfs(int lo, int hi) {
	if (lo == hi)
		return 0;
	if (dp[lo][hi] != -1)
		return dp[lo][hi];
	for (int i = lo + 1; i < hi; i++)
		dp[lo][hi] = max(dp[lo][hi], nums[lo] + nums[i] + nums[hi] + dfs(lo, i) + dfs(i, hi));
	if (dp[lo][hi] == -1)
		return 0;
	else return dp[lo][hi];
}

int main() {
	while (1) {
		int N;
		scan(N);
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			scan(nums[i]);
		memset(dp, -1, sizeof(dp));
		cout << dfs(0, N - 1) << endl;
	}
	return 0;
}
