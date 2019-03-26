#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, M;
int ans;
int visit[11][11];
bool check(vector <vector <int> > &map, int x, int y) {
	int xc = 0, yc = 0;

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (map[nx][ny] == 0) xc++;
	}

	for (int i = 2; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (map[nx][ny] == 0) yc++;
	}

	if (xc >= 1 && yc >= 1) return false;

	return true;
}

void bfs(vector <vector <int> > &map, queue<tuple<int, int, int> > &q) {

	while (!q.empty()) {
		int x, y, time;
		tie(x, y, time) = q.front();

		if (x == N - 1 && y == N - 1) {
			if (ans > time) ans = time;
			return;
		}
		q.pop();
		bool wait = false;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];


			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (map[nx][ny] == 0) continue;
			if (visit[nx][ny]) continue;


			if (map[nx][ny] == 1) {
				visit[nx][ny] = 1;
				q.push(make_tuple(nx, ny, time + 1));
			}

			if (map[nx][ny] > 1) {
				int remain = time % map[nx][ny];
				if (remain != map[nx][ny] - 1) {
					wait = true;
				}
				else {//그 다음 시간이 건널 수 있는 시간
					int nnx = nx + dx[i];
					int nny = ny + dy[i];

					if (nnx < 0 || nnx >= N || nny < 0 || nny >= N) continue;
					if (map[nnx][nny] != 1) continue;

					visit[nx][ny] = 1;
					q.push(make_tuple(nx, ny, time + 1));
				}
			}
		}
		if (wait) { q.push(make_tuple(x, y, time + 1)); }
	}
}
int main() {

	cin >> N >> M;

	vector <vector <int> > map(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	ans = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && check(map, i, j)) {
				memset(visit, 0, sizeof(visit));
				queue<tuple<int, int, int> > q;
				q.push(make_tuple(0, 0, 0));
				visit[0][0] = 1;
				map[i][j] = M;
				bfs(map, q);
				map[i][j] = 0;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}