/*

이친수
- 0으로 시작하지 않는다.
- 1이 두 번 연속 나타나지 않는다.

dp[i][j]
수의 길이가 i이고 마지막에 오는 수가 j인 이친수의 개수를 의미한다.

dp[i][j] = 
           j가 1이면
           dp[i-1][0]//0

		   j가 0이면 
		   dp[i-1][0]//0
		   dp[i-1][1]//1
		   


dp[1][0] = 0
dp[1][1] = 1//1

dp[2][0] = dp[1][0] + dp[1][1] = 1//10
dp[2][1] = dp[1][0] = 0

dp[3][0] = dp[2][0] + dp[2][1] = 1
dp[3][1] = dp[2][0] = 1

1000
1010
1001


*/

#include <iostream>
using namespace std;

long long dp[91][2];
int main(void) {

	int n;
	cin >> n;
	for (int j = 0; j <= 1; j++) {
		dp[1][j] = j;
	}

	for (int i = 2; i <= n; i++) {

		for (int j = 0; j <= 1; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + dp[i - 1][1];
			}

			if (j == 1) {
				dp[i][j] = dp[i - 1][0];
			}
		}
	}

	long long sum = 0;
	for (int k = 0; k <= 1; k++) {
		sum = dp[n][k] + sum;
	}

	cout << sum << "\n";


}