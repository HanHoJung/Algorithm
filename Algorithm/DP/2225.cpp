#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;
int main() {
	int n, k;
	cin >> n >> k;
	d[0][0] = 1LL;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int L = 0; L <= j; L++) {
				d[i][j] += d[i - 1][j - L];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[2][1] << '\n';
	
	return 0;
}


