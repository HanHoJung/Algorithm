#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
bool check[101][101];

void curve(int x, int y, int d, int g) {
	vector<int> dir;//방향저장
	dir.push_back(d);
	
	for (int k = 1; k <=g; k++) {
		vector<int> temp(dir);
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++) {
			temp[i] = (temp[i] + 1) % 4;

		}
		dir.insert(dir.end(), temp.begin(), temp.end());
		
	}
	

	int nx = x;
	int ny = y;


	for (int i = 0; i < dir.size(); i++) {
		nx = nx + dx[dir[i]];
		ny = ny + dy[dir[i]];
		check[nx][ny] = true;
	}

	return;
}

int main(void) {
	int n;
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		check[x][y] = true;
		curve(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i <=99; i++) {
		for (int j = 0; j <=99; j++) {
			if (check[i][j] && check[i][j + 1] && check[i + 1][j] && check[i + 1][j + 1]) {
				ans += 1;
			}
		}
	}
	cout << ans << "\n";



}