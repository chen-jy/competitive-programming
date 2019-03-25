#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int diff[30002][1002];

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int M, N, K, x, y, R, B, a, b;
	scan(M); scan(N); scan(K);
	while (K--) {
		scan(x); scan(y); scan(R); scan(B);
		for (int i = max(1, y - R); i <= min(M, y + R); i++) {
			a = max(1, (int)ceil(x - sqrt(pow(R, 2) - pow(y - i, 2))));
			b = min(N, (int)floor(x + sqrt(pow(R, 2) - pow(y - i, 2))));
			diff[i][a] += B, diff[i][b + 1] -= B;
		}
	}
	a = b = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (j > 1)
				diff[i][j] += diff[i][j - 1];
			if (diff[i][j] == a)
				b++;
			else if (diff[i][j] > a)
				a = diff[i][j], b = 1;
		}
	}
	cout << a << endl << b << endl;
	return 0;
}
