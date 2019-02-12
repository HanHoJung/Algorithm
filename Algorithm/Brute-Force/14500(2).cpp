#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool visit[500][500];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int maxVal;
void go(vector<vector<int>> &MAP,int x, int y,int cnt, int sum) {

	if (cnt == 4) {
		maxVal = max(maxVal, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if(visit[nx][ny]==false){
			visit[nx][ny] = true;
			go(MAP, nx, ny, cnt + 1, sum + MAP[nx][ny]);
			visit[nx][ny] = false;
		}

	}


}


void etc(vector<vector<int>> &MAP) {


	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			if (i - 1 >= 0 && j + 2 < m) {
				sum = MAP[i][j] + MAP[i][j + 1] + MAP[i][j + 2] + MAP[i - 1][j + 1];
			}

			maxVal = max(sum, maxVal);

			if (i + 2 < n && j + 1 < m) {
				sum = MAP[i][j] + MAP[i + 1][j] + MAP[i + 2][j] + MAP[i + 1][j + 1];
			}
			
			maxVal = max(sum, maxVal);


			if (i + 2 < n && j - 1 >= 0) {
				sum = MAP[i][j] + MAP[i + 1][j] + MAP[i + 2][j] + MAP[i + 1][j - 1];
			}
			maxVal = max(sum, maxVal);

			if (i + 1 < n && j + 2 < m) {
				sum = MAP[i][j] + MAP[i][j + 1] + MAP[i][j + 2] + MAP[i + 1][j + 1];

			}
			maxVal = max(sum, maxVal);
		}

	}


}


int main(void) {

	cin >> n >> m;
	vector<vector<int>> MAP(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			go(MAP, i, j, 1, MAP[i][j]);
			visit[i][j] = false;
		}
	}

	etc(MAP);

	cout << maxVal << "\n";

}