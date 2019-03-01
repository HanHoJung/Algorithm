#include <iostream>
#include <algorithm>
using namespace std;


int MAP[1001][1001];
int d[1001][1001];
int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> MAP[i][j];
		}
	}

	d[1][1] = MAP[1][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			
			d[i][j + 1] = max(d[i][j + 1], d[i][j] + MAP[i][j + 1]);
			d[i+1][j] = max(d[i + 1][j], d[i][j] + MAP[i+1][j]);
			d[i+1][j + 1] = max(d[i + 1][j + 1], d[i][j] + MAP[i+1][j + 1]);
		}
	}

	cout << d[n][m] << "\n";


}