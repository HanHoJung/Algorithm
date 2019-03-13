#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int go(int n, int k) {
	if (k < 0 || n < 0)
		return 0;

	if (n == 0 && k == 0)
		return 1;

	if (dp[n][k] >= 0)
		return dp[n][k];

	dp[n][k] = (go(n - 1, k - 1) % 10007 + go(n - 1, k) % 10007) % 10007;

	return dp[n][k];


}

int main(void) {
	int n, k;
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));
	cout << go(n, k) << "\n";

}