#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int>> slaves;
vector<int> chars, memo;

int DFS(int x)
{
	if (memo[x - 1] != -1)
		return memo[x - 1];
	auto it = slaves.find(x);
	int t = chars[x - 1];
	for (int i = 0; i < (*it).second.size(); i++)
	{
		auto itt = slaves.find((*it).second[i]);
		if (itt == slaves.end())
			t += chars[(*it).second[i] - 1];
		else t += DFS((*it).second[i]);
	}
	memo[x - 1] = t;
	return t;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	vector<int> empty;
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> x >> y;
		auto it = slaves.find(x);
		if (it == slaves.end())
		{
			empty.push_back(y);
			slaves.insert(make_pair(x, empty));
			empty.clear();
		}
		else (*it).second.push_back(y);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		chars.push_back(x);
		memo.push_back(-1);
	}
	y = -2147483647;
	for (auto it = slaves.begin(); it != slaves.end(); ++it)
	{
		int t = DFS((*it).first);
		if (t > y)
			y = t;
	}
	for (int i = 0; i < N; i++)
	{
		if (chars[i] > y)
			y = chars[i];
	}
	cout << y;
	return 0;
}
