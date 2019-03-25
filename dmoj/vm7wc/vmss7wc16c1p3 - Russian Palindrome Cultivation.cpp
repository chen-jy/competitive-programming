#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> number;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	string input;
	bool g = 1;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		number.push_back(input[i] - '0');
		if (input[i] != '9')
			g = 0;
	}
	if (g)
	{
		cout << 1;
		for (int i = 0; i < number.size() - 1; i++)
			cout << 0;
		cout << 1;
	}
	else
	{
		int mid = number.size() / 2;
		int left = mid - 1;
		int right = (number.size() % 2 == 0) ? mid : mid + 1;
		g = 0;
		while (left >= 0 && number[left] == number[right])
			left--, right++;
		if (left < 0 || number[left] < number[right])
			g = 1;
		if (g)
		{
			while (left >= 0)
			{
				number[right] = number[left];
				left--, right++;
			}
			int t = 1;
			left = mid - 1;
			if (number.size() % 2 == 0)
				right = mid;
			else
			{
				number[mid]++;
				t = number[mid] / 10;
				number[mid] %= 10;
				right = mid + 1;
			}
			while (left >= 0)
			{
				number[left] += t;
				t = number[left] / 10;
				number[left] %= 10;
				left--;
			}
			for (left = 0; left < mid; left++)
				cout << number[left];
			if (number.size() % 2 == 0)
				left = mid - 1;
			else left = mid;
			for (; left >= 0; left--)
				cout << number[left];
		}
		else
		{
			for (left = 0; left < mid; left++)
				cout << number[left];
			if (number.size() % 2 == 0)
				left = mid - 1;
			else left = mid;
			for (; left >= 0; left--)
				cout << number[left];
		}
	}
	return 0;
}
