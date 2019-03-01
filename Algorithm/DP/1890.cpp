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


	for (int i1 = 0; i1 < n; i1++) {
		for (int j1 = 0; j1 < n; j1++) {
			
			for (int j = 0; j < j1; j++) {
				if (arr[i1][j] + j == j1)
					dp[i1][j1] += dp[i1][j];
			}

			for (int i = 0; i <i1; i++) {
				if (arr[i][j1] + i == i1)
					dp[i1][j1] += dp[i][j1];
			}


		}
	}
	
	cout << dp[n - 1][n - 1] << "\n";

}