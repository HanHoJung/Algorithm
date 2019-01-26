#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int dist[101][101];
char MAP[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


int main(void) {
	int sx, sy, ex, ey;
	int n, m;
	cin >> m >> n;

	bool check = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			MAP[i][j] = c;

			if (MAP[i][j] == 'C'&& check) {
				sx = i;
				sy = j;
				check = false;
				continue;

			}
			else if (MAP[i][j] == 'C' && !check) {
				ex = i;
				ey = j;
			}

		}
	}


	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	dist[sx][sy] = 0;


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			while (true) {
				

				nx = nx + dx[i];
				ny = ny+ dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					break;

				if (dist[nx][ny] != -1)
					continue;

				if (MAP[nx][ny] == '*')
					break;

				

				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));

			

			}

		}


	}



	cout << dist[ex][ey]-1 << "\n";






}