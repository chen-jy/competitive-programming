#include <iostream>
#include <string>

using namespace std;

bool MonkeyWord(string word);
bool AWord(string word)
{
	if (word == "A")
		return true;
	else if (word.size() >= 3 && word[0] == 'B' && word[word.size() - 1] == 'S' &&
		MonkeyWord(word.substr(1, word.size() - 2)))
		return true;
	else return false;
}

bool MonkeyWord(string word)
{
	if (AWord(word))
		return true;
	else
	{
		for (int i = 1; i < word.size(); i++)
		{
			if (AWord(word.substr(0, i)))
			{
				if (word[i] == 'N')
				{
					if (MonkeyWord(word.substr(i + 1)))
						return true;
				}
			}
		}
		return false;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	string word;
	while (cin >> word)
	{
		if (word == "X")
			break;
		if (MonkeyWord(word))
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
