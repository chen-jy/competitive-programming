#include <cstdio>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	if (N % M == 0)
		printf("yes %d\n", N / M);
	else {
		int m = M;
		while (N % ++m != 0);
		printf("no %d\n", m - M);
	}
	return 0;
}
