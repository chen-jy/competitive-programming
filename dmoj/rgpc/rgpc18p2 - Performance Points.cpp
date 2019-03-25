#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, a, b, c, d, e, f, combo, t;
	a = b = c = d = e = f = combo = 0;
	double S, score;
	scanf("%d%lf", &N, &S);
	while (N--) {
		scanf("%d", &t);
		if (t < 0) t = -t;
		if (t > 200) {
			e++, combo = 0;
			continue;
		}
		if (t <= 50) a++;
		else if (t <= 100) b++;
		else if (t <= 150) c++;
		else d++;
		f = max(f, ++combo);
	}
	score = 1.5 * a + b + c + 0.5 * d - e + 0.5 * f;
	printf("%.1f\n", max(0.0, score - S));
	return 0;
}
