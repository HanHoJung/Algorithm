/*

��ǥ:1�� ���� �� ���� �̿� ��ȹ�� �����ϰ� "���� ���� ���"���� �������� �̿��� ���

�̿��(���, 10<=cash<=3000)
-1�� �̿��
-1�� �̿��(�Ŵ� 1�Ϻ��� ����)
-3�� �̿��(�Ŵ� 1�Ϻ��� ����)
-1�� �̿��(�ų� 1�� 1�Ϻ��� ����)
-3��

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
