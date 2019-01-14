/*

d[n] ���� n�� 1,2,3 ���� �̿��Ͽ� ǥ���� �� �ִ� ����� ��

n-1 1
n-2 2
n-3 3

dp[0]=1

d[4] = dp[3]+dp[2]+dp[1]=4+2+1
d[3]= dp[2] +dp[1]+dp[0]=4
dp[2] = dp[1] dp[0]

dp[0]=1
dp[1]=1
dp[2]=2

1

11
2

*/
#include <iostream>
using namespace std;
long long dp[1000001];
int main(void) {

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
		}
		cout << dp[n] % 1000000009 << "\n";
	}


}