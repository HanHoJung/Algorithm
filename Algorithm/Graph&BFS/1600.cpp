#include <iostream>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

int MAP[201][201];
int dist[201][201][32];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int hx[] = { -2,-2,-1,1,2,2,-1,1 };
int hy[] = { -1,1,-2,-2,-1,1,2,2 };

int main(void) {
	int k;
	cin >> k;

	int h, w;//h:세로,w:가로

	cin >> w>> h;//가로, 세로 입력됨

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> MAP[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	dist[0][0][0] = 0;

	while (!q.empty()) {

		int x, y, c;
		tie(x, y, c) = q.front();
		q.pop();



		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;

			if (MAP[nx][ny] == 1)
				continue;

			if (dist[nx][ny][c] == -1) {
				dist[nx][ny][c] = dist[x][y][c] + 1;
				q.emplace(nx, ny, c);
			}
		}


		for (int i = 0; i < 8; i++) {
			int nx = x + hx[i];
			int ny = y + hy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w || c + 1>k)
				continue;

			if (MAP[nx][ny] == 1)
				continue;


			if (dist[nx][ny][c + 1] == -1) {
				dist[nx][ny][c + 1] = dist[x][y][c] + 1;
				q.emplace(nx, ny, c + 1);
			}

		}

	}

	int min = -1;
	for (int i = 0; i <= k; i++) {

		if (dist[h - 1][w - 1][i] != -1) {
			if (min == -1 || min > dist[h - 1][w - 1][i])
				min = dist[h - 1][w - 1][i];

		}


	}

	cout << min << "\n";



}