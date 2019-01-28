

#include <iostream>
using namespace std;
int dp[1000][10];
int main(void) {

	int n;
	cin >> n;

	for (int j = 0; j <= 9; j++) {
		dp[1][j] = 1;
	}

	for (int i = 2; i <= n; i++) {
		
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j])%10007;
			}

		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[n][i])%10007;
	}

	cout << sum << "\n";

}