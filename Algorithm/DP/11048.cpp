#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int dx[] = { 1,0,1 };
int dy[]= { 0,1,1 };
int dist[1001][1001];
int main(void) {

	int n, m;
	cin >> n >> m;
	vector<vector<int>> MAP(n, vector<int>(m,0));
	
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			MAP[i][j] = input;
		}
	}
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(0,0));
	dist[0][0] = MAP[0][0];


	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + MAP[nx][ny];
				q.push(make_pair(nx, ny));

			}
			else {
				if (dist[nx][ny] < dist[x][y] + MAP[nx][ny]) {
					dist[nx][ny] = dist[x][y] + MAP[nx][ny];
				}
			}
		}
	}

	cout << dist[n - 1][m - 1] << "\n";

}

