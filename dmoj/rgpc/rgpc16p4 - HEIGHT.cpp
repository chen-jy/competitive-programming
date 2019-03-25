#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n], sums[n];
	for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sums[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && sums[i] < sums[j] + arr[i])
                sums[i] = sums[j] + arr[i];
        }
    }
    sort(sums, sums + n);
    cout << sums[n - 1];
	return 0;
}
