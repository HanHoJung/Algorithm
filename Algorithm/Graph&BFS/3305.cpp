#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <map>

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
	deque<tuple<int, int, bool>> q;
	q.push_back(make_tuple(startX, startY, false));
	check[startX][startY] = true;
	int t = -1;

	while (!q.empty()) {
		int x, y, w;
		tie(x, y, w) = q.front();
		q.pop_front.pop_back();


		
		if (x == destX && y == destY)
			break;
		
		for (int k = 0; k < 4; k++) {

			int newWaterX = x + dx[k];
			int newWaterY = y + dy[k];


			if (newWaterX < 0 || newWaterX >= n || newWaterY < 0 || newWaterY >= m)
				continue;

			if (check[newWaterX][newWaterY] == false && MAP[newWaterX][newWaterY] != 'X' && MAP[newWaterX][newWaterY] != 'D') {
				check[newWaterX][newWaterY] = true;
				MAP[newWaterX][newWaterY] = '*';
				q.push_back.push_front(make_tuple(newWaterX, newWaterY, true));
			}
		}



		for (int k = 0; k < 4; k++) {

			int newX = x + dx[k];
			int newY = y + dy[k];

			if (newX < 0 || newX >= n || newY < 0 || newY >= m)
				continue;

			if (check[newX][newY] == false && MAP[newX][newY] != 'X' && MAP[newX][newY] != '*') {
				check[newX][newY] = true;
				dist[newX][newY] = dist[x][y] + 1;
				q.push_back(make_tuple(newX, newY,false));

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