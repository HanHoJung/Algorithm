#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

bool visit[1001][1001][11];
int dist[1001][1001][11];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int MAP[1001][1001];
int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> MAP(n,vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &MAP[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	visit[0][0][0] = true;

	while (!q.empty()) {
		int x, y, c;
		tie(x, y, c) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (visit[nx][ny][c])
				continue;
			
			if (MAP[nx][ny] == 0) {
				visit[nx][ny][c] = true;
				dist[nx][ny][c] = dist[x][y][c] + 1;
				q.emplace(nx, ny, c);
			}
			else if (MAP[nx][ny] == 1 && c+1<=k) {

				visit[nx][ny][c+1] = true;
				dist[nx][ny][c+1] = dist[x][y][c] + 1;
				q.emplace(nx, ny, c+1);
			}
		}

	}

	int min = 1000 * 1000 * 1000;
	bool check = false;
	for (int i = 0; i <=k; i++) {
		if (visit[n - 1][m - 1][i]) {
			if (min > dist[n - 1][m - 1][i]) {
				min = dist[n - 1][m - 1][i];
			}
			check = true;
		}
		
	}

	if (check)
		cout << min + 1 << "\n";
	else
		cout << -1 << "\n";
}