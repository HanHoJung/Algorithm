
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001];
int main(void) {
	int n;
	cin >> n;
	vector<int> pi;


	pi.push_back(0);
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		pi.push_back(input);
	}


	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <=i; k++) {
			dp[i] = max(dp[i], pi[k]+dp[i-k]);
		}
		
	}
	cout << dp[n];

}
