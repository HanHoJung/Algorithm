#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		dp[i] = 1;

		for (int j = i - 1; j >= 0; j--) {

			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int maxVal=1;
	for (int i = 0; i < n; i++) {
		maxVal = max(dp[i], maxVal);
	}
	cout << maxVal << "\n";
}