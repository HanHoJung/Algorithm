#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
bool ground[50][50];
bool visit[50][50];



//1단계 input
void input(int m, int n, int k) {
	memset(ground, false, sizeof(ground));
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		ground[x][y] = true;
	}
}

//2단계 n번째 지렁이 이동 좌표 영역 찾기(bfs,플러드필)
void bfs(int x, int y,int m,int n) {
	visit[x][y] = true;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int sx, sy;
		tie(sx, sy) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = sx + dx[i];
			ny = sy + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (visit[nx][ny] || ground[nx][ny]==0)
				continue;

			q.push(make_pair(nx, ny));
			visit[nx][ny] = true;
		}	
	}
}
int main(void) {

	int t;
	cin >> t;

	while (t--) {
		int m, n, k;
		int cnt = 0;//지렁이 개수
		cin >> m >> n >> k;
		input(m, n, k);
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

				if (visit[i][j] == false && ground[i][j] == 1) {
					cnt++;
					bfs(i, j,m,n);

				}
			}
		}

		cout << cnt << "\n";//지렁이 갯수 출력
	}
}