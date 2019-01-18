#include <iostream>
using namespace std;


long long dp[100001][4];
int main(void) {


	for (int i = 0; i <= 100000; i++) {

		for (int j = 1; j <= 3; j++) {

			if (i < 0) {
				dp[i][1] = 0;
			}
			else if (i == 1) {
				dp[i][1] = 1;
			}
			else {
				dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
			}

			if (i < 2) {
				dp[i][2] = 0;
			}
			else if (i == 2) {
				dp[i][2] = 1;
			}
			else {
				dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
			}


			if (i < 3) {
				dp[i][3] = 0;
			}
			else if (i == 3) {
				dp[i][3] = 1;
			}
			else {
				dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
			}

		}
	}



	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		

		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << "\n";
	}

}