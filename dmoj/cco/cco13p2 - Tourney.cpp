#include <iostream>
#include <cmath>
#define lchild 2 * idx
#define rchild 2 * idx + 1
using namespace std;

struct Node {
	int l, r, max, id;
} tree[4194305];

int indices[1048577];
int N, M, pos = 1, x, y;
char op;

void push_up(int idx) {
	if (tree[lchild].max > tree[rchild].max)
		tree[idx].max = tree[lchild].max, tree[idx].id = tree[lchild].id;
	else tree[idx].max = tree[rchild].max, tree[idx].id = tree[rchild].id;
}

void build(int l, int r, int idx) {
	tree[idx].l = l, tree[idx].r = r;
	if (l == r) {
		cin >> tree[idx].max;
		tree[idx].id = pos++, indices[l] = idx;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, lchild);
	build(mid + 1, r, rchild);
	push_up(idx);
}

void update(int x, int v, int idx) {
	if (tree[idx].l > x && tree[idx].r < x)
		return;
	if (tree[idx].l == tree[idx].r && tree[idx].l == x) {
		tree[idx].max = v;
		return;
	}
	int mid = (tree[idx].l + tree[idx].r) / 2;
	if (x <= mid)
		update(x, v, lchild);
	else update(x, v, rchild);
	push_up(idx);
}

int rounds_won(int idx) {
	idx = indices[idx];
	int won = 0, id = tree[idx].id;
	idx /= 2;
	while (tree[idx].id == id)
		won++, idx /= 2;
	return won;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	N = pow(2, N);
	build(1, N, 1);
	while (M--) {
		cin >> op;
		if (op == 'R') {
			cin >> x >> y;
			update(x, y, 1);
		}
		else if (op == 'W')
			cout << tree[1].id << '\n';
		else {
			cin >> x;
			cout << rounds_won(x) << '\n';
		}
	}
	return 0;
}
