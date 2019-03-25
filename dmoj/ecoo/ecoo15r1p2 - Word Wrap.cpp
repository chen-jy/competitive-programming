#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	for (int test = 0; test < 10; test++)
	{
		int length, index = 0;
		string text, t;
		cin >> length;
		cin.ignore();
		getline(cin, text);
		if (length == 1)
		{
			for (int i = 0; i < text.size(); i++)
			{
				if (text[i] == ' ')
					continue;
				cout << text[i] << '\n';
			}
			cout << "=====\n";
		}
		else
		{
			stringstream ss(text);
			deque<string> words;
			while (ss >> t)
				words.push_back(t);
			while (words.size() > 0)
			{
				if (words[0].size() + index <= length)
				{
					cout << words[0] << ' ';
					index += words[0].size() + 1;
					words.pop_front();
				}
				else if (index != 0)
				{
					cout << '\n';
					index = 0;
				}
				else
				{
					bool g = 1;
					while (words[0].size() > 0)
					{
						for (int i = 0; i < length; i++)
						{
							if (words[0].size() < length && i == words[0].size())
							{
								index = i + 1;
								g = 0;
								break;
							}
							else cout << words[0][i];
						}
						if (!g)
						{
							words.pop_front();
							cout << ' ';
							break;
						}
						words[0] = words[0].substr(length);
						cout << '\n';
						if (words[0].size() == 0)
						{
							words.pop_front();
							break;
						}
					}
				}
			}
			if (index != 0)
				cout << '\n';
			cout << "=====\n";
		}
	}
	return 0;
}
