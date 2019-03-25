#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
	int N, R, C, Rf, Cf;
	scanf("%d", &N);
	vector<int> lines(N + 1);
	vector<vector<int>> dist(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &lines[i]);
		dist[i].resize(lines[i] + 1, INF);
	}
	scanf("%d%d%d%d", &R, &C, &Rf, &Cf);
	queue<pair<int, int>> q;
	dist[R][C] = 0, q.push(make_pair(R, C));
	while (!q.empty()) {
		R = q.front().first, C = q.front().second, q.pop();
		if (R == Rf && C == Cf) {
			printf("%d\n", dist[Rf][Cf]);
			break;
		}
		if (R - 1 >= 1) {
			int c = min(C, lines[R - 1]);
			if (dist[R][C] + 1 < dist[R - 1][c]) {
				dist[R - 1][c] = dist[R][C] + 1;
				q.push(make_pair(R - 1, c));
			}
		}
		if (R + 1 <= N) {
			int c = min(C, lines[R + 1]);
			if (dist[R][C] + 1 < dist[R + 1][c]) {
				dist[R + 1][c] = dist[R][C] + 1;
				q.push(make_pair(R + 1, c));
			}
		}
		if (C - 1 >= 1) {
			if (dist[R][C] + 1 < dist[R][C - 1]) {
				dist[R][C - 1] = dist[R][C] + 1;
				q.push(make_pair(R, C - 1));
			}
		}
		if (C + 1 <= lines[R]) {
			if (dist[R][C] + 1 < dist[R][C + 1]) {
				dist[R][C + 1] = dist[R][C] + 1;
				q.push(make_pair(R, C + 1));
			}
		}
		if (C == 1 && R - 1 >= 1) {
			int c = lines[R - 1];
			if (dist[R][C] + 1 < dist[R - 1][c]) {
				dist[R - 1][c] = dist[R][C] + 1;
				q.push(make_pair(R - 1, c));
			}
		}
		if (C == lines[R] && R + 1 <= N) {
			int c = 1;
			if (dist[R][C] + 1 < dist[R + 1][c]) {
				dist[R + 1][c] = dist[R][C] + 1;
				q.push(make_pair(R + 1, c));
			}
		}
	}
	return 0;
}
