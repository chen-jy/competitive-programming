#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
using namespace std;

int N, M, w1[1000], w2[1000];

int lcs() {
	vector<vector<int>> dp;
	dp.resize(N + 1, vector<int>(M + 1, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (w1[i] == w2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else if (dp[i + 1][j] > dp[i][j + 1])
				dp[i + 1][j + 1] = dp[i + 1][j];
			else dp[i + 1][j + 1] = dp[i][j + 1];
		}
	}
	return dp[N][M];
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	scan(N); scan(M);
	for (int i = 0; i < N; i++)
		scan(w1[i]);
	for (int i = 0; i < M; i++)
		scan(w2[i]);
	cout << lcs() << endl;
	return 0;
}
