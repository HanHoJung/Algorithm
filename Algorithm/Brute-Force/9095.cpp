#include <iostream>
using namespace std;
int dp[11];

int cnt;
void solve(int n,int sum) {

	if (sum == n) {
		cnt++;
		return;
	}

	if (sum > n) {
		return;
	}


	for (int i = 1; i <= 3; i++) {
		solve(n, sum + i);
	}
}



int main(void) {
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		int n;
		cin >> n;
		solve(n,0);
		cout << cnt << "\n";
	}


	//dp[1] = 1;
	//dp[2] = 2;
	//dp[3] = 4;
	//
	//
	//while (t--) {
	//	int n;
	//	cin >> n;
	//	for(int i=4; i<=n; i++){
	//		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	//	}
	//	cout << dp[n] << "\n";
	//}

	
}