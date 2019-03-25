#include <iostream>
#include <set>
#include <utility>

using namespace std;

int numbers[100000];
multiset<pair<int, int>> available;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, K;
	pair<int, int> a;
	multiset<pair<int, int>>::iterator it;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
		available.insert({ numbers[i], i });
	}
	for (int i = 0; i < N; i++)
	{
		if (!available.empty() && K > 0)
		{
			available.erase({ numbers[i], i });
			if (!available.empty())
			{
				it = --available.end();
				if ((*it).first > numbers[i])
				{
					/*auto itt = it;
					int index = (*it).second;
					while ((*itt).first == (*it).first)
					{
						if ((*itt).second > index)
							index = (*itt).second;
						--itt;
					}
					if (index > (*it).second)
						it = itt;*/
					a.first = numbers[i], a.second = (*it).second;
					numbers[i] = (*it).first;
					numbers[(*it).second] = a.first;
					available.erase(it);
					available.insert(a);
					K--;
				}
			}
		}
		cout << numbers[i] << ' ';
	}
	return 0;
}
