#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;

bool isInBounds(int X, int Y) {
	return X >= 0 && X <= M && Y >= 0 && Y <= N;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, sum = 0;
	string A2, B2;
	cin >> N >> M >> A2 >> B2;
	string A = " " + A2, B = " " + B2;
	vector<int> dp(M + 1), prevDp;
	for (int i = 0; i < M + 1; i++)
		dp[i] = i;
	for (int y = 1; y < N + 1; y++)
	{
		prevDp = dp;
		fill(dp.begin(), dp.end(), 0);
		dp[0] = y;
		for (int x = 1; x < M + 1; x++)
		{
			if (A[y] == B[x] && isInBounds(x - 1, y - 1))
				dp[x] = prevDp[x - 1];
			else
			{
				a = b = c = INF;
				if (isInBounds(x - 1, y - 1))
					a = prevDp[x - 1];
				if (isInBounds(x - 1, y))
					b = dp[x - 1];
				if (isInBounds(x, y - 1))
					c = prevDp[x];
				dp[x] = min(a, min(b, c)) + 1;
			}
		}
	}
	for (int i = 1; i < M; i++)
		sum += dp[i];
	cout << sum << '\n';
	return 0;
}
