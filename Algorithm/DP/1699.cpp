#include <iostream>
using namespace std;

int dp[100001];
int main(void) {
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++) {
		dp[i] = n;
		for (int j = 1; j*j <= i; j++) {
			if (dp[i] >dp[i - j * j] + 1) {
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}

	cout << dp[n] << "\n";
}