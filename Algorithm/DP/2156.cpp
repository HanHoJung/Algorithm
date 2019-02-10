#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10000][3];

int main(void) {
	int n;
	cin >> n;
	vector<int> A(n+1,0);

	for (int i = 1; i <= n; i++)
		cin >> A[i];

	
	dp[1][0] = 0;
	dp[1][1] = A[1];
	dp[1][2] = 0;

	for (int i = 2;i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				dp[i][j] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			}
			else if (j == 1) {
				dp[i][j] = dp[i - 1][0] + A[i];
			}
			else if (j == 2) {
				dp[i][j] = dp[i - 1][1] + A[i];
			}

		}
	}
	int sum = -1;
	for (int i = 0; i < 3; i++) {
		
		sum = max(sum, dp[n][i]);
	}
	cout << sum << "\n";
}