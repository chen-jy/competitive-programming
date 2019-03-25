#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string words[10] = { "ook", "ookook", "oog", "ooga", "ug",
	"mook", "mookmook", "oogam", "oogum", "ugug" };
unordered_map<string, int> memo;

int DFS(string word)
{
	if (word.size() == 0)
		return 1;
	int t = 0;
	for (int i = 0; i < 10; i++)
	{
		auto index = word.find(words[i]);
		if (index == 0)
		{
			string _word = word.substr(words[i].size());
			auto it = memo.find(_word);
			if (it != memo.end())
				t += (*it).second;
			else
			{
				memo.insert(make_pair(_word, DFS(_word)));
				it = memo.find(_word);
				t += (*it).second;
			}
		}
	}
	return t;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	string word;
	for (int test = 0; test < 10; test++)
	{
		cin >> word;
		cout << DFS(word) << '\n';
	}
	return 0;
}
