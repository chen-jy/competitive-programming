#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Point {
	double x, y;
	bool operator<(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

double cross(const Point &O, const Point &A, const Point &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> H(2 * n);
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
			k--;
		H[k++] = P[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
			k--;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	vector<Point> P, H;
	Point t;
	int N, y;
	double ans = 0;
	scan(N);
	for (int x = 1; x <= N; x++) {
		scan(y);
		t.x = x, t.y = y;
		P.push_back(t);
	}
	H = convex_hull(P);
	if (H.size() == 1)
		cout << 0 << endl;
	else {
		double a = H[H.size() - 1].x, b = H[H.size() - 1].y;
		for (int i = H.size() - 2;; i--) {
			ans += sqrt(pow(H[i].y - b, 2) + pow(H[i].x - a, 2));
			a = H[i].x, b = H[i].y;
			if (H[i].x == N)
				break;
		}
		cout << fixed << setprecision(1) << ans << endl;
	}
	return 0;
}
