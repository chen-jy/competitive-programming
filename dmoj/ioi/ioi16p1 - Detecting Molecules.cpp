#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int find_subset(int l, int u, int w[], int n, int result[]) {
	vector<pair<int, int>> W(n);
	for (int i = 0; i < n; i++)
		W[i] = make_pair(w[i], i);
	sort(W.begin(), W.end());
	int start = 0, end = 0;
	long long total = W[0].first;
	while (1) {
		if (l <= total && total <= u) {
			for (int i = start, j = 0; i <= end; i++, j++)
				result[j] = W[i].second;
			return (end - start) + 1;
		}
		if (start == n - 1 && end == n - 1 && (l < total || total > u))
			return 0;
		if (end < n - 1)
			total += W[++end].first;
		if (end == n - 1 && total < l)
			return 0;
		if (total > u)
			total -= W[start++].first;
	}
}
