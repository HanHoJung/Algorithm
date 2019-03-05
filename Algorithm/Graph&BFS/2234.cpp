#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int n, m;
int MAP[51][51];//성벽 정보
int area[51][51];//영역 분할
int rooms[51 * 51];//각 룸의 갯수

int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

int go(int i, int j, int paint) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	area[i][j] = paint;
	
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			if (area[nx][ny] != 0) continue;
			if (MAP[x][y] & (1 << i)) continue;

			q.push(make_pair(nx, ny));
			area[nx][ny] = paint;	
		}
	}

	return cnt;
}



int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}
	int paint=0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] == 0) {
				paint++;
				rooms[paint] = go(i, j, paint);
				

			}
		}
	}


	int rMax = -1;
	for (int i = 1; i <= paint; i++) {

		if (rooms[i] > rMax)
			rMax = rooms[i];

	}


	int wide = -1;
	for (int x = 0; x < 50; x++) {
		for (int y = 0;	y < 50; y++) {

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					continue;

				if (area[nx][ny]==area[x][y]) continue;
				if (MAP[x][y] & (1 << k)==0) continue;
				
				if (wide < rooms[area[x][y]] + rooms[area[nx][ny]])
					wide = rooms[area[x][y]] + rooms[area[nx][ny]];
				

			}


		}
	}



	cout << paint << "\n";
	cout << rMax << "\n";
	cout << wide << "\n";

	
}