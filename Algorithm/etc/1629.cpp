#include <iostream>
using namespace std;
long long mul(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a % c;
	}
	else if (b % 2 == 0) {
		return (mul(a, b / 2, c) * mul(a, b / 2, c)) % c;
	}
	else {
		return (a * mul(a, b - 1, c)) % c;
	}
}
int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << mul(a, b, c) << '\n';
	return 0;
}