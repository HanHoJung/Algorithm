#include<iostream>
using namespace std;
typedef long long ll;
int n, mp[33][33];
ll dp[33][33][4];
ll f(int x, int y, int t) {
	if (mp[x][y] || (t == 1 && mp[x][y - 1]) || (t == 2 && mp[x - 1][y]) || (t == 3 && (mp[x][y - 1] || mp[x - 1][y] || mp[x - 1][y - 1]))) return 0;
	if (dp[x][y][t] != -1) return dp[x][y][t];
	ll re;
	if (t == 1) re = f(x, y - 1, 1) + f(x, y - 1, 3);
	if (t == 2) re = f(x - 1, y, 2) + f(x - 1, y, 3);
	if (t == 3) re = f(x - 1, y - 1, 1) + f(x - 1, y - 1, 2) + f(x - 1, y - 1, 3);
	return dp[x][y][t] = re;
}
int main() {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) scanf("%d", &mp[i][j]);
	for (int i = 0;i <= n;i++) mp[0][i] = mp[i][0] = 1;
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) for (int k = 1;k <= 3;k++) dp[i][j][k] = -1;
	dp[1][2][1] = 1;
	printf("%lld", f(n, n, 1) + f(n, n, 2) + f(n, n, 3));
}

