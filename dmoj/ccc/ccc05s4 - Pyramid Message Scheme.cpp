#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

map<string, vector<string>> graph;
set<string> visited;
int counter = 0, maxDepth = 0;

void DFS(string x, int depth)
{
	if (depth > maxDepth)
		maxDepth = depth;
	auto it = graph.find(x);
	if (it == graph.end())
		return;
	for (int i = 0; i < (*it).second.size(); i++)
	{
		if (visited.find((*it).second[i]) == visited.end())
		{
			visited.insert((*it).second[i]);
			counter++;
			DFS((*it).second[i], depth + 1);
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	vector<string> t;
	int L, n;
	string a, b;
	map<string, vector<string>>::iterator it;
	cin >> L;
	for (int test = 0; test < L; test++)
	{
		cin >> n;
		for (int i = 0; i < n; i += 2)
		{
			cin >> a >> b;
			it = graph.find(a);
			if (it == graph.end())
			{
				t.push_back(b);
				graph.insert(make_pair(a, t));
				t.clear();
			}
			else (*it).second.push_back(b);
			it = graph.find(b);
			if (it == graph.end())
			{
				t.push_back(a);
				graph.insert(make_pair(b, t));
				t.clear();
			}
			else (*it).second.push_back(a);
		}
		visited.insert(b);
		DFS(b, 0);
		maxDepth *= 20, counter *= 20;
		if (counter - maxDepth > 0)
			cout << counter - maxDepth;
		else cout << 0;
		cout << '\n';
		graph.clear();
		visited.clear();
		counter = maxDepth = 0;
	}
    return 0;
}
