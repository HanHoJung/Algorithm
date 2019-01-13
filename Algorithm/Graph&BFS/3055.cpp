#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;
char MAP[50][50];
bool check[50][50];
bool water[50][50];
int dist[50][50];
vector<pair<int, int>> waterLocation;

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

pair<int, int> start() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 'S')
				return make_pair(i, j);
		}
	}
}

pair<int, int> dest() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 'D')
				return make_pair(i, j);
		}
	}
}



int main(void) {
	int startX, startY;
	int destX, destY;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			MAP[i][j] = c;
			if (c == '*') {
				waterLocation.push_back(make_pair(i, j));
				water[i][j] = true;
			}
		}
	}

	tie(startX, startY) = start();
	tie(destX, destY) = dest();
	queue<pair<int, int>> q;
	q.push(make_pair(startX, startY));
	check[startX][startY] = true;
	int t = -1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (x == destX && y == destY)
			break;

		if (t != dist[x][y]) {
			int size = waterLocation.size();

			for (int i = 0; i < size; i++) {
				int waterX = waterLocation[i].first;
				int waterY = waterLocation[i].second;

				for (int k = 0; k < 4; k++) {

					int newWaterX = waterX + dx[k];
					int newWaterY = waterY + dy[k];

					if (newWaterX < 0 || newWaterX >= n || newWaterY < 0 || newWaterY >= m)
						continue;

					if (water[newWaterX][newWaterY] == false && MAP[newWaterX][newWaterY] != 'X' && MAP[newWaterX][newWaterY] != 'D') {
						water[newWaterX][newWaterY] = true;
						MAP[newWaterX][newWaterY] = '*';
						waterLocation.push_back(make_pair(newWaterX, newWaterY));
					}
				}

			}
			t = dist[x][y];
		}



		for (int k = 0; k < 4; k++) {

			int newX = x + dx[k];
			int newY = y + dy[k];

			if (newX < 0 || newX >= n || newY < 0 || newY >= m)
				continue;

			if (check[newX][newY] == false && MAP[newX][newY] != 'X' && MAP[newX][newY] != '*') {
				check[newX][newY] = true;
				dist[newX][newY] = dist[x][y] + 1;
				MAP[newX][newY] = 'A';
				q.push(make_pair(newX, newY));


			}
		}
	}

	if (check[destX][destY] == false) {
		cout << "KAKTUS";
	}
	else {
		cout << dist[destX][destY];
	}

}