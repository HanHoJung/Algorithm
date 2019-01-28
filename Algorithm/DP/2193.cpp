#include <iostream>
using namespace std;

long long dp[91][2];
int main(void) {

	int n;
	cin >> n;
	for (int j = 0; j <= 1; j++) {
		dp[1][j] = j;
	}

	for (int i = 2; i <= n; i++) {

		for (int j = 0; j <= 1; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + dp[i - 1][1];
			}

			if (j == 1) {
				dp[i][j] = dp[i - 1][0];
			}
		}
	}

	long long sum = 0;
	for (int k = 0; k <= 1; k++) {
		sum = dp[n][k] + sum;
	}

	cout << sum << "\n";


}