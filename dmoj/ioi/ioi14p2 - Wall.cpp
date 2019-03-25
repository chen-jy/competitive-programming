#include <algorithm>
#define lchild 2 * n
#define rchild 2 * n + 1
#define mid (tree[n].left + tree[n].right) / 2
using namespace std;

struct node {
	int left, right, min, max, lazy;
};
node tree[8000000];

void build(int n, int l, int r) {
	tree[n].left = l, tree[n].right = r;
	tree[n].min = tree[n].max;
	tree[n].lazy = -1;
	if (l != r) {
		build(lchild, l, mid);
		build(rchild, mid + 1, r);
	}
}

void update(int n, int l, int r, int val, int op) {
	if (tree[n].min == tree[n].max && tree[n].left == l && tree[n].right == r) {
		if (op == 1)
			tree[n].min = tree[n].max = tree[n].lazy = max(tree[n].max, val);
		else tree[n].min = tree[n].max = tree[n].lazy = min(tree[n].min, val);
		return;
	}
	if (tree[n].lazy != -1) {
		tree[lchild].min = tree[rchild].min = tree[n].lazy;
		tree[lchild].max = tree[rchild].max = tree[n].lazy;
		tree[lchild].lazy = tree[rchild].lazy = tree[n].lazy;
		tree[n].lazy = -1;
	}
	if (mid != 0) {
		if (r <= mid)
			update(lchild, l, r, val, op);
		else if (l > mid)
			update(rchild, l, r, val, op);
		else {
			update(lchild, l, mid, val, op);
			update(rchild, mid + 1, r, val, op);
		}
	}
	tree[n].min = min(tree[lchild].min, tree[rchild].min);
	tree[n].max = max(tree[lchild].max, tree[rchild].max);
}

int idx = 0;
void walk(int n, int *& finalHeight) {
	if (tree[n].min == tree[n].max) {
		for (int i = tree[n].left; i <= tree[n].right; i++)
			finalHeight[idx++] = tree[n].min;
		return;
	}
	walk(lchild, finalHeight);
	walk(rchild, finalHeight);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
	build(1, 1, n);
	for (int i = 0; i < k; i++)
		update(1, left[i] + 1, right[i] + 1, height[i], op[i]);
	walk(1, finalHeight);
}
