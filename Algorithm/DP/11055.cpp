#include <iostream>
#include <vector>
using namespace std;
int dp[1001];
int m[1001];
int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		
		for (int j = i; j >= 0; j--) {

			if (arr[i] > arr[j] && dp[i]<dp[j]+arr[i]) {
				dp[i] = dp[j] + arr[i];
				
			}
		}
	}

	int maxVal = 0;
	for (int i = 0; i < n; i++) {
		if (maxVal < dp[i])
			maxVal = dp[i];
	}
		
	cout << maxVal << "\n";
	
}