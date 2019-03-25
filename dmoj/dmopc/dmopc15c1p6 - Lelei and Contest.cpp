#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200001;
int M, N, Q;
vector<unsigned long long> bit1(MAXN), bit2(MAXN);

void add(vector<unsigned long long> &bit, int i, int v) {
	for (; i <= MAXN; i += (i & -i))
		bit[i] += v;
}

void add(int lo, int hi, int v) {
	add(bit1, lo, v);
	add(bit1, hi + 1, -v);
	add(bit2, lo, v * (lo - 1));
	add(bit2, hi + 1, -v * hi);
}

unsigned long long sum(vector<unsigned long long> &bit, int i) {
	unsigned long long res = 0;
	for (; i > 0; i -= (i & -i))
		res += bit[i];
	return res;
}

unsigned long long sum(int hi) {
	return sum(bit1, hi) * hi - sum(bit2, hi);
}

unsigned long long sum(int lo, int hi) {
	return sum(hi) - sum(lo - 1);
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int op, l, r, x;
	scan(M); scan(N); scan(Q);
	for (int i = 1; i <= N; i++) {
		scan(x);
		add(i, i, x % M);
	}
	while (Q--) {
		scan(op); scan(l); scan(r);
		if (op == 1) {
			scan(x);
			add(l, r, x % M);
		}
		else cout << sum(l, r) % M << endl;
	}
	return 0;
}
