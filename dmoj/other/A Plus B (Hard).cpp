#include <iostream>
#include <string>
using namespace std;

struct bigint {
	static const int MAXN = 100000;
	char digits[MAXN] = {}, sign;
	int end;

	bigint(long long x = 0) {
		if (x >= 0)
			sign = 1;
		else sign = -1;
		if (x != 0) {
			if (x < 0)
				x = -x;
			for (end = -1; x > 0; x /= 10)
				digits[++end] = x % 10;
		}
		else end = 0;
	}

	bigint(const string &s) {
		if (s[0] != '-')
			sign = 1;
		else sign = -1;
		end = -1;
		for (int i = s.size() - 1; i >= 0; i--)
			digits[++end] = s[i] - '0';
		if (digits[end] + '0' == '-')
			digits[end--] = 0;
	}
};

void trim(bigint* x) {
	while (x->end > 0 && !x->digits[x->end])
		x->end--;
	if (x->end == 0 && x->digits[0] == 0)
		x->sign = 1;
}

int compare(bigint* a, bigint* b) {
	if (a->sign != b->sign)
		return b->sign;
	if (b->end > a->end)
		return a->sign;
	if (a->end > b->end)
		return -a->sign;
	for (int i = a->end; i >= 0; i--) {
		if (a->digits[i] > b->digits[i])
			return -a->sign;
		if (b->digits[i] > a->digits[i])
			return a->sign;
	}
	return 0;
}

void add(bigint* a, bigint* b, bigint* c);
void subtract(bigint* a, bigint* b, bigint* c);

void add(bigint* a, bigint* b, bigint* c) {
	if (a->sign != b->sign) {
		if (a->sign == -1)
			a->sign = 1, subtract(b, a, c), a->sign = -1;
		else b->sign = 1, subtract(a, b, c), b->sign = -1;
		return;
	}
	c->sign = a->sign;
	c->end = (a->end > b->end ? a->end : b->end) + 1;
	for (int i = 0, carry = 0; i <= c->end; i++) {
		c->digits[i] = (carry + a->digits[i] + b->digits[i]) % 10;
		carry = (carry + a->digits[i] + b->digits[i]) / 10;
	}
	trim(c);
}

void subtract(bigint* a, bigint* b, bigint* c) {
	if (a->sign == -1 || b->sign == -1) {
		b->sign *= -1, add(a, b, c), b->sign *= -1;
		return;
	}
	if (compare(a, b) == 1) {
		subtract(b, a, c), c->sign = -1;
		return;
	}
	c->end = a->end > b->end ? a->end : b->end;
	for (int i = 0, borrow = 0, v; i <= c->end; i++) {
		v = a->digits[i] - borrow;
		if (i <= b->end)
			v -= b->digits[i];
		if (a->digits[i] > 0)
			borrow = 0;
		if (v < 0)
			v += 10, borrow = 1;
		c->digits[i] = v % 10;
	}
	trim(c);
}

string to_string(bigint* x) {
	string s(x->sign == -1 ? "-" : "");
	for (int i = x->end; i >= 0; i--)
		s += (char)('0' + x->digits[i]);
	return s;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("DATA.txt", "r", stdin);
	int N;
	string a, b, c;
	cin >> N;
	while (N--) {
		cin >> a >> b;
		bigint A(a), B(b), C;
		add(&A, &B, &C);
		cout << to_string(&C) << '\n';
	}
	return 0;
}
