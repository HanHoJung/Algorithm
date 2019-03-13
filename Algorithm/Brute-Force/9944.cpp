#include <iostream>
using namespace std;

int n, m;
char map[31][31];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int go(int x, int y, int cnt) {
	int ans = -1;

	if (cnt == 0)
		return 0;

	for (int i = 0; i < 4; i++) {
		int nx = x;
		int ny = y;

		while (true) {
			if (nx + dx[i] < 0 || nx + dx[i] >= n || ny + dy[i] < 0 || ny + dy[i] >= m)
				break;

			if (map[nx + dx[i]][ny + dy[i]] != '.')
				break;

			map[nx + dx[i]][ny + dy[i]] = '#';
			cnt--;
			nx = nx + dx[i];
			ny = ny + dy[i];

		}


		if (!(nx == x && ny == y)) {
			int temp = go(nx, ny, cnt);

			if (temp != -1) {
				if (ans == -1 || ans > temp + 1)
					ans = temp + 1;
			}
		}

		while (!(nx == x && ny == y)) {
			map[nx][ny] = '.';
			nx = nx - dx[i];
			ny = ny - dy[i];
			cnt++;
		}
	}

	return ans;
}

int main(void) {

	int t = 1;
	while (cin >> n >> m) {

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.')
					cnt++;
			}
		}

		int ans = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.') {

					map[i][j] = '#';
					int temp = go(i, j, cnt - 1);
					if (temp != -1) {
						if (ans == -1 || ans > temp)
							ans = temp;
					}
					map[i][j] = '.';

				}

			}
		}

		cout << "Case " << t << ": " << ans << "\n";
		t++;
	}

}