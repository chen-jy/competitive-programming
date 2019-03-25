#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int n, m, k;
	cin >> n;
	while (n--)
	{
		map<string, int> words;
		multimap<int, string, greater<int>> sorted;
		map<string, int>::iterator it;
		string word;
		cin >> m >> k;
		cout << k;
		if (k % 100 >= 11 && k % 100 <= 13)
			cout << "th";
		else
		{
			if (k % 10 == 1)
				cout << "st";
			else if (k % 10 == 2)
				cout << "nd";
			else if (k % 10 == 3)
				cout << "rd";
			else cout << "th";
		}
		cout << " most common word(s):\n";
		while (m--)
		{
			cin >> word;
			it = words.find(word);
			if (it == words.end())
				words.insert(make_pair(word, 1));
			else it->second++;
		}
		for (auto it = words.begin(); it != words.end(); ++it)
			sorted.insert(make_pair(it->second, it->first));
		int common = 0, value = 0;
		for (auto it = sorted.begin(); it != sorted.end(); ++it)
		{
			if (it->first != value)
			{
				common++;
				if (common == k)
					cout << it->second << '\n';
				value = it->first;
			}
			else if (common == k)
				cout << it->second << '\n';
			else common++;
		}
		cout << '\n';
	}
	return 0;
}
