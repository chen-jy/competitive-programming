#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#include <iostream>
#include <vector>
#include <algorithm>
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
	vector<Point> H(n * 2);
	sort(P.begin(), P.end());
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
	H.resize(k - 1);
	return H;
}

double area(vector<Point> P) {
	// Too lazy to optimize
	if (P.size() <= 2)
		return 0;
	double ans = P[0].x * P[1].y;
	for (int i = 1; i < P.size() - 1; i++)
		ans += P[i].x * P[i + 1].y;
	ans += P[P.size() - 1].x * P[0].y;
	ans -= P[0].y * P[1].x;
	for (int i = 1; i < P.size() - 1; i++)
		ans -= P[i].y * P[i + 1].x;
	ans -= P[P.size() - 1].y * P[0].x;
	return ans / 2;
}

int main() {
	//cin.sync_with_stdio(0);
	//cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int n, x, y;
	scan(n);
	vector<Point> P(n), H;
	for (int i = 0; i < n; i++) {
		scan(x); scan(y);
		P[i].x = x, P[i].y = y;
	}
	H = convex_hull(P);
	double ans = area(H) / 50;
	cout << (int)ans << endl;
	return 0;
}
