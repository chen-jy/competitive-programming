#include <cstdio>
#include <algorithm>
#define MAXN 30001
#define lchild 2 * idx
#define rchild 2 * idx + 1
#define INF 0x3f3f3f3f
using namespace std;

struct Node {
	int l, r, min, lazy;
} tree[4 * MAXN];

int N, Q, a, b, c;

void push_up(int idx) {
	tree[idx].min = min(tree[lchild].min, tree[rchild].min);
}

void push_down(int idx) {
	if (tree[idx].lazy != 0) {
		tree[idx].min = max(tree[idx].min - tree[idx].lazy, 0);
		if (tree[idx].l != tree[idx].r) {
			tree[lchild].lazy += tree[idx].lazy;
			tree[rchild].lazy += tree[idx].lazy;
		}
		tree[idx].lazy = 0;
	}
}

void build(int l, int r, int idx) {
	tree[idx].l = l, tree[idx].r = r;
	if (l == r) {
		scanf("%d", &tree[idx].min);
		tree[idx].lazy = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, lchild);
	build(mid + 1, r, rchild);
	push_up(idx);
}

void update(int updL, int updR, int val, int idx) {
	push_down(idx);
	if (tree[idx].l >= updL && tree[idx].r <= updR) {
		tree[idx].lazy = val;
		push_down(idx);
		return;
	}
	if (tree[idx].l > updR || tree[idx].r < updL)
		return;
	update(updL, updR, val, lchild);
	update(updL, updR, val, rchild);
	push_up(idx);
}

int query(int l, int r, int idx) {
	push_down(idx);
	if (tree[idx].r < l || tree[idx].l > r)
		return INF;
	if (tree[idx].r <= r && tree[idx].l >= l)
		return tree[idx].min;
	return min(query(l, r, lchild), query(l, r, rchild));
}

int main() {
	scanf("%d%d", &N, &Q);
	build(1, N, 1);
	while (Q--) {
		scanf("%d%d%d", &a, &b, &c);
		update(a, b, c, 1);
		printf("%d %d\n", query(a, b, 1), query(1, N, 1));
	}
	return 0;
}
