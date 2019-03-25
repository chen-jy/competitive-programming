#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

// How do I adjacency matrix
unordered_map<char, set<char>> graph;
vector<pair<char, char>> roads;
bool visited[26];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	set<char> empty;
	char a, b, x;
	bool g = 0;
	int c = 0;
	unordered_map<char, set<char>>::iterator it;
	while (cin >> a >> b, a != '*')
	{
		roads.push_back(make_pair(a, b));
		it = graph.find(a);
		if (it == graph.end())
		{
			empty.insert(b);
			graph.insert(make_pair(a, empty));
			empty.clear();
		}
		else (*it).second.insert(b);
		it = graph.find(b);
		if (it == graph.end())
		{
			empty.insert(a);
			graph.insert(make_pair(b, empty));
			empty.clear();
		}
		else (*it).second.insert(a);
	}
	for (int i = 0; i < roads.size(); i++)
	{
		a = roads[i].first, b = roads[i].second;
		it = graph.find(a);
		(*it).second.erase(b);
		it = graph.find(b);
		(*it).second.erase(a);
		memset(visited, 0, 26);
		queue<char> que;
		que.push('A');
		visited[0] = 1;
		while (!que.empty() && !g)
		{
			x = que.front();
			que.pop();
			it = graph.find(x);
			for (auto itt = (*it).second.begin(); itt != (*it).second.end(); ++itt)
			{
				if (*itt == 'B')
				{
					g = 1;
					break;
				}
				if (!visited[*itt - 'A'])
				{
					que.push(*itt);
					visited[*itt - 'A'] = 1;
				}
			}
		}
		if (!g)
		{
			cout << a << b << '\n';
			c++;
		}
		else g = 0;
		it = graph.find(a);
		if (it == graph.end())
		{
			empty.insert(b);
			graph.insert(make_pair(a, empty));
			empty.clear();
		}
		else (*it).second.insert(b);
		it = graph.find(b);
		if (it == graph.end())
		{
			empty.insert(a);
			graph.insert(make_pair(b, empty));
			empty.clear();
		}
		else (*it).second.insert(a);
	}
	cout << "There are " << c << " disconnecting roads.";
	return 0;
}
