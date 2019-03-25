#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> rank2;
bool comp(const int &a, const int &b) {
	return rank2[a] < rank2[b];
}

vector<int> suffix_array(const string &s) {
	int n = (int)s.size();
	vector<int> sa(n), rank(n);
	for (int i = 0; i < n; i++) {
		sa[i] = i;
		rank[i] = (int)s[i];
	}
	rank2.resize(n);
	for (int len = 1; len < n; len *= 2) {
		for (int i = 0; i < n; i++)
			rank2[i] = ((long long)rank[i] << 32) + (i + len < n ? rank[i + len] + 1 : 0);
		sort(sa.begin(), sa.end(), comp);
		for (int i = 0; i < n; i++)
			rank[sa[i]] = (i > 0 && rank2[sa[i - 1]] == rank2[sa[i]]) ? rank[sa[i - 1]] : i;
	}
	return sa;
}

vector<int> lcp_array(const string &s, const vector<int> &sa) {
	int n = (int)sa.size();
	vector<int> rank(n), lcp(n - 1);
	for (int i = 0; i < n; i++)
		rank[sa[i]] = i;
	for (int i = 0, h = 0; i < n; i++) {
		if (rank[i] < n - 1) {
			int j = sa[rank[i] + 1];
			while (max(i, j) + h < n && s[i + h] == s[j + h])
				h++;
			lcp[rank[i]] = h;
			if (h > 0)
				h--;
		}
	}
	return lcp;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		vector<int> sa = suffix_array(s), lcp = lcp_array(s, sa);
		int ans = (int)s.size() - sa[0];
		for (int i = 0; i < (int)lcp.size(); i++)
			ans += ((int)s.size() - sa[i + 1]) - lcp[i];
		cout << ans + 1 << '\n';
	}
	return 0;
}
