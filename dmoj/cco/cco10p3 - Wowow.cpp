#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> map_t;
int dict[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	map_t s;
	int N, X, Y, n = 0;
	char c;
	cin >> N;
	while (N--) {
		cin >> c;
		if (c == 'N') {
			cin >> X >> Y;
			s.insert(make_pair(Y, X));
			dict[X] = Y;
			n++;
		}
		else if (c == 'M') {
			cin >> X >> Y;
			auto it = s.find(dict[X]);
			swap(s[Y], it->second);
			s.erase(it);
			dict[X] = Y;
		}
		else {
			cin >> X;
			cout << s.find_by_order(n - X)->second << '\n';
		}
	}
	return 0;
}
