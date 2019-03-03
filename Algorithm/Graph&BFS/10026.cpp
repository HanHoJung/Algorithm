#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int n;
bool check[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

void fludFill(int i, int j, vector<vector<char>> MAP) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	char color = MAP[i][j];
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (check[nx][ny])
				continue;
			if (MAP[nx][ny] == color) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
void fludFill2(int i, int j, vector<vector<char>> MAP) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	char color = MAP[i][j];
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (check[nx][ny])
				continue;
			if (color == 'R' || color == 'G') {
				if (MAP[nx][ny] != 'B') {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
			else {
				if (MAP[nx][ny] == color) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}

			}
		}
	}
}

int main(void) {
	cin >> n;
	vector<vector<char>> MAP(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}
	int person = 0;
	int blind = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				fludFill(i, j, MAP);
				person++;
			}
		}
	}
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				fludFill2(i, j, MAP);
				blind++;
			}
		}
	}
	cout << person << " " << blind << "\n";

}