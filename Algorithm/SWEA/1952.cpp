/*

목표:1년 동안 각 달의 이용 계획을 수립하고 "가장 적은 비용"으로 수영장을 이용할 방법

이용권(요금, 10<=cash<=3000)
-1일 이용권
-1달 이용권(매달 1일부터 시작)
-3달 이용권(매달 1일부터 시작)
-1년 이용권(매년 1월 1일부터 시작)
-3초

*/

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[13];

int main(void) {

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		memset(dp, 0, sizeof(dp));
		vector<int> cost(5);
		vector<int> use(13);

		for (int i = 1; i <= 4; i++)
			cin >> cost[i];

		for (int i = 1; i <= 12; i++)
			cin >> use[i];


		for (int i = 1; i <= 12; i++) {
			if (use[i] == 0)
				dp[i] = dp[i - 1];

			int day = dp[i - 1] + (use[i] * cost[1]);
			dp[i] = min(dp[i - 1] + cost[2], day);

			if (i - 3 >= 0)
				dp[i] = min(dp[i - 3] + cost[3], dp[i]);

		}

		int output = min(dp[12], cost[4]);

		printf("#%d %d\n", i, output);

	}

}
