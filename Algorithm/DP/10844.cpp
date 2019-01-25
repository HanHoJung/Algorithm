#include <iostream>
using namespace std;
long long dp[100][10];

int main(void) {

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {

		for (int j = 0; j <= 9; j++) {

			if (j  >= 1)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i][j]) % 1000000000;

			if (j == 1) {
				cout << i << "\n";
				printf("dp[%d][%d]=%d\n", i-1, j-1,dp[i-1][j-1]);
			}

			if (j < 9)
				dp[i][j] = (dp[i - 1][j + 1] + dp[i][j]) % 1000000000;

		}
	}
	
	
    
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[n][i])%1000000000;

	}

	cout << sum << "\n";
}

