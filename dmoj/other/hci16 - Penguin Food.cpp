#include <cstdio>
#define MAXN 1000001
#define lchild 2 * idx
#define rchild 2 * idx + 1
using namespace std;

struct Node {
	int l, r, lval, rval, mval, sum;
} tree[4 * MAXN];

void push_up(int idx) {
	tree[idx].mval = 0;
	tree[idx].sum = tree[lchild].sum + tree[rchild].sum;
	tree[idx].lval = tree[lchild].lval;
	tree[idx].rval = tree[rchild].rval;
	if (tree[lchild].sum > tree[idx].lval)
		tree[idx].lval = tree[lchild].sum;
	if (tree[lchild].sum + tree[rchild].lval > tree[idx].lval)
		tree[idx].lval = tree[lchild].sum + tree[rchild].lval;
	if (tree[lchild].sum + tree[rchild].sum > tree[idx].lval)
		tree[idx].lval = tree[lchild].sum + tree[rchild].sum;
	if (tree[rchild].sum > tree[idx].rval)
		tree[idx].rval = tree[rchild].sum;
	if (tree[rchild].sum + tree[lchild].rval > tree[idx].rval)
		tree[idx].rval = tree[rchild].sum + tree[lchild].rval;
	if (tree[rchild].sum + tree[lchild].sum > tree[idx].rval)
		tree[idx].rval = tree[rchild].sum + tree[lchild].sum;
	if (tree[lchild].mval > tree[idx].mval)
		tree[idx].mval = tree[lchild].mval;
	if (tree[rchild].mval > tree[idx].mval)
		tree[idx].mval = tree[rchild].mval;
	if (tree[lchild].rval + tree[rchild].lval > tree[idx].mval)
		tree[idx].mval = tree[lchild].rval + tree[rchild].lval;
	if (tree[lchild].sum > tree[idx].mval)
		tree[idx].mval = tree[lchild].sum;
	if (tree[rchild].sum > tree[idx].mval)
		tree[idx].mval = tree[rchild].sum;
	if (tree[lchild].sum + tree[rchild].sum > tree[idx].mval)
		tree[idx].mval = tree[lchild].sum + tree[rchild].sum;
}

void build(int l, int r, int idx) {
	tree[idx].l = l, tree[idx].r = r;
	if (l == r) {
		scanf("%d", &tree[idx].sum);
		tree[idx].lval = tree[idx].rval = tree[idx].mval = tree[idx].sum;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, lchild);
	build(mid + 1, r, rchild);
	push_up(idx);
}

void update(int x, int val, int idx) {
	if (tree[idx].l > x && tree[idx].r < x)
		return;
	if (tree[idx].l == x && tree[idx].r == x) {
		tree[idx].lval = tree[idx].rval = tree[idx].mval = tree[idx].sum = val;
		return;
	}
	int mid = (tree[idx].l + tree[idx].r) / 2;
	if (x <= mid)
		update(x, val, lchild);
	else update(x, val, rchild);
	push_up(idx);
}

int main() {
	int N, M, x, y;
	scanf("%d", &N);
	build(1, N, 1);
	printf("%d\n", tree[1].mval);
	scanf("%d", &M);
	while (M--) {
		scanf("%d%d", &x, &y);
		x++;
		update(x, y, 1);
		printf("%d\n", tree[1].mval);
	}
	return 0;
}
