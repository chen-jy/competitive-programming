#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cubes;
unordered_map<int, int>::iterator it1, it2;

int main()
{
	int N, M, Q, p = 0, a, b;
	scan(N); scan(M); scan(Q);
	while (N--)
	{
		scan(a);
		p += a;
		cubes.insert({ a, p });
	}
	while (Q--)
	{
		scan(a); scan(b);
		it1 = cubes.find(a), it2 = cubes.find(b);
		a = (it2->second - it1->second + it1->first) / 2;
		if (a >= M)
			cout << "Enough" << endl;
		else cout << "Not enough" << endl;
	}
	return 0;
}
