#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001];
int main(void) {
	int n;
	vector<int> pi;
	cin >> n;
	pi.push_back(0);
	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		pi.push_back(weight);
	}


	for (int i = 1; i <= n; i++) {
		dp[i] = pi[i];
		for (int j = 1; j <= i-1; j++) {
			dp[i] = min(dp[i], pi[j] + dp[i - j]);
		}

	}
	
			
	cout << dp[n] << "\n";


}
