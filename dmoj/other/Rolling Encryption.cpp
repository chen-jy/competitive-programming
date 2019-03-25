#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int freq[26]{ 0 }, high = 0, shift = 0, start;
	string ref, word;
	cin >> start >> ref;
	word = ref;
	for (int i = start; i < word.size(); i++)
	{
		if (i == start)
		{
			for (int j = i - 1; j >= i - start; j--)
			{
				freq[ref[j] - 97]++;
				if (freq[ref[j] - 97] > high)
				{
					high = freq[ref[j] - 97];
					shift = ref[j] - 96;
				}
				else if (freq[ref[j] - 97] == high && ref[j] - 96 < shift)
					shift = ref[j] - 96;
			}
		}
		else
		{
			freq[ref[i - start - 1] - 97]--;
			freq[ref[i - 1] - 97]++;
			high = shift = 0;
			for (int j = 0; j < 26; j++)
			{
				if (freq[j] > high)
				{
					high = freq[j];
					shift = j + 1;
				}
			}
		}
		if (word[i] + shift > 122)
		{
			high = word[i] + shift;
			high -= 122;
			word[i] = 96 + high;
		}
		else word[i] += shift;
	}
	cout << word;
	return 0;
}
