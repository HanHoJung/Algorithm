#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main(void) {
	int n;
	dp[0] = 0;
	dp[1] = 0;

	cin >> n;


	for (int i = 2; i <= n; i++) {
		int temp;
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			temp = dp[i / 2] + 1;
			dp[i] = min(dp[i], temp);
		}
		if ((i % 3) == 0) {
			temp = dp[i / 3] + 1;
			dp[i] = min(dp[i], temp);

		}



	}


	cout << dp[n];

}