#include <iostream>
using namespace std;


long long dp[101][101];
int arr[101][101];
int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				continue;

			if (arr[i][j] + j < n)
				dp[i][j + arr[i][j]] += dp[i][j];

			if (arr[i][j] + i < n)
				dp[i + arr[i][j]][j] += dp[i][j];


		}
	}

	cout << dp[n - 1][n - 1] << "\n";

}