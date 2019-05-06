#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int edge[1001][1001];
int dist[1001][1001];
bool check[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int m, n;


int main(void) {
	cin >> m >> n;
	queue<pair<int, int>> q;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &edge[i][j]);

			if (edge[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = true;
				dist[i][j] = 0;
			}
		}
	}

	


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m)
				continue;

			if (edge[new_x][new_y] == 0 && check[new_x][new_y] == false) {
				check[new_x][new_y] = true;
				dist[new_x][new_y] = dist[x][y] + 1;
				q.push(make_pair(new_x, new_y));
			}
		}


	}


	int dayMax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (edge[i][j] == -1)
				continue;

			int value = dist[i][j];
			dayMax = max(dayMax, value);
			if (value == -1) {
				//토마토가 모두 익지 않은 상황
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	if (dayMax == 0) {
		//저장될 때부터 모든 토마토가 익어있는 상태
		cout << dayMax  << "\n";
		return 0;
	}
	else {
		//완숙 토마토^^
		cout << dayMax << "\n";
		return 0;
	}


}
