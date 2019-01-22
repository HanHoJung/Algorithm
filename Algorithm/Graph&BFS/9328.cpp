#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
char a[102][102];
bool c[102][102];
bool key[26];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		int cnt = 0;
		int ans = 0;
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		memset(key, false, sizeof(key));
		memset(c, false, sizeof(c));
		vector<string> a(n + 2);
		n = n + 2;
		for (int i = 1; i < n - 1; i++) {

			cin >> a[i];
			a[i] = "." + a[i] + ".";

		}

		m = m + 2;


		for (int i = 0; i < m; i++) {
			a[0] = a[0] + ".";
			a[n - 1] = a[n - 1] + ".";
		}

		string keys;
		cin >> keys;
		if (keys[0] != '0') {

			for (int i = 0; i < keys.length(); i++) {
				key[keys[i] - 'a'] = true;
				
			}
		}
		queue<pair<int, int>> q;
		queue<pair<int, int>> door[26];
		q.push(make_pair(0, 0));
		c[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (c[nx][ny]) {
					continue;
				}
				char w = a[nx][ny];
				if (w == '*') {
					continue;
				}
				c[nx][ny] = true;
				if (w == '.') {
					q.push(make_pair(nx, ny));
				}
				else if (w == '$') {
					ans += 1;
					q.push(make_pair(nx, ny));
				}
				else if (w >= 'A' && w <= 'Z') {
					if (key[w - 'A']) {
						q.push(make_pair(nx, ny));
					}
					else {
						door[w - 'A'].push(make_pair(nx, ny));
					}
				}
				else if (w >= 'a' && w <= 'z') {
					q.push(make_pair(nx, ny));
					if (!key[w - 'a']) {
						key[w - 'a'] = true;
						while (!door[w - 'a'].empty()) {
							q.push(door[w - 'a'].front());
							door[w - 'a'].pop();
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


