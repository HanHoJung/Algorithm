#include <iostream>
#include <vector>
using namespace std;

int dp[100001];
int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}

	for (int i = 0; i < n; i++) {
		if (dp[i-1] + arr[i] > arr[i]) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {
			dp[i] = arr[i];
		}
	}


	int max = dp[0];

	for (int i = 1; i < n; i++) {
		if (max < dp[i])
			max = dp[i];
	}

	cout << max << "\n";




}