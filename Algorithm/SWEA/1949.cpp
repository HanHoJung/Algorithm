
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
int n, k;
bool visit[9][9];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool broken = false;
vector<vector<int>> MAP(10, vector<int>(10, -1));
int go(int x, int y, int cnt) {

	int size = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			continue;
		}

		if (visit[nx][ny] == true) {
			continue;
		}

		if (broken) {//broken true

			if (MAP[x][y] > MAP[nx][ny]) {
				visit[nx][ny] = true;
				int depth = go(nx, ny, cnt + 1);
				visit[nx][ny] = false;
				if (depth > size)
					size = depth;
			}
		}
		else {//broken false

			if (MAP[x][y] > MAP[nx][ny]) {
				visit[nx][ny] = true;
				int depth = go(nx, ny, cnt + 1);
				visit[nx][ny] = false;
				if (depth > size)
					size = depth;
			}
			else {

				for (int diff = 1; diff <= k; diff++) {

					if (MAP[x][y] > (MAP[nx][ny] - diff)) {
						visit[nx][ny] = true;
						broken = true;
						MAP[nx][ny] = MAP[nx][ny] - diff;
						int depth = go(nx, ny, cnt + 1);
						MAP[nx][ny] = MAP[nx][ny] + diff;
						visit[nx][ny] = false;
						broken = false;
						if (depth > size)
							size = depth;
					}
				}
				
			}
		}

	}
	
	return size;


}
int main(void) {
	int t; 
	cin >> t;
	int cnt = 1;
	while (t--) {
		int max=-1;
		memset(visit, false, sizeof(visit));
		cin >> n >> k;
		

		int height=-1;
		vector<pair<int, int>> loc;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> MAP[i][j];

				if (height < MAP[i][j]) {
					height = MAP[i][j];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (height == MAP[i][j])
					loc.push_back(make_pair(i, j));
			}
		}

		
		for (int r = 0; r < loc.size(); r++) {
			int i, j;
			tie(i, j) = loc[r];
			visit[i][j] = true;
			broken = false;

			int depth = go(i, j, 1);
			visit[i][j] = false;
			if (max < depth)
				max = depth;
		}

		
	
		printf("#%d %d\n", cnt, max);
		cnt++;
	}
}