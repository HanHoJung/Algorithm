#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<vector<int>> bfs(vector<string> &prision, int x, int y) {

	int n = prision.size();//세로 길이
	int m = prision[0].size();//가로 길이

	vector<vector<int>> dist(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = -1;//방문하지 않는 상태
		}
	}

	deque<pair<int, int>> q;
	q.push_back(make_pair(x, y));
	dist[x][y] = 0;


	while (!q.empty()) {
		tie(x, y) = q.front(); q.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;
			if (prision[nx][ny] == '*') continue;
			if (prision[nx][ny] == '#') {
				dist[nx][ny] = dist[x][y] + 1;
				q.push_back(make_pair(nx, ny));
			}
			else {
				dist[nx][ny] = dist[x][y];
				q.push_front(make_pair(nx, ny));
			}
		}




	}

	return dist;
}


int main(void) {
	int t;
	cin >> t;

	while (t--) {

		int h, w;
		cin >> h >> w;

		vector<string> prision(h + 2);
		h = h + 2;
		w = w + 2;
		for (int i = 1; i < h - 1; i++) {
			cin >> prision[i];
			prision[i] = "." + prision[i] + ".";
		}


		for (int i = 0; i < w; i++) {
			prision[0] = prision[0] + '.';
			prision[h - 1] = prision[h - 1] + '.';
		}

		int destination_x = 0;
		int destination_y = 0;

		vector<vector<int>> arr1 = bfs(prision, destination_x, destination_y);

		
		int prisoner1_x, prisoner1_y;
		int prisoner2_x, prisoner2_y;
		bool next = false;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (prision[i][j] == '$'&& next == false) {
					prisoner1_x = i;
					prisoner1_y = j;
					next = true;
					continue;
				}
				if (prision[i][j] == '$' && next == true) {
					prisoner2_x = i;
					prisoner2_y = j;
				}
			}
		}



		vector<vector<int>> arr2 = bfs(prision, prisoner1_x, prisoner1_y);

		vector<vector<int>> arr3 = bfs(prision, prisoner2_x, prisoner2_y);


		int ans = w*h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {

				if (prision[i][j] == '*')
					continue;

				int sum = arr1[i][j] + arr2[i][j] + arr3[i][j];
				if (prision[i][j] == '#')
					sum = sum - 2;

				if (ans > sum)
					ans = sum;
			}
		}


		cout << ans << "\n";


	}
}