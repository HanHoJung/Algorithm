#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001];
int main(void) {

	int n;
	cin >> n;

	vector<int> A(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];


	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = i; j >= 0; j--) {

			if (A[i] < A[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}

	}

	int maxVal = 1;
	for (int i = 0; i < n; i++) {
		maxVal = max(dp[i], maxVal);
	}
	cout << maxVal << "\n";
}
