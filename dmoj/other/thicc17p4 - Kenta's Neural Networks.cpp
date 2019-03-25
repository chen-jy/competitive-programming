#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#define INF 999999999.9
using namespace std;

int edit_distance(const string &str, const string &target) {
	int n = str.size(), m = target.size();
	if (abs(n - m) > 100)
		return INF;
	vector<vector<int>> dp;
	dp.resize(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++)
		dp[i][0] = i;
	for (int j = 0; j <= m; j++)
		dp[0][j] = j;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i] == target[j])
				dp[i + 1][j + 1] = dp[i][j];
			else dp[i + 1][j + 1] = min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1])) + 1;
		}
	}
	return dp[n][m];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string target, str;
	int n, t, total;
	cin >> target >> n;
	double ans = INF, accuracy;
	while (n--) {
		cin >> t;
		total = 0, accuracy = INF;
		for (int i = 0; i < t; i++) {
			cin >> str;
			total += edit_distance(str, target);
		}
		accuracy = (double)total / t;
		if (accuracy < ans)
			ans = accuracy;
	}
	cout << fixed << setprecision(6) << ans << '\n';
	return 0;
}
