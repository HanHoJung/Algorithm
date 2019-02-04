#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	int t;
	cin >> t;
	
	while (t--) {

		int n;
		cin >> n;
		vector<vector<int>> A(n+1, vector<int>(2,0));
		vector<vector<int>> dp(n+1, vector<int>(3,0));
		for (int i = 1; i <= n; i++) {
			cin >> A[i][0];
		}
		for (int i = 1; i <= n; i++) {
			cin >> A[i][1];
		}
		
		

		for (int i = 1; i <= n; i++) {
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + A[i][0];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + A[i][1];

		}

		cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << "\n";

	}

}

