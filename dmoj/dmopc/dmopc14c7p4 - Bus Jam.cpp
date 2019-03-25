#include <iostream>

using namespace std;

int times[1001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N, M, H, brs = 0;
	cin >> N >> M >> H;
	for (int i = 0; i < N; i++)
		cin >> times[i];
	for (int i = N - 1; i > 0; i--)
	{
		while (times[i] - times[i - 1] > H)
		{
			times[i - 1] += M;
			brs++;
		}
	}
	cout << brs;
	return 0;
}
