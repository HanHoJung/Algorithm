#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<vector<int>> bfs(vector<string> &a, int x, int y) {
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> d(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = -1;
		}
	}
	deque<pair<int, int>> q;
	q.push_back(make_pair(x, y));
	d[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front(); q.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (d[nx][ny] != -1) continue;
			if (a[nx][ny] == '*') continue;
			if (a[nx][ny] == '#') {
				d[nx][ny] = d[x][y] + 1;
				q.push_back(make_pair(nx, ny));
			}
			else {
				d[nx][ny] = d[x][y];
				q.push_front(make_pair(nx, ny));
			}
		}
	}
	return d;
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


		

		int ans = w * h;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++) {

				if (prision[i][j] == '*')
					continue;

			  vector<vector<int>> arr1 = bfs(prision, i, j);


				int sum = arr1[0][0]+arr2[i][j] + arr3[i][j];


				if (prision[i][j] == '#') 
					sum = sum - 1;
				
				if (i == 1 && j == 1) {
					cout<<sum<<"\n";
				}
		

				if (ans > sum)
					ans = sum;
					
			}

		}
	

		cout << ans << "\n";


	}
}