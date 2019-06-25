#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int MAP[9][9];
vector<pair<int, int>> virus;
bool check[9][9];
int maxVal = -1;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


int fludfill(int MAP[][9]) {

	int copy[9][9];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j] = MAP[i][j];

		}
	}


	queue<pair<int, int>> q;
	bool visit[9][9];
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;

		q.push(make_pair(x, y));
		visit[x][y] = true;
		copy[x][y] = 2;

	}


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (copy[nx][ny] == 0 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				copy[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}

	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copy[i][j] == 0)
				count++;
		}
	}

	return count;
}


void wall(int cnt) {

	if (cnt == 3) {
		int value = fludfill(MAP);

		if (maxVal < value)
			maxVal = value;


		return;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == false && MAP[i][j] == 0) {
				check[i][j] = true;
				MAP[i][j] = 1;
				wall(cnt + 1);
				check[i][j] = false;
				MAP[i][j] = 0;
			}
		}


	}

}


int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	wall(0);
	cout << maxVal << "\n";
}
