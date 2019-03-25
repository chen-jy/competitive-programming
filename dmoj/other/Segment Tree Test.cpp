#include <cstdio>
using namespace std;

const int MAXN = 100001, INF = 1 << 30;
int N, M, a[MAXN], m[3 * MAXN], g[3 * MAXN], q[3 * MAXN], x, y;
inline int min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void build(int n, int l, int r) {
	if (l == r) {
		m[n] = g[n] = a[l], q[n] = 1;
		return;
	}
	int lchild = 2 * n, rchild = 2 * n + 1, mid = (l + r) / 2;
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	m[n] = min(m[lchild], m[rchild]);
	g[n] = gcd(g[lchild], g[rchild]);
	if (g[n] == g[lchild])
		q[n] += q[lchild];
	else {
		for (int i = l; i <= mid; i++) {
			if (a[i] == g[n])
				q[n]++;
		}
	}
	if (g[n] == g[rchild])
		q[n] += q[rchild];
	else {
		for (int i = mid + 1; i <= r; i++) {
			if (a[i] == g[n])
				q[n]++;
		}
	}
}

int query_M(int n, int l, int r) {
	if (r < x || l > y)
		return INF;
	if (l >= x && r <= y)
		return m[n];
	int lchild = 2 * n, rchild = 2 * n + 1, mid = (l + r) / 2;
	int a = query_M(lchild, l, mid), b = query_M(rchild, mid + 1, r);
	if (a == INF)
		return b;
	if (b == INF)
		return a;
	return min(a, b);
}

int query_G(int n, int l, int r) {
	if (r < x || l > y)
		return INF;
	if (l >= x && r <= y)
		return g[n];
	int lchild = 2 * n, rchild = 2 * n + 1, mid = (l + r) / 2;
	int a = query_G(lchild, l, mid), b = query_G(rchild, mid + 1, r);
	if (a == INF)
		return b;
	if (b == INF)
		return a;
	return gcd(a, b);
}

int query_Q(int n, int l, int r, int v) {
	if (r < x || l > y)
		return INF;
	if (l >= x && r <= y) {
		if (l == r && a[l] == v)
			return 1;
		if (g[n] == v)
			return q[n];
		return 0;
	}
	int lchild = 2 * n, rchild = 2 * n + 1, mid = (l + r) / 2;
	int a = query_Q(lchild, l, mid, v), b = query_Q(rchild, mid + 1, r, v);
	if (a == INF)
		return b;
	if (b == INF)
		return a;
	return a + b;
}

void update(int n, int l, int r) {
	if (r < x || l > x)
		return;
	if (l == r) {
		m[n] = g[n] = a[l], q[n] = 1;
		return;
	}
	int lchild = 2 * n, rchild = 2 * n + 1, mid = (l + r) / 2;
	update(lchild, l, mid);
	update(rchild, mid + 1, r);
	m[n] = min(m[lchild], m[rchild]);
	g[n] = gcd(g[lchild], g[rchild]);
	q[n] = 0;
	if (g[n] == g[lchild])
		q[n] += q[lchild];
	else {
		for (int i = l; i <= mid; i++) {
			if (a[i] == g[n])
				q[n]++;
		}
	}
	if (g[n] == g[rchild])
		q[n] += q[rchild];
	else {
		for (int i = mid + 1; i <= r; i++) {
			if (a[i] == g[n])
				q[n]++;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	build(1, 0, N - 1);
	char op;
	while (M--) {
		scanf(" %c%d%d", &op, &x, &y);
		x--, y--;
		if (op == 'C') {
			y++, a[x] = y;
			update(1, 0, N - 1);
		}
		else if (op == 'M')
			printf("%d\n", query_M(1, 0, N - 1));
		else if (op == 'G')
			printf("%d\n", query_G(1, 0, N - 1));
		else printf("%d\n", query_Q(1, 0, N - 1, query_G(1, 0, N - 1)));
	}
	return 0;
}
