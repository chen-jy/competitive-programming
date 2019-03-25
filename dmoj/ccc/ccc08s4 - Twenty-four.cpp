#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cards(4);
int ans = 0;

void Solve(int num, int level)
{
	if (level == 4)
	{
		if (num > ans && num <= 24)
			ans = num;
		return;
	}
	Solve(num + cards[level], level + 1);
	Solve(num - cards[level], level + 1);
	Solve(num * cards[level], level + 1);
	if (num % cards[level] == 0)
		Solve(num / cards[level], level + 1);
	if (level == 1 || level == 2)
	{
		Solve(num + (cards[level] * cards[level + 1]), level + 2);
		Solve(num - (cards[level] * cards[level + 1]), level + 2);
		if (cards[level] % cards[level + 1] == 0)
		{
			Solve(num + (cards[level] / cards[level + 1]), level + 2);
			Solve(num - (cards[level] / cards[level + 1]), level + 2);
		}
		Solve(num * (cards[level] + cards[level + 1]), level + 2);
		Solve(num * (cards[level] - cards[level + 1]), level + 2);
		if (num % cards[level] + cards[level + 1] == 0)
			Solve(num / (cards[level] + cards[level + 1]), level + 2);
		if (num % cards[level] - cards[level + 1] == 0)
			Solve(num / (cards[level] - cards[level + 1]), level + 2);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N;
	cin >> N;
	for (int test = 0; test < N; test++)
	{
		for (int i = 0; i < 4; i++)
			cin >> cards[i];
		sort(cards.begin(), cards.end());
		do
		{
			Solve(cards[0], 1);
		} while (next_permutation(cards.begin(), cards.end()));
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}
