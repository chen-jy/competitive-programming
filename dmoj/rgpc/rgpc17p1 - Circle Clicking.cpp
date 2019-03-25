#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N, D, c = 1, m = 1, x1, y1, x2, y2;
	double d;
	scan(N); scan(D); scan(x1); scan(y1);
	for (int i = 1; i < N; i++)
	{
		scan(x2); scan(y2);
		if (c == 0)
		{
			x1 = x2, y1 = y2, c = 1;
			continue;
		}
		d = sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
		if (d <= D)
		{
			c++;
			if (c > m)
				m = c;
		}
		else c = 0;
		x1 = x2, y1 = y2;
	}
	cout << m << endl;
	return 0;
}
