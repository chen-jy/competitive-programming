#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<int, int>> jewls;
multiset<int> bags;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, K, a, b;
	long long sum = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		jewls.push_back(make_pair(b, a));
	}
	for (int i = 0; i < K; i++)
	{
		cin >> a;
		bags.insert(a);
	}
	sort(jewls.begin(), jewls.end(), [](const auto &A, const auto &B)
	{
		if (A.first == B.first)
		{
			if (A.second < B.second) return true;
			else return false;
		}
		if (A.first > B.first) return true;
		else return false;
	});
	for (int i = 0; i < N; i++)
	{
		if (bags.size() == 0) break;
		multiset<int>::iterator it = bags.lower_bound(jewls[i].second);
		if (it == bags.end()) continue;
		sum += jewls[i].first;
		bags.erase(it);
	}
	cout << sum;
	return 0;
}
