// RuAr
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000002
typedef long long ll;

int N, T;
ll spinDelta[MAXN], spinFix[MAXN], cur, ans = LLONG_MAX;
bool prime[MAXN];

// bit dictates if we're updating the fixes or the deltas
void update(int bit, int x, ll val){
	if(bit)
		for(; x <= N; x += x&-x) spinFix[x] += val;
	else
		for(; x <= N; x += x&-x) spinDelta[x] += val;
}

ll query(int bit, int x){
	ll sum = 0;
	if(bit)
		for(; x; x -= x&-x) sum += spinFix[x];
	else
		for(; x; x -= x&-x) sum += spinDelta[x];
	return sum;
}

// Updates range on [a,b]
void updateDelta(int a, int b, ll val){
	update(0, a, val);
	update(0, b+1, -val);
}

// Updates on [a, b]
void updateFix(int a, int b, ll val){
	update(1, a, val*(a-1));
	update(1, b+1, -val*b);
}

// Queries on [a,b]
ll queryRange(int a, int b){
	ll delta1 = query(0, a-1), fix1 = query(1, a-1),
	delta2 = query(0, b), fix2 = query(1, b);
	return (delta2*b - fix2) - (delta1*(a-1) - fix1);
}

void sieve(){
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;
	for(int i = 2; i * i <= T; i++){
		if(prime[i]){
			for(int j = i*i; j <= T; j += i)
				prime[j] = 0;
		}
	}
}

int main(){
	scanf("%d%d", &N, &T);
	sieve();
	for(int i = 1; i <= N; i++){
		scanf("%lld", &cur);
		updateDelta(i, i, cur);
		updateFix(i, i, cur);
	}

	for(int i = 1; i <= T; i++){
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		if(prime[i]){
			ll sum = queryRange(a, b);
			sum += k;
			ans = min(ans, 1LL*i*sum);
		}
		else{
			updateDelta(a, b, 1LL*k);
			updateFix(a, b, 1LL*k);
		}
	}

	printf("%lld", ans);
	return 0;
}
