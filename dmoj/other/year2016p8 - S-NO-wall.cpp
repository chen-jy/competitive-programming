#include <cstdio>
#define MAXN 1000001
#define lchild 2 * idx
#define rchild 2 * idx + 1
using namespace std;

struct Node {
	int l, r, len, idx, llen, rlen, lazy;
} tree[4 * MAXN];

void push_up(int idx) {
	tree[idx].len = tree[rchild].len;
	tree[idx].idx = tree[rchild].idx;
	if (tree[lchild].rlen + tree[rchild].llen > tree[idx].len || (tree[lchild].rlen + tree[rchild].llen ==
		tree[idx].len && tree[lchild].r - tree[lchild].rlen + 1 < tree[idx].idx)) {
		tree[idx].len = tree[lchild].rlen + tree[rchild].llen;
		tree[idx].idx = tree[lchild].r - tree[lchild].rlen + 1;
	}
	if (tree[lchild].len > tree[idx].len || (tree[lchild].len == tree[idx].len && tree[lchild].idx < tree[idx].idx)) {
		tree[idx].len = tree[lchild].len;
		tree[idx].idx = tree[lchild].idx;
	}
	bool rFull = tree[rchild].len == tree[rchild].r - tree[rchild].l + 1;
	bool lFull = tree[lchild].len == tree[lchild].r - tree[lchild].l + 1;
	if (rFull)
		tree[idx].rlen = tree[rchild].len + tree[lchild].rlen;
	else tree[idx].rlen = tree[rchild].rlen;
	if (lFull)
		tree[idx].llen = tree[lchild].len + tree[rchild].llen;
	else tree[idx].llen = tree[lchild].llen;
	if (rFull && lFull) {
		tree[idx].len = tree[idx].llen = tree[idx].rlen = tree[rchild].rlen + tree[lchild].llen;
		tree[idx].idx = tree[lchild].l;
	}
}

void push_down(int idx) {
	if (tree[idx].lazy == 0)
		return;
	if (tree[idx].lazy == 1) {
		tree[lchild].len = tree[lchild].llen = tree[lchild].rlen = tree[lchild].r - tree[lchild].l + 1;
		tree[rchild].len = tree[rchild].llen = tree[rchild].rlen = tree[rchild].r - tree[rchild].l + 1;
		tree[lchild].idx = tree[lchild].l, tree[rchild].idx = tree[rchild].l;
	}
	else if (tree[idx].lazy == -1) {
		tree[lchild].len = tree[lchild].llen = tree[lchild].rlen = 0;
		tree[rchild].len = tree[rchild].llen = tree[rchild].rlen = 0;
	}
	if (tree[idx].l != tree[idx].r)
		tree[lchild].lazy = tree[rchild].lazy = tree[idx].lazy;
	tree[idx].lazy = 0;
}

void build(int l, int r, int idx) {
	tree[idx].l = l, tree[idx].r = r;
	tree[idx].idx = l, tree[idx].lazy = 0;
	if (l == r) {
		tree[idx].len = tree[idx].llen = tree[idx].rlen = 0;
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
		if (val == 1)
			tree[idx].len = tree[idx].llen = tree[idx].rlen = tree[idx].r - tree[idx].l + 1;
		else tree[idx].len = tree[idx].llen = tree[idx].rlen = 0;
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

int main() {
	int N, Q, T, l, r;
	scanf("%d%d", &N, &Q);
	build(1, N, 1);
	while (Q--) {
		scanf("%d", &T);
		if (T != 2) {
			scanf("%d%d", &l, &r);
			update(l, r, T == 0 ? -1 : 1, 1);
			printf("%d\n", tree[1].len);
		}
		else update(tree[1].idx, tree[1].idx + tree[1].len - 1, -1, 1);
	}
	return 0;
}
