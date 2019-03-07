#include <iostream>
using namespace std;

long long dp[101];
int main(void) {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= i - 3; j++) {
		
			if (dp[i - (j + 2)] * (j + 1) > dp[i])
				dp[i] = dp[i - (j + 2)] * (j + 1);
		}
	}
	cout << dp[n] << "\n";
}