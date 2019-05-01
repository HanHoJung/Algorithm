#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<vector<int>> cube[5];
vector<vector<int>> cp[5];
int d = -1;
void init() {
	for (int k = 0; k < 5; k++) {
		vector<vector<int>> arr(5, vector<int>(5, 0));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> arr[i][j];
			}
		}
		cube[k] = arr;
	}


}
void output() {
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << cube[k][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
}
void rotation(vector<vector<int>> &arr) {

	vector<vector<int>> copy = arr;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[j][4 - i] = copy[i][j];
		}
	}


}



void bfs(vector<int> permu) {
	if (cube[permu[0]][0][0] == 0 || cube[permu[permu.size() - 1]][4][4] == 0) return;
	int dx[] = { 1, -1, 0, 0, 0, 0 };
	int dy[] = { 0, 0, 1, -1, 0, 0 };
	int dh[] = { 0, 0, 0, 0, 1, -1 };
	vector<pair<int, int>> loc = { make_pair(0,0) };
	vector<pair<int, int>> loc2 = { make_pair(4,4) };


	int sx, sy;
	int ex, ey;
	tie(sx, sy) = loc[0];
	tie(ex, ey) = loc2[0];

	int dist[5][5][5];

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> q;
	q.emplace(0, sx, sy);
	dist[0][sx][sy] = 0;


	while (!q.empty()) {
		int t, x, y;
		tie(t, x, y) = q.front();
		q.pop();

		bool out = false;

		for (int i = 0; i < 6; i++) {
			int nt = t + dh[i];
			int nx = x + dx[i];
			int ny = y + dy[i];



			if (nt < 0 || nt >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
				continue;

			if ((t == 4) && (nx == 4) && (ny == 4)) {

				if (d == -1 || d > (dist[t][x][y] + 1))
					d = dist[t][x][y] + 1;

				out = true;
				break;
			}
			if (dist[nt][nx][ny] != -1)
				continue;

			if (cube[permu[nt]][nx][ny] != 1)
				continue;

			dist[nt][nx][ny] = dist[t][x][y] + 1;
			q.emplace(nt, nx, ny);

		}

		if (out)
			break;


	}


}

void go(int cnt) {
	if (cnt == 5) {

		vector<int> permutation = { 0,1,2,3,4 };
		do {
			bfs(permutation);

		} while (next_permutation(permutation.begin(), permutation.end()));


		return;
	}

	for (int i = 0; i < 4; i++) {
		rotation(cube[cnt]);
		go(cnt + 1);

	}

}


int main(void) {
	init();
	go(0);
	cout << d << "\n";


}