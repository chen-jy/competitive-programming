#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll Expand(vll a, vll b)
{
	int len = max(a.size(), b.size()), index;
	len += (len - 1);
	vll result(len);
	if (a.size() > b.size())
	{
		vll temp(a.size());
		for (int i = 0, j = a.size() - b.size(); j < a.size(); i++, j++)
			temp[j] = b[i];
		b = temp;
	}
	else if (b.size() > a.size())
	{
		vll temp(b.size());
		for (int i = 0, j = b.size() - a.size(); j < b.size(); i++, j++)
			temp[j] = a[i];
		a = temp;
	}
	for (int i = 0; i < a.size(); i++)
	{
		index = i;
		for (int j = 0; j < b.size(); j++, index++)
			result[index] += a[i] * b[j];
	}
	index = 0;
	while (result[index] == 0)
		index++;
	if (index == 0)
		return result;
	vll coeff(len - index);
	for (int i = 0; i < coeff.size(); i++, index++)
		coeff[i] = result[index];
	return coeff;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int Q, N, x, l;
	ll y, fx;
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		vector<int> roots(N);
		for (int i = 0; i < N; i++)
			cin >> roots[i];
		cin >> x >> y;
		vll coeff = { 1, -roots[0] };
		fx = x - roots[0];
		for (int i = 1; i < N; i++)
		{
			vll temp = { 1, -roots[i] };
			fx *= (x - roots[i]);
			coeff = Expand(coeff, temp);
		}
		l = y / fx;
		for (int i = 0; i < coeff.size(); i++)
			cout << l * coeff[i] << ' ';
		cout << endl;
	}
	return 0;
}
